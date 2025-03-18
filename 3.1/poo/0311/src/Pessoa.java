public class Pessoa {
    String nome;
    int idade;
    String sexo;
    String cpf;

    public String getNome() {
        return nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getSexo() {
        return sexo;
    }

    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    Pessoa(String nome, int idade, String sexo, String cpf) {
        this.nome = nome;
        this.idade = idade;
        this.sexo = sexo;
        this.cpf = cpf;
    }

    public static void main(String[] args) {
        Pessoa p1 = new Pessoa("Luna", 19, "Feminino", "1234");
        Pessoa p2 = new Pessoa("Camila", 21, "Feminino", "1235");
        Pessoa p3 = new Pessoa("Luis", 20, "Masculino", "1236");

        System.out.println(p1.nome + ", " + p2.nome + " e " + p3.nome);
    }
}
