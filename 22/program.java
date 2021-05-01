import java.util.Scanner;

public class program
{
    public static int[][] sum;
    public static int[][][] m;
    public static char[][] wf;
    public static int n, k, l;

    public static int dfs(int r, int c, int s)
    {
        if (m[r][c][s] != -1)
        {
            return m[r][c][s];
        }
        m[r][c][s] = 0;
        if (s == 0)
        {
            if (sum[r][c] >= l)
            {
                m[r][c][s] = 1;
            }
        }
        else
        {
            for (int i = r + 1; i < n; i++)
            {
                if (sum[r][c] - sum[i][c] >= l && sum[i][c] >= s)
                {
                    m[r][c][s] += (dfs(i, c, s - 1) % 1000000007);
                    m[r][c][s] %= 1000000007;
                }
            }
            for (int j = c + 1; j < n; j++)
            {
                if (sum[r][c] - sum[r][j] >= l && sum[r][j] >= s)
                {
                    m[r][c][s] += dfs(r, j, s - 1) % 1000000007;
                    m[r][c][s] %= 1000000007;
                }
            }
        }
        return m[r][c][s];
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        l = sc.nextInt();

        sum = new int[55][55];
        m = new int[55][55][15];
        wf = new char[55][55];
        
        for (int i = 0; i < n; i++)
        {
            char[] c = new char[55];
            char[] line = sc.next().toCharArray();
            System.arraycopy(line, 0, c, 0, line.length);
            wf[i] = c;
        }
        
        sc.close();

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                sum[i][j] = sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1] + (wf[i][j] == 'S' ? 1 : 0);
            }
        }

        for (int i = 0; i < 55; i++)
        {
            for (int j = 0; j < 55; j++)
            {
                for (int p = 0; p < 15; p++)
                {
                    m[i][j][p] = -1;
                }
            }
        }

        System.out.println(dfs(0, 0, k));
    }
}
