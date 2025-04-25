package oop.day05.getset;

public class Studentt {
    private int no;
    private String name;
    private int schoolNo;

    public Studentt() {
        super();
    }

    public Studentt(String name, int no, int schoolNo) {
        super();
        this.name = name;
        this.no = no;
        this.schoolNo = schoolNo;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getNo() {
        return no;
    }

    public void setNo(int no) {
        this.no = no;
    }

    public void setSchoolNo(int schoolNo) {
        this.schoolNo = schoolNo;
    }
}
