import java.util.*;

public class e5_Aluno {
    static int num_alunos = 0;
    int ra;
    String rg;
    String nome;
    String data_nasc;
    String endereco;
    String telefone;
    double CR;
    static ArrayList<e5_Aluno> lista = new ArrayList<>();

    public int getRa() {
        return ra;
    }

    public void setRa(int ra) {
        this.ra = ra;
    }

    public String getRg() {
        return rg;
    }

    public void setRg(String rg) {
        this.rg = rg;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getData_nasc() {
        return data_nasc;
    }

    public void setData_nasc(String data_nasc) {
        this.data_nasc = data_nasc;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public double getCR() {
        return CR;
    }

    public void setCR(double CR) {
        while(CR < 0 || CR > 10){
            Scanner sc = new Scanner(System.in);
            System.out.println("CR invalido, tente novamente");
            CR = sc.nextDouble();
            sc.close();
        }
        this.CR = CR;
    }

    public e5_Aluno(String rg, String nome, String data_nasc, String endereco, String telefone, double CR) {
        num_alunos += 1;
        this.ra = num_alunos;
        this.rg = rg;
        this.nome = nome;
        this.data_nasc = data_nasc;
        this.endereco = endereco;
        this.telefone = telefone;
        while(CR < 0 || CR > 10){
            Scanner sc = new Scanner(System.in);
            System.out.println("CR invalido, tente novamente");
            CR = sc.nextInt();
            sc.close();
        }
        this.CR = CR;
        lista.add(this);
    }

    static e5_Aluno procurar_Aluno(){
        System.out.println("Informe o RA do aluno:");
        Scanner sc = new Scanner(System.in);
        int ra = sc.nextInt();
        for(e5_Aluno aluno : lista){
            if(ra == aluno.getRa()){
                sc.close();
                return aluno;
            }
        }
        sc.close();
        return null;
    }

    static void imprime_ra(){
        for(e5_Aluno a : lista){
            System.out.println(a.getRa() + " " + a.getNome() + " " + a.getCR());
        }
    }
    static void imprime_nome(){
        ArrayList<e5_Aluno> lista_nome = new ArrayList<>();
        lista_nome = lista;
        Collections.sort(lista_nome, new sortName());

        for(e5_Aluno a : lista_nome){
            System.out.println(a.getRa() + " " + a.getNome() + " " + a.getCR());
        }
    }
    static void imprime_cr(){
        ArrayList<e5_Aluno> lista_cr = new ArrayList<>();
        lista_cr = lista;
        Collections.sort(lista_cr, new sortCr());

        for(e5_Aluno a : lista_cr){
            System.out.println(a.getRa() + " " + a.getNome() + " " + a.getCR());
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean stop = false;
        while(!stop){
            System.out.println("SISTEMA DE ALUNOS");
            System.out.println("1 - Cadastrar aluno");
            System.out.println("2 - Imprimir aluno");
            System.out.println("3 - Alterar dados do aluno");
            System.out.println("4 - Listar por RA");
            System.out.println("5 - Listar por Nome");
            System.out.println("6 - Listar por CR");
            System.out.println("0 - Sair");

            int aux = 0;
            if(sc.hasNextInt()){
                aux = sc.nextInt();
            } else {
                aux = 0;
            }

            sc.nextLine();

            if(aux == 0){
                stop = true;
            } else if (aux == 1) {
                System.out.print("Digite o RG do aluno: ");
                String rg = sc.nextLine();
                System.out.print("Digite o nome do aluno: ");
                String nome = sc.nextLine();
                System.out.print("Digite a data de nascimento do aluno: ");
                String data_nasc = sc.nextLine();
                System.out.print("Digite o endereco do aluno: ");
                String endereco = sc.nextLine();
                System.out.print("Digite o telefone do aluno: ");
                String telefone = sc.nextLine();
                System.out.print("Digite a CR do aluno: ");
                double CR = sc.nextDouble();

                e5_Aluno a = new e5_Aluno(rg, nome, data_nasc, endereco, telefone, CR);
            } else if (aux == 2) {
                e5_Aluno a = procurar_Aluno();
                if(a == null){
                    System.out.println("Aluno nao encontrado");
                } else {
                    System.out.println(a.getRa() + " " + a.getNome() + " " + a.getCR() + " " +a.getEndereco() + " " + a.getData_nasc() + " " + a.getTelefone());
                }
            } else if (aux == 3) {
                e5_Aluno a = procurar_Aluno();
                if(a == null){
                    System.out.println("Aluno nao encontrado");
                } else {
                    System.out.println("1 - RG");
                    System.out.println("2 - Nome");
                    System.out.println("3 - CR");
                    System.out.println("4 - Endereco");
                    System.out.println("5 - Telefone");
                    System.out.println("6 - Data de nascimento");
                    int mudar = sc.nextInt();
                    sc.nextLine();
                    if(mudar == 1){
                        System.out.print("Informe novo RG: ");
                        String rg = sc.nextLine();
                        a.setRg(rg);
                    } else if (mudar == 2) {
                        System.out.print("Informe novo Nome: ");
                        String nome = sc.nextLine();
                        a.setNome(nome);
                    } else if (mudar == 3) {
                        System.out.print("Informe novo CR: ");
                        double CR = sc.nextDouble();
                        a.setCR(CR);
                    } else if (mudar == 4) {
                        System.out.print("Informe novo Endereco: ");
                        String endereco = sc.nextLine();
                        a.setEndereco(endereco);
                    } else if (mudar == 5) {
                        System.out.print("Informe novo Telefone: ");
                        String telefone = sc.nextLine();
                        a.setTelefone(telefone);
                    } else if (mudar == 6) {
                        System.out.print("Informe novo Data de nascimento: ");
                        String data_nasc = sc.nextLine();
                        a.setData_nasc(data_nasc);
                    }
                    sc.nextLine();
                }
            } else if (aux == 4) {
                imprime_ra();
            } else if (aux == 5) {
                imprime_nome();
            } else if (aux == 6) {
                imprime_cr();
            }
        }
    }
}

class sortName implements Comparator<e5_Aluno>{
    @Override
    public int compare(e5_Aluno o1, e5_Aluno o2) {
        if(o1.getNome().compareTo(o2.getNome()) < 0){
            return -1;
        } else {
            return 1;
        }
    }
}

class sortCr implements Comparator<e5_Aluno>{
    @Override
    public int compare(e5_Aluno o1, e5_Aluno o2) {
        return Double.compare(o1.getCR(), o2.getCR());
    }
}