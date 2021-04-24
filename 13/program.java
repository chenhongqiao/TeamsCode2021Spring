import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class program {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] ans = new int[100005];
        List<Person> p = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int v = sc.nextInt();
            p.add(new Person(i, v));
        }

        Collections.sort(p);
        int rk = 1;

        for (int i = 0; i < p.size(); i++) {
            ans[p.get(i).id] = rk;
            if (i != n - 1 && p.get(i + 1).s != p.get(i).s) {
                rk = i + 2;
            }
        }

        for (int i = 0; i < n; i++)
            System.out.print(ans[i] + " ");

        System.out.println();
    }

    static class Person implements Comparable<Person> {
        public int id;
        public int s;

        public Person(int id, int s) {
            this.id = id;
            this.s = s;
        }

        @Override
        public int compareTo(Person arg0) {
            return Integer.compare(arg0.s, s);
        }

    }
}
