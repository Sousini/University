package Ficha03.src;



import java.lang.Math;

public class Circle {
    private double x;
    private double y;
    private double radius;

    // Default constructor
    public Circle() {
        this.x = 0;
        this.y = 0;
        this.radius = 1;
    }

    // Parameterized constructor
    public Circle(double x, double y, double radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    // Copy constructor
    public Circle(Circle other) {
        this.x = other.x;
        this.y = other.y;
        this.radius = other.radius;
    }

    // Method to change the center of the circle
    public void changeCenter(double x, double y) {
        this.x = x;
        this.y = y;
    }

    // Calculate area
    public double calculateArea() {
        return Math.PI * Math.pow(this.radius, 2);
    }

    // Calculate perimeter
    public double calculatePerimeter() {
        return 2 * Math.PI * this.radius;
    }

    // Getters and Setters
    public double getX() {
        return this.x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return this.y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getRadius() {
        return this.radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    // Equals method to compare two circles
    
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || this.getClass() != o.getClass()) return false;
        
        Circle c = (Circle) o;
        return this.x == c.x && this.y == c.y && this.radius == c.radius;
    }

    // toString method for printing the object

    public String toString() {
        return "Circle{x=" + x + ", y=" + y + ", radius=" + radius + "}";
    }
}
