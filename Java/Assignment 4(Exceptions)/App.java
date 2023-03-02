import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        try {
            System.out.println("Enter number : ");
            int userNum = sc.nextInt();
            Number num = new Number(userNum);
            int result = num.factorial(userNum);

            System.out.println("Factorial returns " + result);

        }catch(Exception e){
            System.out.println(e.getMessage());
        }

    }
}
