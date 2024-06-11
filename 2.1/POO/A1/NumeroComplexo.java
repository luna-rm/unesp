package A1;
public class NumeroComplexo {
    double r, i;

    void atrib(double ar, double ai){
        r = ar;
        i = ai;
    }

    public static void main (String s[]){
        NumeroComplexo x = new NumeroComplexo();
        x.atrib(1.2, 9.8);
        System.out.format("(%.1f + %.1fi)", x.r, x.i);
    }
}
