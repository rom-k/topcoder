//#include <iostream> /*debug*/
#include <vector>
#include <algorithm>
#include "grader.h"
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)

struct edge { int u, v; LL cost; };

bool comp_init(const edge& e1, const edge& e2) {
    if (e1.u != e2.u) return e1.u < e2.u;
    if (e1.v != e2.v) return e1.v < e2.v;
    return e1.cost < e2.cost;
}

bool comp_cost (const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

/* union find */
#define MAX_N 100005
int par[MAX_N];
int rank[MAX_N];
void init_uf(int n) {
    for (int i=0;i<n;i++) { par[i]=i; rank[i]=0; }
}
int find_uf(int x) {
    if (par[x]==x) return x;
    else           return par[x]=find_uf(par[x]);
}
void unite_uf(int x, int y) {
    x = find_uf(x); y = find_uf(y);
    if      (x==y)            return;
    else if (rank[x]<rank[y]) par[x]=y;
    else if (rank[x]>rank[y]) par[y]=x;
    else                    { par[y]=x; rank[x]++; }
}
bool same_uf(int x, int y) {
    return find_uf(x)==find_uf(y);
}

void construct(int N, int M, int E[][3]) {
    /* init */
    vector<edge> es, es_all;
    REP(j,M) {
        edge e;
        e.u    = E[j][0];
        e.v    = E[j][1];
        e.cost = E[j][2];
        es_all.push_back(e);
    }
    sort(es_all.begin(), es_all.end(), comp_init);

    for(int i=1;i<N;i++) {
        /* add new edge */
        REP(j,es_all.size()) {
            edge e = es_all[j];
            if      (i==e.v) es.push_back(e);
            else if (i<=e.u) break;
        }
        sort(es.begin(), es.end(), comp_cost);

        /* prepare union find */
        init_uf(i+1);

        /* kruskal */
        int j, cnt = 0;
        LL prev = -1;
        LL ret = 0LL;
        for (j=0;j<es.size();j++) {
            edge e = es[j];
            if (!same_uf(e.u, e.v)) {
                unite_uf(e.u, e.v);
                ret += e.cost;
                prev = e.cost;
                if(++cnt == i) break;
            }
            else if (prev != e.cost) {
                es.erase(es.begin()+j);
                j--;
            }
        }
        if (++j<es.size()) es.erase(es.begin()+j, es.end());
        if (cnt != i) ret = -1;

        answer(ret);
    }
}

