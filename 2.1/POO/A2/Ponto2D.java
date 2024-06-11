package A2;

import java.lang.Math; 

public class Ponto2D {
    private double x, y;
    
    Ponto2D(){
        x = 0;
        y = 0;
    }

    Ponto2D(double x, double y){
        this.x = x;
        this.y = y;
    }

    Ponto2D(Ponto2D p){
        this.x = p.x;
        this.y = p.y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }
    
    public void setY(double y) {
        this.y = y;
    }

    public double calculate(Ponto2D p){
        return Math.sqrt((this.x - p.x)*(this.x - p.x) + (this.y - p.y)*(this.y - p.y));
    }
    
    public void printCoor(){
        System.out.println("x: " + this.x + " | y: " + this.y);
    }
    public static void main(String[] args) {
        Ponto2D p1 = new Ponto2D(2.0, 4.0);
        Ponto2D p2 = new Ponto2D();
        p2.setX(10);
        p2.setY(-2);
        
        System.out.println((p1.calculate(p2)));

        p2.printCoor();

    }
}

