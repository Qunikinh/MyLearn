package oop.day05.getset;

public class School {
    private int schoolNo;
    private String schoolName;

    public School() {
        super();
    }

    public School(int schoolNo, String schoolName) {
        super();
        this.schoolNo = schoolNo;
        this.schoolName = schoolName;
    }

    public int getSchoolNo() {
        return schoolNo;
    }

    public void setSchoolNo(int schoolNo) {
        this.schoolNo = schoolNo;
    }

    public String getSchoolName() {
        return schoolName;
    }

    public void setSchoolName(String schoolName) {
        this.schoolName = schoolName;
    }
}