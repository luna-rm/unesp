package ex3;

import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

public class Times {
    public static void main(String[] args) {
        try (Scanner sn = new Scanner(System.in)) {
            int n = sn.nextInt();
            Vector<Integer> vec = new Vector<Integer>();

            for(int i = 0; i < n; i++){
                vec.add(sn.nextInt());
            }

            Collections.sort(vec);

            int ans = 0;
            while(vec.size() != 0){
                int n1 = vec.firstElement();
                vec.remove(0);
                int n2 = vec.firstElement();
                vec.remove(0);

                ans += n2-n1;
            }

            System.out.println(ans);
        }
        
    }
}
