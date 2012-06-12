#include <iostream>
using namespace std;
typedef long long LL;

#define MAXN 1505
int n, m;
string mz[MAXN];
LL moved[MAXN][MAXN];
int dx[] = {-1, 0, 1, 0};
int dy[] = { 0,-1, 0, 1};

bool dfs(int x, int y, int px, int py) {
    LL s = moved[y][x];
    for (int i=0;i<4;i++) {
        int nx = (x+dx[i]+m) % m;
        int ny = (y+dy[i]+n) % n;
        if (nx == px and ny == py) continue;
        if (mz[ny][nx] == '#') continue;

        LL ns = s;
//        if (nx != x+dx[i] or ny != y+dy[i]) ns++;
        if (dx[i] ==  1 and nx == 0  ) ns++;
        if (dx[i] == -1 and nx == m-1) ns--;
        if (dy[i] ==  1 and ny == 0  ) ns+=MAXN;
        if (dy[i] == -1 and ny == n-1) ns-=MAXN;
        if (moved[ny][nx] == ns) continue;
        if (0 != moved[ny][nx]) return true;

        moved[ny][nx] = ns;
        if (dfs(nx,ny,x,y)) return true;
    }
    return false;
}

int main() {
    cin >>n >>m;
    for (int i=0;i<n;i++) cin >>mz[i];

    for (int i=0;i<n;i++) for (int j=0;j<m;j++)
        moved[i][j] = 0;
    int x, y;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++)
        if (mz[i][j] == 'S') x = j, y = i;
//    moved[y][x] = 1;

    if (dfs(x,y,-1,-1)) cout <<"Yes" <<endl;
    else                cout <<"No" <<endl;

    return 0;
}
