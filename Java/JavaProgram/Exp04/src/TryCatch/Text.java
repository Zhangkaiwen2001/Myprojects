package TryCatch;

import java.io.*;
import java.util.Scanner;

public class Text extends Data {
    public Text(int n,String nam,String gen,String stu,String mob,String mem){
        setNo(n);
        setName(nam);
        setGender(gen);
        setStudent_id(stu);
        setMobile_phone_number(mob);
        setMemo(mem);
    }
    public Text(){}

    public void Create() {
        try {
            int n;
            String gen;
            String nam;
            String stu;
            String mem;
            String mob;
            Scanner sc = new Scanner(System.in);
            n = sc.nextInt();
            nam = sc.next();
            gen = sc.next();
            stu = sc.next();
            mob = sc.next();
            mem = sc.next();
            BufferedReader br = new BufferedReader(new FileReader("D:\\MyProjects\\Java\\JavaProgram\\Exp04\\Data.txt"));
            String line;
            if ((line = br.readLine()) == null) {
                setNo(n);
                setName(nam);
                setGender(gen);
                setStudent_id(stu);
                setMobile_phone_number(mob);
                setMemo(mem);
            } else {
                while ((line = br.readLine()) != null) {
                    if (!(line.contains(stu)) && !(line.contains(mob))&&line.indexOf(n)==-1) {
                        setNo(n);
                        setName(nam);
                        setGender(gen);
                        setStudent_id(stu);
                        setMobile_phone_number(mob);
                        setMemo(mem);
                    }
                    else{
                        System.out.println("唯一性测试不通过");
                        return;
                }
            }
            }
            try {
                FileWriter fw = new FileWriter("D:\\MyProjects\\Java\\JavaProgram\\Exp04\\Data.txt", true);
                BufferedWriter bw = new BufferedWriter(fw);
                bw.append(getNo() + "\t" + getName() + "\t" + getGender() + "\t" + getStudent_id() + "\t" + getMobile_phone_number() + "\t" + getMemo() + "\r\n");
                bw.flush();
                bw.close();
                fw.close();
            } catch (Exception e) {
                System.out.println(e);
            }
        }catch (Exception e){
            System.out.println(e);
        }
    }

    public void Update() {
        Delete();
        Create();
        findAll();
    }

    public void Delete(){
        System.out.println("请输入要删除对象学号");
        Scanner sc = new Scanner(System.in);
        String id = sc.next();
        File inFile = new File("D:\\MyProjects\\Java\\JavaProgram\\Exp04\\Data.txt");
        File outFile = new File("D:\\MyProjects\\Java\\JavaProgram\\Exp04\\Data_new.txt");

        BufferedReader br = null;
        String readedLine;
        BufferedWriter bw = null;
        try {
            FileWriter fw = new FileWriter(outFile);
            bw = new BufferedWriter(fw);
            if (!outFile.exists()) {
                outFile.createNewFile();
            }
            br = new BufferedReader(new FileReader(inFile));
            int idx = 0;
            while ((readedLine = br.readLine()) != null) {
                if (readedLine.contains(id)) {
                    continue;
                }
                bw.write(readedLine + "\n");
                if (idx++ == 100) {
                    bw.flush();
                    idx = 0;
                }
            }
            bw.flush();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (br != null) {
                    br.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                if (bw != null) {
                    bw.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        inFile.delete();
        outFile.renameTo(inFile);
    }

    public void findAll() {
        try {
            System.out.print("序号" + "\t" + "姓名" + "\t" + "性别" + "\t" + "学号" + "\t" + "手机号" + "\t" + "备注" + "\n");
            BufferedReader br = new BufferedReader(new FileReader("D:\\MyProjects\\Java\\JavaProgram\\Exp04\\Data.txt"));
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
            br.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public void findByStudentName() {
        String n;
        int flag = 0;
        System.out.println("请输入要查询学生姓名：");
        Scanner sc = new Scanner(System.in);
        n = sc.next();
        try {
            BufferedReader br = new BufferedReader(new FileReader("D:\\MyProjects\\Java\\JavaProgram\\Exp04\\Data.txt"));
        String line;
        while ((line = br.readLine()) != null)
            if (line.contains(n)) {
                System.out.println(line);
                flag = 1;
            }
        if (flag == 0) {
            System.out.println("未发现此名称学生");
        }
        br.close();
        }catch (Exception e){
            System.out.println(e);
        }
    }

    public void findByStudentId(){
        Scanner sc = new Scanner(System.in);
        String id;
        int flag = 0;
        System.out.println("请输入要查询学生id：");
        id = sc.next();
        try {
            BufferedReader br = new BufferedReader(new FileReader("D:\\MyProjects\\Java\\JavaProgram\\Exp04\\Data.txt"));
            String line;
            while ((line = br.readLine()) != null) {
                if(line.contains(id)) {
                    System.out.println(line);
                    flag = 1;
                }
            }
            if(flag==0)
            {
                System.out.println("未发现此名称学生");
            }
            br.close();
        }catch (Exception e){
            System.out.println(e);
        }
    }
}
