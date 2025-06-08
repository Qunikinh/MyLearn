package topic.six;

class SingleQuestion2 extends Question {
    protected char answer;
    private final char correctAnswer;

    public SingleQuestion2(String title, String[] options, char correctAnswer) {
        super(title, options);
        this.correctAnswer = correctAnswer;
    }

    @Override
    protected boolean check(char[] answers) {
        if (answers.length != 1) return false;
        this.answer = answers[0];
        return answers[0] == correctAnswer;
    }
}