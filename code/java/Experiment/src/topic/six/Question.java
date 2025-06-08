package topic.six;

abstract class Question {
    protected String title;
    protected String[] options;

    public Question(String title, String[] options) {
        this.title = title;
        this.options = options;
    }

    protected void print() {
        System.out.println("题干：" + title);
        System.out.println("选项：");
        for (int i = 0; i < options.length; i++) {
            System.out.println((char) ('A' + i) + ". " + options[i]);
        }
    }

    protected abstract boolean check(char[] answers);
}