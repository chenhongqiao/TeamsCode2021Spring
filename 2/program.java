import java.util.Scanner;

public class program {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int c = 0;
        for (int i = 0; i < N; i++)
            System.out.printf("%d ", sc.nextInt() % 3);
        System.out.printf("\n");
    }
}
