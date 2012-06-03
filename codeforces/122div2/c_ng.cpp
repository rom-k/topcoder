#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >>n >>m;
    string s[n];
    for (int i=0;i<n;i++) cin >>s[i];

    int ret = 2;
    int num_of_color = 0;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = { 0,-1, 0, 1};
    for (int y=0;y<n;y++) for (int x=0;x<m;x++) {
        if (s[y][x] != '#') continue;

        num_of_color++;
        int num = 0;
        for (int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx and nx <= m-1
            and 0 <= ny and ny <= n-1
            and s[ny][nx] == '#') num++;
        }
        if (num <= 1) ret = 1;
    }
    if (num_of_color - ret <= 1) ret = -1;

    cout <<ret <<endl;
    return 0;
}
