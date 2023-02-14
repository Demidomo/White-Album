package Vehicle;

public class Vehicle {
    private String model;
    private String make;
    private int numberOfWheels;
    private int topSpeed;

    public Vehicle(String model, String make, int numberOfWheels, int topSpeed) {
        this.model = model;
        this.make = make;
        this.numberOfWheels = numberOfWheels;
        this.topSpeed = topSpeed;
    }
    // Getter: model
    public String getModel() {
        return model;
    }
    // Setter: model
    public void setModel(String model) {
        this.model = model;
    }
    // Getter: make
    public String getMake() {
        return make;
    }
    // Setter: make
    public void setMake(String make) {
        this.make = make;
    }
    // Getter: numberOfWheels
    public int getNumberOfWheels() {
        return numberOfWheels;
    }
    // Setter: numberOfWheels 
    public void setNumberOfWheels(int numberOfWheels) {
        this.numberOfWheels = numberOfWheels;
    }
    // Getter: topSpeed
    public int getTopSpeed() {
        return topSpeed;
    }
    // Setter: topSpeed
    public void setTopSpeed(int topSpeed) {
        this.topSpeed = topSpeed;
    }
    
}
