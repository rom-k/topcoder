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
        int h = cin.nextInt();
        int w = cin.nextInt();
        char c = cin.next().charAt(0);
        String[] board = new String[h];
        for (int i = 0; i < h; i++)
        {
            board[i] = cin.next();
        }
        Map<Character, Integer> dic = new HashMap<Character, Integer>();
        dic.put('.', 1);
        dic.put(c, 1);
        int[] vx = { 1, 0, -1, 0 };
        int[] vy = { 0, 1, 0, -1 };
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i].charAt(j) == c)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int y = i + vy[k];
                        int x = j + vx[k];
                        if (y < 0 || y >= h) continue;
                        if (x < 0 || x >= w) continue;
                        dic.put(board[y].charAt(x), 1);
                    }
                }
            }
        }
        System.out.println(dic.size() - 2);
    }
}
