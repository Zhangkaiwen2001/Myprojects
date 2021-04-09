package TryCatch;

public abstract class Data {
    private int no;
    private String gender;
    private String name;
    private String student_id;
    private String memo;
    private String mobile_phone_number;
    public abstract void Create();
    public abstract void Update();
    public abstract void Delete();
    public abstract void findAll();
    public abstract void findByStudentId();
    public abstract void findByStudentName();

    public String getGender() {
        return gender;
    }
    public void setGender(String gender) {
        this.gender = gender;
    }
    public int getNo() {
        return no;
    }
    public void setNo(int no) {
        this.no = no;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getStudent_id() {
        return student_id;
    }
    public void setStudent_id(String student_id) {
        this.student_id = student_id;
    }
    public String getMemo() {
        return memo;
    }
    public void setMemo(String memo) {
        this.memo = memo;
    }
    public String getMobile_phone_number() {
        return mobile_phone_number;
    }
    public void setMobile_phone_number(String mobile_phone_number) {
        this.mobile_phone_number = mobile_phone_number;
    }
}
