package A2.Area;

public class Circulo implements AreaCalculavel {
    double raio;

    Circulo(double raio){
        this.raio = raio;
    }

    @Override
    public double calcularArea() {
        return 3.14*this.raio*this.raio;
    }
    
}
