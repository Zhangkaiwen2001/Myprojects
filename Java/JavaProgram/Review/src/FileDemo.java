import java.io.File;
import java.io.FileWriter;
import java.io.Writer;

public class FileDemo {
    public static void main(String[] args) throws Exception {
        File file = new File("d:" + File.separator + "temp.txt");
        Writer out = new FileWriter(file);
        out.write("Hello World"); // 直接输出字符串
        out.close();
    }
}
