using System;
using System.Collections.Generic;

class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

}

class Myon
{
    Scanner cin;

    public static void Main()
    {
        new Myon().calc();
    }

    void calc()
    {
        cin = new Scanner();
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
                Console.WriteLine(i + " " + (n - i));
                return;
            }
        }
        Console.WriteLine(n + " " + 0);
    }
}
