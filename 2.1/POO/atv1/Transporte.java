public class Transporte {
    String nome;
    int tipo;

    Transporte(){
        this.nome = "";
        this.tipo = -1;
    }
    //existem dois metódos "transporte" <- sobrecarga
    Transporte(String nome, int tipo){
        this.nome = nome;
        this.tipo = tipo;
    }
}
