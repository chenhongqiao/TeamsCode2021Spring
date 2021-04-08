import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int r = sc.nextInt();
        Queue<Integer> q = new PriorityQueue<Integer>();
        for (int i = 0; i < n; i++) {
            q.add(sc.nextInt());
        }

        int dark = 0;
        int prevPos = q.remove();

        if (prevPos - r > 0)
            dark++;

        while (!q.isEmpty()) {
            int curPos = q.remove();
            // darkness gap dist = curPos - r - (prevPos + r)
            // = curPos - prevPos - 2r
            if (curPos - prevPos - 1 - 2 * r > 0)
                dark++;
            prevPos = curPos;
        }

        // last light does not reach end of street?
        if (prevPos + r < m)
            dark++;

        System.out.println(dark);
    }
}
