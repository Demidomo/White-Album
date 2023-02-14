package Cylinder;
import java. lang. Math.*;

public class Cylinder {
    private double height;
    private double radius;

    public Cylinder(){
        
    }
  
    public Cylinder(double height, double radius) {
        this.height = height;
        this.radius = radius;
    }
  
    public double getVolume() {
        return Math.PI * Math.pow(radius, 2) * height;
    }
}
