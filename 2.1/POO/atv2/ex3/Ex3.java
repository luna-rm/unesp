package ex3;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Ex3 {

    public static void main(String[] args) {
        try (Scanner sn = new Scanner(System.in)) {
            System.out.print("Primeiro Valor (0 para parar): ");
            int vetor[] = new int[10];
            int where = 0;

            try{
                int aux = sn.nextInt();
                while(aux != 0){
                    vetor[where] = aux;
                    where++;
                    System.out.print("Proximo Valor (0 para parar): ");
                    aux = sn.nextInt();
                }
                if(where < 10){
                    vetor[where] = 0;
                    where++;
                }
            } catch (ArrayIndexOutOfBoundsException e){
                System.out.println("Nosso Array nao consegue armazenar tanto!");
            } catch (InputMismatchException e){
                System.out.println("Voce nao digitou um numero!");
            }

            System.out.println("Os valores salvos:");
            for(int i = 0; i < where; i++){
                System.out.print(vetor[i] + " ");
            }
        }
    }
    
    
}