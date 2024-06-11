package ex1;
import java.util.*;

class Comparador implements Comparator<Aluno> {
    public int compare(Aluno a1, Aluno a2) {
        return a1.nome.compareTo(a2.nome);
    }
}

public class Aluno {
    String nome;
    String ra;

    Aluno(String nome, String ra){
        this.nome = nome;
        this.ra = ra;
    }

    public String str_Aluno(){
        return("Nome: " + this.nome + " | RA: " + this.ra);
    }


    public static void main(String[] args) {
        try (Scanner sn = new Scanner(System.in)) {
            Vector<Aluno> vec = new Vector<Aluno>();

            System.out.print("Quantos Alunos: ");
            int n = sn.nextInt();

            sn.nextLine();

            for(int i = 0; i < n; i++){
                System.out.println(i);
                
                System.out.print("Nome: ");
                String nome_a = sn.nextLine();

                System.out.print("RA: ");
                String ra_a = sn.nextLine();

                Aluno a = new Aluno(nome_a, ra_a);

                vec.add(a);
            }

            Collections.sort(vec, new Comparador());

            System.out.println("\nLista de Alunos:");
            Iterator<Aluno> inter = vec.iterator();
            while(inter.hasNext()){                
                System.out.println(inter.next().str_Aluno());
            }
        }

    }
}