package A2.Area;

public class Retangulo implements AreaCalculavel {
    double lado, altura;

    Retangulo(double lado, double altura){
        this.lado = lado;
        this.altura = altura;
    }

    @Override
    public double calcularArea(){
        return lado*altura;
    }
}
