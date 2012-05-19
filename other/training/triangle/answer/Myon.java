import java.util.*;

public class Myon
{
    public static void main(String[] args)
    {
        new Myon().calc();
    }

    void calc()
    {
        Scanner cin = new Scanner(System.in);
        int[] num = new int[4];
        for (int i = 0; i < 4; i++)
        {
            num[i] = cin.nextInt();
        }
        Arrays.sort(num);
        if (num[0] + num[1] > num[2] || num[1] + num[2] > num[3]) System.out.println("TRIANGLE");
        else if(num[0] + num[1] == num[2] || num[1] + num[2] == num[3]) System.out.println("SEGMENT");
        else System.out.println("IMPOSSIBLE");
    }
}
