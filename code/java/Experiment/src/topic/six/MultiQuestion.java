package topic.six;

class MultiQuestion extends Question {
    protected char[] answers;
    private final char[] correctAnswers;

    public MultiQuestion(String title, String[] options, char[] correctAnswers) {
        super(title, options);
        this.correctAnswers = correctAnswers;
    }

    @Override
    protected boolean check(char[] answers) {
        if (answers.length == 0) return false;
        this.answers = answers;

        for (char ans : answers) {
            boolean found = false;
            for (char correct : correctAnswers) {
                if (ans == correct) {
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
}