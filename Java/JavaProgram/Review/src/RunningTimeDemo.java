public class RunningTimeDemo {
    public static void main(String[] args) throws Exception{
        Runtime run = Runtime.getRuntime();
        System.out.println("1.MAX_MEMORY:"+run.maxMemory());
        System.out.println("1.TOTAL_MEMORY:"+run.totalMemory());
        System.out.println("1.FREE_MEMORY:"+run.freeMemory());
        String str = "";
        for (int x = 0; x < 30000 ; x ++){
            str += x ;
        }
        System.out.println("2.MAX_MEMORY:"+run.maxMemory());
        System.out.println("2.TOTAL_MEMORY:"+run.totalMemory());
        System.out.println("2.FREE_MEMORY:"+run.freeMemory());
        run.gc();
        System.out.println("3.MAX_MEMORY:"+run.maxMemory());
        System.out.println("3.TOTAL_MEMORY:"+run.totalMemory());
        System.out.println("3.FREE_MEMORY:"+run.freeMemory());

    }
}
