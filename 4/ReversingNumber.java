import java.util.Scanner;

public class ReversingNumber
{
    public static String reverse(String s)
    {
        if (s == null) return null;
        if (s.length() <= 1) return s;
        return s.substring(s.length() - 1) + reverse(s.substring(0, s.length() - 1));
    }
    
    public static void main(String[] args)
    {
        System.out.println(reverse(new Scanner(System.in).nextLine()));
    }
}
