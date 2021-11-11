import java.util.*;

public class climbStairs {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n;
        n = sc.nextInt();
        System.out.println(countPaths(n, new int[n + 1]));
        System.out.println(countPathsTab(n));
        sc.close();
    }

    public static int countPaths(int n, int[] dp) {
        if (n == 0) {
            return 1;
        }
        else if (n < 0) {
            return 0;
        }

        if (dp[n] != 0) {
            return dp[n];
        }

        dp[n] = countPaths(n-1, dp) + countPaths(n-2, dp) + countPaths(n-3, dp);
        return dp[n];
    }

    public static int countPathsTab(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;

        for (int i=1; i<=n;i++) {
            if (i == 1) {
                dp[i] = dp[i-1];
            }
            else if (i == 2){
                dp[i] = dp[i-1] + dp[i-2];
            }
            else 
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
}
