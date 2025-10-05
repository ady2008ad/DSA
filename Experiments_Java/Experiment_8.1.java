import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i%2==0 || i%3==0){
                sum=sum+i;
            }
        }
        System.out.println("Sum of numbers divisible by 2 or 3: "+sum);
    }
}