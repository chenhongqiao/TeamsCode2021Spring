import java.util.Scanner;

public class Solution
{
    public static void main(String[] args)
    {
        boolean[][] dp = new boolean[25000000][2];
        dp[20210424][0] = true;
        for (int i = 20210423; i >= 0; i--)
        {
            dp[i][0] = (dp[i + 1][1] && dp[i + 123][1]);
            dp[i][1] = (dp[i + 1][0] || dp[i + 123][0]);
        }
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++)
        {
            int s = sc.nextInt();
            System.out.println(dp[s][1] ? "Yes" : "No");
        }
        sc.close();
    }
}
