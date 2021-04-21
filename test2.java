import java.util.*;
public class test2 {
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        System.out.println(Sum(n));
    }
    static int Sum(int n) {
        if (n == 0)
            return 0;
        return n+Sum(n-1) ;
    }
}
