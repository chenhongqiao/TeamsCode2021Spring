import java.util.Arrays;
import java.util.Scanner;

public class program {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        for (int i = 0; i < n; i++) {
            long[] arr = new long[m];
            for (int j = 0; j < m; j++) {
                arr[j] = sc.nextLong();
            }
            Arrays.sort(arr);
            System.out.println(arr[arr.length - 1] * arr[arr.length - 2]);
        }

    }
}
