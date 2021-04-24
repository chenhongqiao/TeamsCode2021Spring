import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class program {
    public static ArrayList<Point>[][] graph;
    public static boolean[][] visited;

    public static long bfs(int x, int y) {
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(x, y));
        long cnt = 1;
        while (!q.isEmpty()) {
            Point cur = q.poll();
            for (int i = 0; i < graph[cur.x][cur.y].size(); i++) {
                Point neighbor = graph[cur.x][cur.y].get(i);
                if (!visited[neighbor.x][neighbor.y]) {
                    q.add(new Point(neighbor.x, neighbor.y));
                    visited[neighbor.x][neighbor.y] = true;
                    cnt++;
                }
            }
        }
        return cnt * (cnt - 1);
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        graph = new ArrayList[n + 1][n + 1];
        visited = new boolean[n + 1][n + 1];
        ArrayList<Point> cities = new ArrayList<Point>();

        for (int i = 0; i < m; i++) {
            int x1 = sc.nextInt();
            int y1 = sc.nextInt();
            int x2 = sc.nextInt();
            int y2 = sc.nextInt();
            if (graph[x1][y1] == null) {
                graph[x1][y1] = new ArrayList<>();
            }
            if (graph[x2][y2] == null) {
                graph[x2][y2] = new ArrayList<>();
            }
            graph[x1][y1].add(new Point(x2, y2));
            graph[x2][y2].add(new Point(x1, y1));
            cities.add(new Point(x1, y1));
            cities.add(new Point(x2, y2));
        }

        sc.close();

        long ans = (long) n * n;

        for (int i = 0; i < cities.size(); i++) {
            Point city = cities.get(i);
            if (!visited[city.x][city.y]) {
                visited[city.x][city.y] = true;
                ans += bfs(city.x, city.y);
            }
        }
        System.out.println(ans);
    }

    static class Point {
        public int x;
        public int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
