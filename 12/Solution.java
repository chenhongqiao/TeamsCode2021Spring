import java.util.Scanner;

public class Solution {
    public static void main(String[] argS) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int nrt = 1 + (int) Math.sqrt(n);
        for (int i = 2; i < nrt; i++) {
            int cnt = 0;
            while (n > 0 && n % i == 0) {
                n /= i;
                cnt++;
            }

            if (cnt != 0) {
                System.out.printf("%d %d\n", i, cnt);
            }
        }
        if (n != 1) {
            System.out.printf("%d 1\n", n);
        }
    }
}
