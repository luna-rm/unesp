interface MostraDados {
    void mostra(int l);
    void mostra(double f);
}

public class Mostra_Abs implements MostraDados{
    public void mostra(int l){
        System.out.println("Numero Inteiro: " + l);
    }

    public void mostra(double f){
        System.out.println("Numero: " + f);
    }

}

class ProgPrincipal {
    static int valor = 123;
    static double x = 4.56;

    static void mostraValores(MostraDados db) {
        db.mostra(x);
        db.mostra(valor);
    }
    public static void main(String []s) {
        Mostra_Abs mostra = new Mostra_Abs();
        mostraValores(mostra);
    }
}