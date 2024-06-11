package ex2;
import java.util.Scanner;
import java.lang.Math; 

public class Ex2 {

    public static void main(String[] args) {
        try (Scanner sn = new Scanner(System.in)) {
            System.out.print("A: ");
            double a = sn.nextDouble();
            System.out.print("B: ");
            double b = sn.nextDouble();
            System.out.print("C: ");
            double c = sn.nextDouble();
   
            double delta = b*b - (4*a*c);
            System.out.println("delta = " + b + "*" + b + " - (4*" + a + "*" + c + ") = " + delta );

            try {
                double x1 = (-b + Math.sqrt(delta))/2*a;
                double x2 = (-b - Math.sqrt(delta))/2*a;
                
                if(Double.isNaN(x1) || Double.isNaN((x2))){
                    throw new ExecNotNegative();
                }
                if(x1 == x2){
                    throw new ExecRaizIgual();
                }

                System.out.println("X1: " + x1);
                System.out.println("X2: " + x2);
            } catch (Exception e) {
                System.out.println(e.toString());
            }
        }

        /*
         * This won't produce a runtime error in the sense that
         * term is used in Java; i.e. no exception will be thrown. 
         * The sqrt call terminates normally and returns a NaN value.
         * NaN is a well-defined value, per the Java Language spec and 
         * IEE floating point spec.
         */

    }
}