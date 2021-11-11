import java.util.*;

public class fib {

    public static void main(String[] args) {
        Scanner Sc = new Scanner(System.in);
        int n;
        n = Sc.nextInt();
        System.out.println(Fib(n, new long[n + 1]));
        Sc.close();
    }

    public static long Fib (int n, long[] dp) {
        if (n <= 1) {
            return n;
        }

        if (dp[n] != 0) {
            return dp[n];
        }
        dp[n] = Fib(n-1, dp) + Fib(n-2, dp);
        return dp[n];
    }
}