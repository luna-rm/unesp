public class Pessoa {
    private int idade;
    private String nome;

    Pessoa(){
        this.nome = "";
        this.idade = -1;
    }

    public int getIdade() {
        return idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    public void print_Dados(){
        System.out.println("Nome: " + this.nome + " | Idade: " + this.idade);
    }

    public static void main(String[] args){
        Pessoa p1 = new Pessoa();
        System.out.println("Nome padrao: " + p1.getNome());
        System.out.println("Idade padrao: " + p1.getIdade());

        p1.setIdade(19);
        p1.setNome("Luna Ricieri Marchi");
        
        p1.print_Dados();
    }
}
