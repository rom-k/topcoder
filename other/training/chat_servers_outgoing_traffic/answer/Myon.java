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
        int member = 0;
        int ret = 0;
        while (true)
        {
            String s = cin.hasNextLine() ? cin.nextLine() : "";
            if (s.length() == 0) break;
            String[] st = s.split(":");
            if (st.length == 1)
            {
                if (s.charAt(0) == '+') member++;
                else if (s.charAt(0) == '-') member--;
            }
            else
            {
                ret += member * st[1].length();
            }
            
        }
        System.out.println(ret);
    }
}
