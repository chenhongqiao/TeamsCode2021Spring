// This solution needs to be updated
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class UnitConversion
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        Map<String, Double> factorMap = new HashMap<>();
        for (int i = 0; i < N; i++)
        {
            double u1Amt = sc.nextDouble();
            String u1Name = sc.next();
            double u2Amt = sc.nextDouble();
            String u2Name = sc.next();
            factorMap.put(u1Name + " " + u2Name, u2Amt / u1Amt);
            factorMap.put(u2Name + " " + u1Name, u1Amt / u2Amt);
        }
        for (int i = 0; i < M; i++)
        {
            double baseAmt = sc.nextDouble();
            String baseUnit = sc.next();
            String tgtUnit = sc.next();
            double target = factorMap.get(baseUnit + " " + tgtUnit) * baseAmt;
            System.out.printf("%.3f\n", target);
        }
    }
}
