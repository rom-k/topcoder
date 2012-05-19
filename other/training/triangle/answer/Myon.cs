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
        int[] num = new int[4];
        for (int i = 0; i < 4; i++)
        {
            num[i] = cin.nextInt();
        }
        Array.Sort(num);
        if (num[0] + num[1] > num[2] || num[1] + num[2] > num[3]) Console.WriteLine("TRIANGLE");
        else if(num[0] + num[1] == num[2] || num[1] + num[2] == num[3]) Console.WriteLine("SEGMENT");
        else Console.WriteLine("IMPOSSIBLE");
    }
}
