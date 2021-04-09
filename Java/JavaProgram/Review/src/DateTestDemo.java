import java.util.Date;

public class DateTestDemo {
    public static void main(String[] args){
        Date date = new Date();
        long num = date.getTime();
        System.out.println(date);
        System.out.println(num);
    }
}
