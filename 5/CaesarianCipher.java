import java.util.Scanner;

public class CaesarianCipher
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
            char replacement = ' ';
            if (c != replacement)
            {
                replacement = (char) (c - N);
                if (replacement < 'A') replacement = (char) ('Z' + 1 - N);
                if (replacement > 'Z') replacement = (char) ('A' + c - 'Z' + 2);
            }
            translated += replacement;
        }
        System.out.println(translated);
    }
}
