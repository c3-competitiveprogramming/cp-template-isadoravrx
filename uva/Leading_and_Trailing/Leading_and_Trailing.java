import java.util.Scanner;
import java.math.BigDecimal;
public class Leading_and_Trailing{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();

        while(t > 0){
            t--;

            BigDecimal n;
            int k;
            n = sc.nextBigDecimal();
            k = sc.nextInt();

            BigDecimal ans1 = BigDecimal.ONE;
            BigDecimal ans2 = BigDecimal.ONE;

            BigDecimal tresultimos = new BigDecimal(pegar3ultimos(n));

            for(int i = 0; i < k ; i++){    
                ans1 = ans1.multiply(n).remainder(BigDecimal.valueOf(1000000000));
                ans2 = ans2.multiply(tresultimos);
            }

            String ans1String = ans1.toString();
            String ans2String = ans2.toString();

            for(int i = 0; i < 3; i++){
                System.out.printf("%c", ans1String.charAt(i));
            }            

            System.out.printf("...");

            
            for(int i = 0; i < 3; i++){
                System.out.printf("%c", ans2String.charAt(i));
            }            

            System.out.printf("\n");

        }
        
    }
    static int pegar3ultimos(BigDecimal n){
        String temp = n.toString();
        String result = "";

        int cont = 0;
        for(int i = temp.length()-1; i >= 0 && cont < 3; i--){
            result += temp.charAt(i);
            cont++;
        }

        String result2 = "";
        for(int i = result.length() -1; i >= 0; i--){
            result2 += result.charAt(i);
        }
        return Integer.valueOf(result2);

    }
}