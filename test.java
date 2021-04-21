import java.util.*;
class test {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        System.out.println(isPowerOf2(n));
        sc.close();
    }
    static boolean isPowerOf2(int n) {
        return (boolean)((boolean)n && (boolean)(~(n & n-1)));
    }
}