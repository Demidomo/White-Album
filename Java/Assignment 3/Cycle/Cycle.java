package Cycle;
import Vehicle.Vehicle;

// Child class from Vehicles with no additional attributes
public class Cycle extends Vehicle{

    // Constructor
    public Cycle(String model, String make, int topSpeed) {
        super(model, make, 2, topSpeed);
    }
    
}
