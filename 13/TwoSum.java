import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class TwoSum
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] arr = new int[n];
        Set<Integer> set = new HashSet<>();
        
        for (int i = 0; i < n; i++)
        {
            arr[i] = sc.nextInt();
        }

        int res = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (set.contains(m - arr[i]))
            {
                res++;
            }
            set.add(arr[i]);
        }
        System.out.println(res);
    }
}
