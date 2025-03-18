import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.*;

public class e3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int v[] = new int[n];

        for (int i = 0; i < n; i++) {
            v[i] = sc.nextInt();
        }

        Arrays.sort(v);

        for (int i = 0; i < n; i++) {
            System.out.println(v[i]);
        }
    }
}