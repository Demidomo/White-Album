// You have to accept a number from the user

// Now you have calculate the factorial of the number

// If the user enters a negative value, than throw a custom Exception called as NegativeException
// 5! --> 5 * 4 * 3 * 2 * 1
// 3! --> 3 * 2 * 1
// 6! --> 6 * 5 * 4 * 3 * 2 * 1


public class Number {
   private int number;

    public Number(int number) {
        this.number = number;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public int factorial(int num) throws NegativeException{
        if (num < 0){
            throw new NegativeException("Negative Number is not allowed! Please enter a whole number.");

        }
        
        int result = 1;
        for (int i = 1; i <= num; i++) {
            result *= i;
        }
        return result;
    }
}
