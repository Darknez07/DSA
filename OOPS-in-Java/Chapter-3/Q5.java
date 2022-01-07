import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        input.close();
        long p;
        String s;
        for(long i=100000000;i<=999999999;i++){
            s = Long.toString(i).substring(0, n);
            p = Long.parseLong(s);
            if(p % n == 0){
                System.out.println(i);
                break;
            }
        }
    }
}
