package Car;
import Vehicle.Vehicle;

// Car object from Vehicle class, with added attributes
public class Car extends Vehicle{
    private boolean hasAC;
    private boolean hasHandBrake;
    private String sound;
    private String engine;

    // Constructor
    public Car(String model, String make, int numberOfWheels, int topSpeed, boolean hasAC, boolean hasHandBrake,
            String sound, String engine) {
        super(model, make, numberOfWheels, topSpeed);
        this.hasAC = hasAC;
        this.hasHandBrake = hasHandBrake;
        this.sound = sound;
        this.engine = engine;
    }

    // Getters and Setters all added attributes 
    public boolean isHasAC() {
        return hasAC;
    }
    public void setHasAC(boolean hasAC) {
        this.hasAC = hasAC;
    }
    public boolean isHasHandBrake() {
        return hasHandBrake;
    }
    public void setHasHandBrake(boolean hasHandBrake) {
        this.hasHandBrake = hasHandBrake;
    }
    public String getSound() {
        return sound;
    }
    public void setSound(String sound) {
        this.sound = sound;
    }
    public String getEngine() {
        return engine;
    }
    public void setEngine(String engine) {
        this.engine = engine;
    }

    // Added methods for the Car object  
    public void accelerate(){
        System.out.println(this.getModel() + " Accelerates...");
    }

    public void Break(){
        System.out.println(this.getModel() + " Breaks...");
    }

    public void Handbreak(){
        System.out.println(this.getModel() + " Hand Break ON...");
    }

    public void getInfo(){
        System.out.println("Model: " + this.getModel());
        System.out.println("Make: " + this.getMake());
        System.out.println("Number of wheels: " + this.getNumberOfWheels());
        System.out.println("Model: " + this.getModel());
        System.out.println("Top speed: " + this.getTopSpeed());
        System.out.println("Has A/C?: " + this.isHasAC());
        System.out.println("Has Hand Brake?: " + this.isHasHandBrake());
        System.out.println("Sound: " + this.getSound());
        System.out.println("Engine: " + this.getEngine());

    }
}
