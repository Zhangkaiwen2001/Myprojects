public class Demo02 {
    public static class Point<T>{
        private T var ;
        public T getVar(){
            return var ;
        }
        public void setVar(T var){
            this.var = var ;
        }
    }
    public static void main(String args[]){
        Point<Integer> p = new Point<Integer>() ;
        p.setVar(30) ;
        System.out.println(p.getVar()) ;
        Point<String> q = new Point<String>() ;
        q.setVar("我是大帅哥");
        System.out.println(q.getVar().length());
    }
}
