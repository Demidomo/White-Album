import Car.Car;
import Vehicle.Vehicle;

public class App {

    // Main method 
    public static void main(String[] args) throws Exception {

        // Creating the hatchback and sedan object from the Car child class, which came from the Vehicle parent class
        Car hatchback = new Car("Fit", "Honda", 4, 150, true, true, "quiet", "1.6L");
        Car sedan = new Car("Focus", "Ford", 4, 150, true, false, "quiet", "2.0L");

        // Calling methods from hatchback object 
        hatchback.getInfo();
        hatchback.accelerate();
        hatchback.Break();
        hatchback.Handbreak();

        // Calling methods from sedan object
        sedan.getInfo();
        sedan.accelerate();
        sedan.Break();
        sedan.Handbreak();

    }
}
