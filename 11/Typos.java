import java.util.Scanner;

public class Typos
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        String updated = "";
        for (int i = 0; i < n; i++)
        {
            int shift = sc.nextInt();
            s[i] = s[i - shift];
        }
        System.out.println(new String(s));
    }
}
