import java.util.Scanner;

public class program {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String initTimeStr = sc.next();
        int speed = sc.nextInt();
        int distance = sc.nextInt();
        int initTimeMins = 60 * Integer.parseInt(initTimeStr.substring(0, initTimeStr.indexOf(":")))
                + Integer.parseInt(initTimeStr.substring(initTimeStr.indexOf(":") + 1));
        int dt = (int) 60 * distance / speed;
        int finalTimeMins = initTimeMins + dt;
        int hrs = finalTimeMins / 60 % 24;
        int mins = finalTimeMins % 60;
        System.out.printf("%02d:%02d\n", hrs, mins);
    }
}
