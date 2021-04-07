import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean[][] map = new boolean[n][n];
        boolean[][] visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = sc.nextInt() == 1;
            }
        }

        Queue<MazePos> bfsQueue = new LinkedList<>();
        bfsQueue.add(new MazePos(0, 0, 0));
        visited[0][0] = true;
        while (!bfsQueue.isEmpty()) {
            MazePos cur = bfsQueue.poll();

            if (cur.r == n - 1 && cur.c == 0) {
                System.out.println(cur.d);
                return;
            }

            // go EAST
            if (cur.c + 1 < n && !map[cur.r][cur.c + 1] && !visited[cur.r][cur.c + 1]) {
                bfsQueue.add(new MazePos(cur.r, cur.c + 1, cur.d + 1));
                visited[cur.r][cur.c + 1] = true;
            }

            // go SOUTH
            if (cur.r + 1 < n && !map[cur.r + 1][cur.c] && !visited[cur.r + 1][cur.c]) {
                bfsQueue.add(new MazePos(cur.r + 1, cur.c, cur.d + 1));
                visited[cur.r + 1][cur.c] = true;
            }

            // go WEST
            if (cur.c - 1 >= 0 && !map[cur.r][cur.c - 1] && !visited[cur.r][cur.c - 1]) {
                bfsQueue.add(new MazePos(cur.r, cur.c - 1, cur.d + 1));
                visited[cur.r][cur.c - 1] = true;
            }

            // go NORTH
            if (cur.r - 1 >= 0 && !map[cur.r - 1][cur.c] && !visited[cur.r - 1][cur.c]) {
                bfsQueue.add(new MazePos(cur.r - 1, cur.c, cur.d + 1));
                visited[cur.r - 1][cur.c] = true;
            }

        }

        System.out.println("-1");
    }

    static class MazePos {
        public int r;
        public int c;
        public int d;

        public MazePos(int r, int c, int d) {
            this.r = r;
            this.c = c;
            this.d = d;
        }
    }
}
