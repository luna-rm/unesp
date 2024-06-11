package A2.Area;

public class Quadrado implements AreaCalculavel{
    double lado;

    Quadrado(double lado){
        this.lado = lado;
    }

    @Override
    public double calcularArea() {
        return lado*lado;
    }
    
}
