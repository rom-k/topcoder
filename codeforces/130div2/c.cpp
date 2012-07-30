#include <stdio.h>
#include <iostream>
#include <set>
#include <stack>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int n, m;
bool a[105][105];
int k[105];
int minpath;
bool curpath[105];
stack<int> path;

void dfs(int cur) {
    curpath[cur] = true;
    if (cur==n-1) {
        REP(i,n) if(curpath[i]) k[i]++;
    }
    if (path.size()<minpath+1) {
        REP(i,n) if (a[cur][i] and !curpath[i]) dfs(i);
    }
    curpath[cur] = false;
}

int main() {
    cin >>n >>m;
    REP(i,n)REP(j,n) a[i][j] = false;
    REP(i,m) {
        int u, v;
        cin >>u >>v;
        a[u-1][v-1] = a[v-1][u-1] = true;
    }

    /* bfs */
    set<pair<int,int> > spii; /* path-len, node-num */
    spii.insert(pair<int,int>(0,0));
    int len[n];
    REP(i,n) len[i] = -1;
    while (!spii.empty()) {
        set<pair<int,int> >::iterator it = spii.begin();
        int l = (*it).first;
        int i = (*it).second;
        spii.erase(it);
        len[i] = l;
        if (i==n-1) break;
        REP(j,n) if (len[j]<0 and a[i][j])
            spii.insert(pair<int,int>(l+1,j));
    }
    minpath = len[n-1];

    /* dfs */
    REP(i,n) k[i] = 0;
    REP(i,n) curpath[i] = false;
    dfs(0);

    int ret = k[0];
    REPS(i,1,n-1) ret = max(ret, 2*k[i]);
    printf("%.12lf\n", (double)ret/k[0]);

    return 0;
}
