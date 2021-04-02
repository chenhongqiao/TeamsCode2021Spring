import java.util.Scanner;

public class Solution
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.nextLine());
        String toTranslate = sc.nextLine();
        String translated = "";
        for (int i = 0; i < toTranslate.length(); i++)
        {
            char c = toTranslate.charAt(i);
            char replacement = (char)((26 + (c - 65 + N) % 26) % 26 + 65);
            translated += replacement;
        }
        System.out.println(translated);
    }
}
