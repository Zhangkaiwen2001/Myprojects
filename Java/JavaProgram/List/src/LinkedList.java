import java.util.ArrayList;

public class LinkedList {
    public static void main(String[] args) {
        ArrayList<String> link = new ArrayList<String>();
        link.add("A"); // 向链表中增加数据
        link.add("B"); // 向链表中增加数据
        link.add("C"); // 向链表中增加数据
        System.out.println("初始化链表：" + link);
        link.add(0,"X");// 在链表的表头增加内容
        link.add("Y");// 在链表的表尾增加内容
        System.out.println("增加头和尾之后的链表：" + link);
    }
}
