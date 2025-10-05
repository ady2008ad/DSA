import java.util.*;
public class Main{
    public static int factorial(int n){
        if(n==1||n==0){
            return 1;
        }
        else{
            return n*factorial(n-1);
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int a=n;
        int sum=0;
        int b;
        while(n>0){
            b=n%10;
            sum=sum+factorial(b);
            n=n/10;
        }
        if(sum==a){
            System.out.println("It is a strong number.");
        }
        else{
            System.out.println("It is not a strong number.");
        }
    }
}