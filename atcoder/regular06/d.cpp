#include <iostream>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

#define MAX_H 1005
#define MAX_W 1005

int h, w;
string c[MAX_H];
int num;
int a[MAX_H][MAX_W];

void dfs(int i, int j, int k) {
    a[i][j] = k;
    int di[] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dj[] = {-1, 0, 1,-1, 1,-1, 0, 1};
    REP(p,8) {
        if (c[i+di[p]][j+dj[p]]!='.'
        and a[i+di[p]][j+dj[p]]<0)
            dfs(i+di[p], j+dj[p], k);
    }
}

int main() {
    cin >>h >>w;
    REP(i,h) cin >>c[i];

    num = 0;
    REP(i,h)REP(j,w) a[i][j] = -1;
    REP(i,h)REP(j,w)
        if (c[i][j]!='.' and a[i][j]<0)
            dfs(i, j, num++);

    int numa, numb, numc;
    numa = numb = numc = 0;

    REP(k,num) {
        int l = w;
        int r = 0;
        int u = h;
        int d = 0;
        REP(i,h)REP(j,w) {
            if (a[i][j] != k) continue;
            l = min(l, j);
            r = max(r, j);
            u = min(u, i);
            d = max(d, i);
        }
        if (r==0) continue;

        int kado = 0;
        if (0 <= a[u][l]) kado++;
        if (0 <= a[d][l]) kado++;
        if (0 <= a[u][r]) kado++;
        if (0 <= a[d][r]) kado++;

        int naka = 0;
        if (0 <= a[(u+d)/2][(l+r)/2]) naka++;

        if      (kado==0) numc++;
        else if (naka==0) numa++;
        else              numb++;
    }

    cout <<numa <<" " <<numb <<" " <<numc <<endl;

    return 0;
}
