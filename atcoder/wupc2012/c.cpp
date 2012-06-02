#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,M;
vector<string> mp;

int bfs(int x1, int y1, int x2, int y2) {
    queue<pair<int,int> > q;
    q.push(pair<int,int>(x1,y1));

    vector<vector<int> > step(N, vector<int>(M, -1));
    step[y1][x1] = 0;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = { 0,-1, 0, 1};

    bool end = false;
    while (0 < q.size() and !end) {
        pair<int,int> a = q.front(); q.pop();
        int x   = a.first;
        int y   = a.second;
        int stp = step[y][x];

        for (int i=0;i<4;i++) {
            int xn = x + dx[i];
            int yn = y + dy[i];
            if (mp[yn][xn] == '#') continue;
            if (step[yn][xn] > 0) continue;

            step[yn][xn] = stp + 1;
            q.push(pair<int,int>(xn,yn));

            if (xn == x2 and yn == y2) {
                end = true;
                break;
            }
        }
    }
    return step[y2][x2];
}

int main(void) {
    cin >>N >>M;
    mp.assign(N,"");
    for (int i=0;i<N;i++) cin >>mp[i];

    int xs, ys, xc, yc, xg, yg;
    for (int y=0;y<N;y++)
        for (int x=0;x<M;x++) {
            if (mp[y][x] == 'S') xs = x, ys = y;
            if (mp[y][x] == 'C') xc = x, yc = y;
            if (mp[y][x] == 'G') xg = x, yg = y;
        }

    int a = bfs(xs,ys,xc,yc);
    int b = bfs(xc,yc,xg,yg);
    int c = (a < 0 or b < 0) ? -1 : a + b;
    cout <<c <<endl;
    return 0;
}
