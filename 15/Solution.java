import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution
{
    static class Pair
    {
        int first, second;

        public Pair(int first, int second)
        {
            this.first = first;
            this.second = second;
        }
    }

    static class Node
    {
        int x, y, s;

        public Node(int x, int y, int s)
        {
            this.x = x;
            this.y = y;
            this.s = s;
        }
    }

    public static final int[] dx = { 1, -1, 0, 0 };
    public static final int[] dy = { 0, 0, 1, -1 };

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int[][] mz = new int[1005][1005];
        Pair[][] pw = new Pair[1005][1005];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mz[i][j] = sc.nextInt();
                pw[i][j] = new Pair(0, -1);
            }
        }

        Queue<Node> q = new LinkedList<>();
        pw[0][0] = new Pair(1, 0);
        q.add(new Node(0, 0, 0));

        while (!q.isEmpty())
        {
            Node k = q.poll();
            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + k.x;
                int ny = dy[i] + k.y;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && mz[nx][ny] != 1)
                {
                    if (pw[nx][ny].second == -1)
                    {
                        pw[nx][ny] = new Pair(pw[k.x][k.y].first, k.s);
                        q.add(new Node(nx, ny, k.s + 1));
                    }
                    else if (k.s == pw[nx][ny].second)
                    {
                        pw[nx][ny].first += pw[k.x][k.y].first;
                        pw[nx][ny].first %= 1000000007;
                    }
                }
            }
        }
        System.out.println(pw[m - 1][n - 1].first);
    }
}
