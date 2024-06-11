public class Aluno extends Pessoa {
    private String ra;

    Aluno(){
        super();
        ra = "00000000";
    }

    public void setRa(String ra) {
        this.ra = ra;
    }
    public String getRa() {
        return ra;
    }

    public void print_Dados(){
        System.out.println("Nome: " + this.getNome() + " | Idade: " + this.getIdade() + " | RA: " + this.getRa());
    }

    public static void main(String[] args){
        Aluno a1 = new Aluno();
        System.out.println("Nome padrao: " + a1.getNome());
        System.out.println("Idade padrao: " + a1.getIdade());
        System.out.println("RA padrao: " + a1.getRa());

        a1.setIdade(20);
        a1.setNome("Camila Cristina Silva");
        a1.setRa("12345678");
        
        a1.print_Dados();
    }
}
