import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Solution
{

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Map<Integer, Segment> q = new HashMap<>();

        for (int i = 0; i < n; i++)
        {
            int s = sc.nextInt();
            int e = sc.nextInt();
            q.put(i, new Segment(s, e, i));
        }

        sc.close();

        int ans = 0;

        while (!q.isEmpty())
        {
            Segment cur = q.entrySet().iterator().next().getValue();

            List<Segment> rm = new ArrayList<>();
            rm.add(cur);

            for (Integer id : q.keySet())
            {
                Segment s = q.get(id);
                if (s != cur)
                {
                    if (!overlapSegs(s, rm))
                    {
                        rm.add(s);
                    }
                }
            }

           for (Segment s : rm)
           {
               q.remove(s.id);
           }

            ans++;
        }

        System.out.println(ans);
    }

    public static boolean overlapSegs(Segment a, List<Segment> segs)
    {
        for (Segment seg : segs)
        {
            if (a.start >= seg.start && a.start <= seg.end)
                return true;
            if (a.end >= seg.start && a.end <= seg.end)
                return true;
        }
        return false;
    }

    static class Segment
    {
        int start, end, id;

        public Segment(int start, int end, int id)
        {
            this.start = start;
            this.end = end;
            this.id = id;
        }
    }
}