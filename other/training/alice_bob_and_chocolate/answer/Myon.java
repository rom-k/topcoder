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
        int n = cin.nextInt();
        int[] num = new int[n];
        int[] dp = new int[n + 1];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i + 1] = sum += num[i] = cin.nextInt();
        }
        for (int i = 0; i < n; i++)
        {
            if (dp[i] <= sum - dp[i + 1]) continue;
            else
            {
                System.out.println(i + " " + (n - i));
                return;
            }
        }
        System.out.println(n + " " + 0);
    }
}
