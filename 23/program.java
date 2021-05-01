import java.util.Scanner;

public class program
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int c = sc.nextInt();
        int[][] p = new int[50][105];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                p[i][j] = sc.nextInt();
            }
        }

        int ba = c;
        for (int i = 0; i < m - 1; i++)
        {
            int[] dp = new int[50005];
            for (int j = 0; j < 10005; j++)
            {
                dp[j] = -1000000005;
            }
            dp[ba] = ba;
            for (int j = 0; j < n; j++)
            {
                for (int k = p[i][j]; k <= ba; k++)
                {
                    dp[k - p[i][j]] = Math.max(dp[k] + p[i + 1][j] - p[i][j], dp[k - p[i][j]]);
                }
            }
            int lm = 0;
            for (int j = 0; j <= ba; j++)
            {
                lm = Math.max(lm, dp[j]);
            }
            ba = lm;
        }

        System.out.println(ba);
    }
}
