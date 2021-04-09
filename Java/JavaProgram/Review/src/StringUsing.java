public class StringUsing {
    public static void main(String[] args) throws Exception{
        StringBuffer buf = new StringBuffer();
        buf.append("Hello").append(" World.");
        fun(buf);
        System.out.print(buf);
    }
    public static void fun(StringBuffer temp){
        temp.append("\n").append("Hellp MLDN");
    }
}
