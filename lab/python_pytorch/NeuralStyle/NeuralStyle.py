# 本书链接https://tangshusen.me/Dive-into-DL-PyTorch/#/
# 9.11 样式迁移
# 注释：黄文俊
# E-mail：hurri_cane@qq.com

from matplotlib import pyplot as plt
import time
import torch
import torch.nn.functional as F
import torchvision
import numpy as np
from PIL import Image

import sys
sys.path.append("..")
import d2lzh_pytorch as d2l
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

import os
os.environ['KMP_DUPLICATE_LIB_OK']='True'
os.environ["CUDA_VISIBLE_DEVICES"]='0'

d2l.set_figsize()
content_img = Image.open('./img/rainier.jpg')
d2l.plt.imshow(content_img)
plt.show()


d2l.set_figsize()
style_img = Image.open('./img/autumn_oak.jpg')
d2l.plt.imshow(style_img)
plt.show()

rgb_mean = np.array([0.485, 0.456, 0.406])
rgb_std = np.array([0.229, 0.224, 0.225])

def preprocess(PIL_img, image_shape):
    process = torchvision.transforms.Compose([
        torchvision.transforms.Resize(image_shape),
        torchvision.transforms.ToTensor(),
        torchvision.transforms.Normalize(mean=rgb_mean, std=rgb_std)])

    return process(PIL_img).unsqueeze(dim = 0) # (batch_size, 3, H, W)

def postprocess(img_tensor):
    inv_normalize = torchvision.transforms.Normalize(
        mean= -rgb_mean / rgb_std,
        std= 1/rgb_std)
    to_PIL_image = torchvision.transforms.ToPILImage()
    return to_PIL_image(inv_normalize(img_tensor[0].cpu()).clamp(0, 1))

pretrained_net = torchvision.models.vgg19(pretrained=True, progress=True)
print(pretrained_net)


style_layers, content_layers = [0, 5, 10, 19, 28], [25]

net_list = []
# a = content_layers + style_layers     # [25, 0, 5, 10, 19, 28]
# b = max(a) + 1
# 将我们需要用到的VGG中的层提取出来构成一个新的网络
for i in range(max(content_layers + style_layers) + 1):
    net_list.append(pretrained_net.features[i])
net = torch.nn.Sequential(*net_list)

# 逐层计算，并保留内容层和样式层的输出。
def extract_features(X, content_layers, style_layers):
    contents = []
    styles = []
    for i in range(len(net)):
        X = net[i](X)
        if i in style_layers:
            styles.append(X)
        if i in content_layers:
            contents.append(X)
    return contents, styles


# 提取内容图像和样式图像对应层的特征
def get_contents(image_shape, device):
    content_X = preprocess(content_img, image_shape).to(device)
    contents_Y, _ = extract_features(content_X, content_layers, style_layers)
    return content_X, contents_Y

def get_styles(image_shape, device):
    style_X = preprocess(style_img, image_shape).to(device)
    _, styles_Y = extract_features(style_X, content_layers, style_layers)
    return style_X, styles_Y

# 内容损失通过平方误差函数衡量合成图像与内容图像在内容特征上的差异
def content_loss(Y_hat, Y):
    return F.mse_loss(Y_hat, Y)

# 样式损失
def gram(X):
    num_channels, n = X.shape[1], X.shape[2] * X.shape[3]
    X = X.view(num_channels, n)
    # return的shape为（通道数，通道数）
    return torch.matmul(X, X.t()) / (num_channels * n)


def style_loss(Y_hat, gram_Y):
    '''
    :param Y_hat: 来自原始图像通过前向计算的特征图，并且是前向计算的特征图中的5张而非1张
    :param gram_Y: 来自风格图像通过前向计算得到的特征图，为其中5张，并且通过格拉姆矩阵计算之后的值
    :return: 返回的是原始图像的5张特征图的格拉姆矩阵和风格图像5张特征图的格拉姆矩阵的平方误差
    '''
    # a = gram(Y_hat)
    return F.mse_loss(gram(Y_hat), gram_Y)

# 总变差损失 :用于降噪
def tv_loss(Y_hat):
    return 0.5 * (F.l1_loss(Y_hat[:, :, 1:, :], Y_hat[:, :, :-1, :]) +
                  F.l1_loss(Y_hat[:, :, :, 1:], Y_hat[:, :, :, :-1]))

# 损失函数
# 样式迁移的损失函数即内容损失、样式损失和总变差损失的加权和
# 通过调节这些权值超参数，我们可以权衡合成图像在保留内容、迁移样式以及降噪三方面的相对重要性。
content_weight, style_weight, tv_weight = 1, 1e4, 20

def compute_loss(X, contents_Y_hat, styles_Y_hat, contents_Y, styles_Y_gram):
    # 分别计算内容损失、样式损失和总变差损失
    contents_l = [content_loss(Y_hat, Y) * content_weight for Y_hat, Y in zip(
        contents_Y_hat, contents_Y)]
    styles_l = [style_loss(Y_hat, Y) * style_weight for Y_hat, Y in zip(
        styles_Y_hat, styles_Y_gram)]
    tv_l = tv_loss(X) * tv_weight
    # 对所有损失求和
    l = sum(styles_l) + sum(contents_l) + tv_l
    return contents_l, styles_l, tv_l, l

# 创建和初始化合成图像
class GeneratedImage(torch.nn.Module):
    def __init__(self, img_shape):
        super(GeneratedImage, self).__init__()
        self.weight = torch.nn.Parameter(torch.rand(*img_shape))

    def forward(self):
        return self.weight

# 创建了合成图像的模型实例，并将其初始化为图像X
def get_inits(X, device, lr, styles_Y):
    gen_img = GeneratedImage(X.shape).to(device)
    gen_img.weight.data = X.data
    optimizer = torch.optim.Adam(gen_img.parameters(), lr=lr)
    styles_Y_gram = [gram(Y) for Y in styles_Y]
    return gen_img(), styles_Y_gram, optimizer

def train(X, contents_Y, styles_Y, device, lr, max_epochs, lr_decay_epoch):
    print("training on ", device)
    X, styles_Y_gram, optimizer = get_inits(X, device, lr, styles_Y)
    scheduler = torch.optim.lr_scheduler.StepLR(optimizer, lr_decay_epoch, gamma=0.1)
    for i in range(max_epochs):
        start = time.time()

        contents_Y_hat, styles_Y_hat = extract_features(
                X, content_layers, style_layers)
        contents_l, styles_l, tv_l, l = compute_loss(
                X, contents_Y_hat, styles_Y_hat, contents_Y, styles_Y_gram)

        optimizer.zero_grad()
        l.backward(retain_graph = True)
        optimizer.step()
        scheduler.step()

        if i % 50 == 0 and i != 0:
            # 显示当前合成图像
            d2l.plt.imshow(postprocess(X.detach()))
            plt.show()
            print('epoch %3d, content loss %.2f, style loss %.2f, '
                  'TV loss %.2f, %.2f sec'
                  % (i, sum(contents_l).item(), sum(styles_l).item(), tv_l.item(),
                     time.time() - start))
    return X.detach()

image_shape =  (150, 225)
net = net.to(device)
content_X, contents_Y = get_contents(image_shape, device)
style_X, styles_Y = get_styles(image_shape, device)
output = train(content_X, contents_Y, styles_Y, device, 0.01, 200, 200)

d2l.plt.imshow(postprocess(output))
d2l.plt.imsave('./img/New-neural-style.png', np.asarray(postprocess(output)))
plt.show()
print("*" * 50)
