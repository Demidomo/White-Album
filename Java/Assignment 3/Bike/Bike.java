package Bike;
import Vehicle.Vehicle;

// Child class Bike created from Vehicle parent class
public class Bike extends Vehicle{
    private String engine;

    // Constructor
    public Bike(String model, String make, int numberOfWheels, int topSpeed, String engine) {
        super(model, make, numberOfWheels, topSpeed);
        this.engine = engine;
    }

    // Additional attributes for the Bike Class
    public String getEngine() {
        return engine;
    }

    public void setEngine(String engine) {
        this.engine = engine;
    }

    // Additional methods for the Bike class
    public void accelerate(){
        System.out.println("Speeds up...");
    }

    public void Break(){
        System.out.println("Slows down...");
    }

}
