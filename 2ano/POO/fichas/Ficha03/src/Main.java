package Ficha03.src;
public class Main {
    public static void main(String[] args) {
        Circle c = new Circle(2, 2, 2);

        System.out.println(c.toString());

        c.changeCenter(3,3);
        System.out.println(c.toString());

        double area = c.calculateArea();
        double perimeter = c.calculatePerimeter();

        System.out.println("Area: " + area + "; Perimeter: " + perimeter);
    }    
}
