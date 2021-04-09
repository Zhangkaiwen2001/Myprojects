public class Demo01 {
    public static class Point{
        private Object x ;		// 表示X坐标
        private Object y ;		// 表示Y坐标
        public void setX(Object x){
            this.x = x ;
        }
        public void setY(Object y){
            this.y = y ;
        }
        public Object getX(){
            return this.x ;
        }
        public Object getY(){
            return this.y ;
        }
    }
    public static void main(String args[]) {
        Point p = new Point();
        p.setX(10);
        p.setY(20);
        int x = (Integer) p.getX();
        int y = (Integer) p.getY();
        System.out.println("整数表示，X坐标为：" + x);
        System.out.println("整数表示，Y坐标为：" + y);
        p.setX(10.5f) ;
        p.setY(20.6f) ;
        float m = (float)p.getX() ;
        float n = (float)p.getY() ;
        System.out.println("小数表示，X坐标为：" + m) ;
        System.out.println("小数表示，Y坐标为：" + n) ;
        p.setX("东经180度") ;
        p.setY("北纬210度") ;
        String a = (String)p.getX() ;
        String b = (String)p.getY() ;
        System.out.println("字符串表示，X坐标为：" + a) ;
        System.out.println("字符串表示，Y坐标为：" + b) ;


    }
}
