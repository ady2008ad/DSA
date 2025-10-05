import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int sum=0;
        int a;
        int b=n;
        while(n>0){
            a=n%10;
            sum=sum+a;
            n=n/10;
        }
        System.out.println("Sum of digits of "+b+" is "+sum);
    }
}