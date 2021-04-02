import java.util.Scanner;

public class Solution
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int c = 0;
        for (int i = 0; i < N; i++)
            if (sc.nextInt() % 2 == 0)
                c++;
        System.out.println(c);
    }
}
