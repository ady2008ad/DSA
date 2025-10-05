import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        if(n%5==0 && n%7 ==0 && n%11!=0){
            System.out.println("Number is divisible by 5 and 7 but not divisible by 11");
        }
        else{
            System.out.println("Number is either not divisible by 5 and 7 or divisible by 11");
        }
    }
}