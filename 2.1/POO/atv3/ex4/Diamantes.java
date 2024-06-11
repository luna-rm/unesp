package ex4;

import java.util.Scanner;

public class Diamantes {
    
    public static void main(String[] args) {
        try (Scanner sn = new Scanner(System.in)) {
            int n = sn.nextInt();
            sn.nextLine();
            for (int i = 0; i < n; i++){
                String str = sn.nextLine();
                int dia = 0;
                int ans = 0;
                for(int j = 0; j < str.length(); j++){
                    if(str.charAt(j) == '<'){
                        dia++;
                    }
                    if(str.charAt(j) == '>'){
                        dia--;
                        if(dia < 0){
                            dia = 0;
                            continue;
                        }
                        ans++;
                    }
                }
                System.out.println(ans);
            }
        }

    }
}
