import java.math.BigDecimal;
import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        String s;
        
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            s = sc.nextLine();
            if(s.equals("0")){
                break;
            }

            if(s.length() == 1){
                System.out.println(0);
                continue;
            }

            String temp = "";
            for(int i = 0; i < s.length()-1; i++){
                temp += s.charAt(i);
            }
            
            BigDecimal b = new BigDecimal(temp);
            BigDecimal d = new BigDecimal(5 * (s.charAt(s.length()-1) - '0'));
            BigDecimal diference = b.subtract(d);
            BigDecimal seveteen = new BigDecimal(17);
            BigDecimal zero = new BigDecimal(0);
            BigDecimal positivo = diference.abs();
            BigDecimal resto = positivo.remainder(seveteen);
            
            
            if(resto.compareTo(zero) == 0){
                System.out.println(1);
            }else{
                System.out.println(0);
            }
        }

        sc.close();
    }
}