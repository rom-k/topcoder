#include <iostream>
using namespace std;

#define MAX_SZ 25
int z[MAX_SZ][MAX_SZ];
int s[MAX_SZ][MAX_SZ];
int w, h, sum;

void dfs(int x, int y) {
    if (s[y][x] == 0) {
        s[y][x]++;
        sum++;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = { 0,-1, 0, 1};
        for (int i=0;i<4;i++) {
            if (0 <= x+dx[i] and x+dx[i] < w
            and 0 <= y+dy[i] and y+dy[i] < h
            and z[y+dy[i]][x+dx[i]] < z[y][x]) {
                dfs(x+dx[i], y+dy[i]);
            }
        }
    }
}

int main() {
    while(1) {
        int p;
        cin >>w >>h >> p;
        if (w==0 and h==0 and p==0) break;

        for (int y=0;y<h;y++)
            for (int x=0;x<w;x++) {
                cin >>z[y][x];
                s[y][x] = 0;
            }

        sum = 0;
        for (int i=0;i<p;i++) {
            int x0, y0;
            cin >>x0 >>y0;
            dfs(x0, y0);
        }

        cout <<sum <<endl;
    }
    return 0;
}
