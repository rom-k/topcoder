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
        int h = cin.nextInt();
        int w = cin.nextInt();
        char c = cin.next()[0];
        string[] board = new string[h];
        for (int i = 0; i < h; i++)
        {
            board[i] = cin.next();
        }
        Dictionary<char, int> dic = new Dictionary<char, int>();
        dic['.'] = 1;
        dic[c] = 1;
        int[] vx = new int[] { 1, 0, -1, 0 };
        int[] vy = new int[] { 0, 1, 0, -1 };
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == c)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int y = i + vy[k];
                        int x = j + vx[k];
                        if (y < 0 || y >= h) continue;
                        if (x < 0 || x >= w) continue;
                        dic[board[y][x]] = 1;
                    }
                }
            }
        }
        Console.WriteLine(dic.Count - 2);
    }
}
