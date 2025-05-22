package PD.exp5;

public class EmailOrPwdException extends Exception {

    public EmailOrPwdException(String message) {
        super(message);
    }

    public EmailOrPwdException() {

    }

    public EmailOrPwdException(Throwable cause) {
        super(cause);
    }

    public EmailOrPwdException(String message, Throwable cause) {
        super(message, cause);
    }
}
