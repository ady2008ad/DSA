import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int isPrime=1;
        for(int i=2;i<=n/2;i++){
            if(n%i==0){
                isPrime=0;   
            }
        }
        if(isPrime==1){
            System.out.println("It is a prime number.");
        }
        else{
            System.out.println("It is not a prime number.");
        }
    }
}