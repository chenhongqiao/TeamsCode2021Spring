import java.util.Scanner;

public class FlightArrival
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String initTimeStr = sc.next();
        int speed = sc.nextInt();
        int distance = sc.nextInt();
        int initTimeMins = 
            60 * Integer.parseInt(initTimeStr.substring(0, initTimeStr.indexOf(":")))
            + Integer.parseInt(initTimeStr.substring(initTimeStr.indexOf(":") + 1));
       int dt = (int)60.0 * distance / speed;
       int finalTimeMins = initTimeMins + dt;
       int hrs = finalTimeMins / 60;
       int mins = finalTimeMins % 60;
       System.out.printf("%d:%d\n", hrs, mins);
    }
}
