import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        for (int i = 0; i < N; i++) {
            char op = sc.next().charAt(0);
            int A = sc.nextInt();
            if (op == '+') {
                M += A;
            } else {
                M -= A;
            }
        }
        System.out.println(M);
    }
}
