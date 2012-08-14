#include <iostream>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

#define MAX_N 205;
int par[MAX_N];
int rank[MAX_N];

void init(int n) {
    REP(i,n) {par[i]=i; rank[i]=0;}
}
int find(int x) {
    if (par[x]==x) return x;
    else return par[x] = find(par[x]);
}
void unite(int x, int y) {
    x = find(x); y = find(y);
    if (x==y) return;
    if (rank[x] < rank[y]) {par[x]=y;}
    else {par[y]=x; if(rank[x]==rank[y]) rank[x]++;}
}
bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int n, m;
    cin >>n >>m;
    init(n*2);
    //NG
    return 0;
}
