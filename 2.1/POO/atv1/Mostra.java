abstract class MostraDados {
    abstract void mostra(int l);
    abstract void mostra(double f);
}

public class Mostra extends MostraDados{
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
        Mostra mostra = new Mostra();
        mostraValores(mostra);
    }
}