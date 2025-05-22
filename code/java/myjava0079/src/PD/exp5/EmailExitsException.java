package PD.exp5;

public class EmailExitsException extends Exception {
    public EmailExitsException(String message) {
        super(message);
    }

    public EmailExitsException() {

    }

    public EmailExitsException(Throwable cause) {
        super(cause);
    }

    public EmailExitsException(String message, Throwable cause) {
        super(message, cause);
    }
}
