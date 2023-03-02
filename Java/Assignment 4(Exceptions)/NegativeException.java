public class NegativeException extends Exception {

    private String message;

    public NegativeException(String msg) {
        this.message = msg;
    }

    public String getMessage() {
        return "When a negative number has been inputted" + message;
    }
}
