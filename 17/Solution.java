import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
    public static int n;
    public static int tree[];

    public static int sum(int p) {
        int s = 0;
        while (p > 0) {
            s += tree[p];
            p -= p & -p;
        }
        return s;
    }

    public static void update(int p, int v) {
        while (p <= n + 1) {
            tree[p] += v;
            p += p & -p;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();

        int[] a = new int[100005];
        int[] f = new int[100005];
        int[] snum = new int[100005];
        tree = new int[100005];

        Queue<Pair> q = new PriorityQueue<>();

        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
        }

        for (int i = 0; i < n - 1; i++) {
            int pageA = sc.nextInt();
            int pageB = sc.nextInt();
            snum[pageA]++;
            f[pageB] = pageA;
        }

        sc.close();

        for (int i = 1; i <= n; i++) {
            if (snum[i] == 0)
                q.add(new Pair(a[i], i));
        }

        long ans = 0;
        while (!q.isEmpty()) {
            Pair cur = q.poll();
            int p = cur.second;
            ans += sum(p);
            ans += cur.first * 3;
            update(p, cur.first);
            snum[f[p]]--;
            if (snum[f[p]] == 0)
                q.add(new Pair(a[f[p]], f[p]));
        }

        System.out.println(ans);

    }

    static class Pair implements Comparable<Pair> {
        public int first;
        public int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Solution.Pair arg0) {
            // reverse comparison for maxheap
            return -Integer.compare(first, arg0.first);
        }
    }
}
