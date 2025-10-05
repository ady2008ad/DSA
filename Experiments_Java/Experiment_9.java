import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        int r=1;
        int a=n;
        while(n>0){
            r=r*n;
            n--;
        }
        System.out.println("Factorial of "+a+" is "+r);
    }
}