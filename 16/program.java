import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class program
{
    public static int n, m, q;
    public static int[] ans;
    public static List<Integer>[] g;
    public static List<Pair> df;
    public static boolean[] mp;

    public static void bfs(int f, int fv)
    {
        boolean[] vis = new boolean[10005];
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(f, fv));
        vis[f] = true;
        while (!q.isEmpty())
        {
            Pair k = q.poll();
            ans[k.first] = Math.max(ans[k.first], k.second);
            for (int i = 0; i < g[k.first].size(); i++)
            {
                if (!vis[g[k.first].get(i)] && !mp[g[k.first].get(i)] && k.second / 2 > ans[g[k.first].get(i)]
                    && k.first != 1)
                {
                    vis[g[k.first].get(i)] = true;
                    q.add(new Pair(g[k.first].get(i), k.second / 2));
                }
            }
        }
    }

    public static List<Pair> ar;

    @SuppressWarnings("unchecked")
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        q = sc.nextInt();

        g = new ArrayList[10005];
        df = new ArrayList<>();
        mp = new boolean[10005];
        ans = new int[10005];
        ar = new ArrayList<Pair>();

        for (int i = 0; i < m; i++)
        {
            int f = sc.nextInt();
            int v = sc.nextInt();
            df.add(new Pair(f, v));
            mp[f] = true;
        }

        for (int i = 0; i < q; i++)
        {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (g[a] == null)
            {
                g[a] = new ArrayList<>();
            }
            if (g[b] == null)
            {
                g[b] = new ArrayList<>();
            }
            g[a].add(b);
            g[b].add(a);
        }
        
        sc.close();

        Collections.sort(df, new Comparator<Pair>()
        {
            @Override
            public int compare(Pair a, Pair b)
            {
                return Integer.compare(a.second, b.second);
            }
        });

        for (int i = 0; i < df.size(); i++)
        {
            Pair p = df.get(i);
            bfs(p.first, p.second);
        }

        for (int i = 2; i <= n; i++)
        {
            ar.add(new Pair(i, ans[i]));
        }

        Collections.sort(ar, new Comparator<Pair>()
        {
            @Override
            public int compare(Pair a, Pair b)
            {
                if (a.second == b.second)
                {
                    return Integer.compare(a.first, b.first);
                }
                return Integer.compare(b.second, a.second);
            }
        });

        for (int i = 0; i < ar.size(); i++)
        {
            Pair p = ar.get(i);
            System.out.println(p.first + " " + p.second);
        }

    }

    static class Pair
    {
        public int first;
        public int second;

        public Pair(int first, int second)
        {
            this.first = first;
            this.second = second;
        }

    }
}
