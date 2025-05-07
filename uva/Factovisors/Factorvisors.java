import java.math.BigDecimal;
import java.util.Scanner;

public class Factorvisors{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        BigDecimal n,m;

        while(sc.hasNext()){
            n = sc.nextBigDecimal();
            m = sc.nextBigDecimal();

            BigDecimal fatorial = BigDecimal.ONE;
            BigDecimal tempn = n;
            for(int i = 0; i < n.intValue(); i++){
                fatorial = fatorial.multiply(tempn);
                tempn = tempn.subtract( BigDecimal.ONE);
            }

            if(fatorial.remainder(m) == BigDecimal.ZERO){
                System.out.printf("%.0f divides %.0f!\n", m,n);
            }else{
                System.out.printf("%.0f does not divide %.0f!\n", m,n);
            }
        }
        
    }   
}   