import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class program {
    public static Map<String, List<Pair>> graph;
    public static Map<String, Integer> dp;
    public static Set<String> visited;

    public static void dfs(String u, int ac) {
        dp.put(u, ac);
        List<Pair> neighbors = graph.get(u);
        for (int i = 0; i < neighbors.size(); i++) {
            Pair neighbor = neighbors.get(i);
            if (!visited.contains(neighbor.first)) {
                visited.add(neighbor.first);
                dfs(neighbor.first, ac + neighbor.second);
            }
        }
    }

    public static void main(String[] args) {
        graph = new HashMap<>();
        dp = new HashMap<>();
        visited = new HashSet<>();

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String rt = null;

        for (int i = 0; i < n - 1; i++) {
            String a = sc.next();
            String b = sc.next();
            int x = sc.nextInt();
            if (i == 0) {
                rt = a;
            }
            if (!graph.containsKey(a))
                graph.put(a, new ArrayList<>());
            if (!graph.containsKey(b))
                graph.put(b, new ArrayList<>());
            graph.get(a).add(new Pair(b, x));
            graph.get(b).add(new Pair(a, -x));
        }

        visited.add(rt);
        dp.put(rt, 0);
        dfs(rt, 0);

        for (int i = 0; i < m; i++) {
            String a = sc.next();
            String b = sc.next();
            System.out.println(dp.get(b) - dp.get(a));
        }

        sc.close();
    }

    static class Pair {
        public String first;
        public int second;

        public Pair(String first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
