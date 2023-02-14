package Circle;
import java. lang. Math.*;

public class Circle {
    private double radius;
    private double diameter;

    public Circle(){
        
    }

    public Circle(double radius) {
        this.radius = radius;
        this.diameter = 2 * radius;
    }
  
    public double getArea() {
        return Math.PI * Math.pow(radius, 2);
    }
  
    public double getParameter() {
        return diameter * Math.PI;
    }
}
