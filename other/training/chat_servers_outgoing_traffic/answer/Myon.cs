using System;
using System.Collections.Generic;

class Myon
{
    public static void Main()
    {
        new Myon().calc();
    }

    void calc()
    {
        int member = 0;
        int ret = 0;
        while (true)
        {
            string s = Console.ReadLine() ?? "";
            if (s.Length == 0) break;
            string[] st = s.Split(':');
            if (st.Length == 1)
            {
                if (s[0] == '+') member++;
                else member--;
            }
            else
            {
                ret += member * st[1].Length;
            }
            
        }
        Console.WriteLine(ret);
    }
}
