import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c = 0;
        for (int i = 0; i < n; i++) {
            String cur = sc.next();
            for (int j = 1; j < cur.length(); j++) {
                String h1 = cur.substring(0, j);
                String h2 = cur.substring(j);
                if (h1.equals(reverse(h1)) && h2.equals(reverse(h2))) {
                    c++;
                    break;
                }
            }
        }
        System.out.println(c);
    }

    public static String reverse(String str) {
        if (str == null || str.length() == 0)
            return "";
        return str.substring(str.length() - 1) + reverse(str.substring(0, str.length() - 1));
    }
}
