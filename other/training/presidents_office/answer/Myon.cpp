#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int h;
    int w;
    char c;
    cin >> h >> w >> c;
    string board[h];
    for (int i = 0; i < h; i++)
    {
        cin >> board[i];
    }
    map<char, int> dic;
    dic['.'] = 1;
    dic[c] = 1;
    int vx[4] = { 1, 0, -1, 0 };
    int vy[4] = { 0, 1, 0, -1 };
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
    cout << dic.size() - 2 << endl;
    return 0;
}
