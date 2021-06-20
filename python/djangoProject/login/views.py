from django.shortcuts import render
from django.shortcuts import HttpResponse
from .models import User
# Create your views here.


def index(request):
    # return HttpResponse('Hello, Calvin')
    # return render(request,'index.html')
    if request.method == 'POST':
        username = request.POST.get('username')
        password = request.POST.get('password')
        # print(username, password)
        # temp = {'user': username, 'pwd': password}
        # user_list.append(temp)
        # 数据保存到数据库
        User.objects.create(username=username,password=password)
    # 从数据库读取所有数据，注意缩进
    user_list = User.objects.all()
    print(user_list)
    return render(request, 'index.html', {'data': user_list})
