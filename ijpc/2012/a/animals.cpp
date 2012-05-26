#include "animals.h"
#include <set>
#include <vector>
using namespace std;

#define MAX_N 100000
int N;
struct cnode {
    int p;
    int size;
    set<int> cs;
};
vector<cnode> n;

int inittree(int id) {
    n[id].size = 1;
    for (set<int>::iterator it=n[id].cs.begin();it!=n[id].cs.end();it++) {
        int cid = *it;
        n[cid].p = id;
        n[cid].cs.erase(id);
        n[id].size += inittree(cid);
    }
    return n[id].size;
}

void update_size_parent(int id, int red) {
    n[id].size -= red;
    if (n[id].p < 0) return;
    update_size_parent(n[id].p, red);
}

void remove_node(int id) {
    for (set<int>::iterator it=n[id].cs.begin();it!=n[id].cs.end();it++) {
        int cid = *it;
        n[cid].p = -1;
    }
    n[id].cs.clear();

    if (n[id].p > 0) {
        n[n[id].p].cs.erase(id);
        update_size_parent(n[id].p, n[id].size);
    }
    n[id].p = -1;

    n[id].size = 1;
}

void init(int N0, int E[][2]) {
    N = N0;
    for (int i=0;i<N;i++) {
        cnode n1;
        n1.p = -1;
        n.push_back(n1);
    }
    for (int i=0;i<N-1;i++) {
        n[E[i][0]].cs.insert(E[i][1]);
        n[E[i][1]].cs.insert(E[i][0]);
    }
    inittree(0);
}

int query(int v) {
    remove_node(v);
    int ret = 0;
    for (int i=0;i<N;i++)
        if (n[i].p < 0)
            ret = max(ret, n[i].size);
    return ret;
}

