#include "animals.h"
#include <set>
#include <map>
using namespace std;

#define MAX_N 100000
int N;
map<int,int> n[MAX_N];

void _remove(int v) {
}

void init(int N0, int E[][2]) {
    N = N0;
    for (int i=0;i<N-1;i++) {
        int a = E[i][0];
        int b = E[i][1];
        n[a].insert(map<int,int>::value_type(b, -1));
        n[b].insert(map<int,int>::value_type(a, -1));
    }

    bool loop_flag = true;
    while (loop_flag) {
        loop_flag = false;
        for (int i=0;i<N;i++) {
            for (map<int,int>::iterator it=n[i].begin();it!=n[i].end();it++) {
                int j     = (*it).first;
                int j_num = (*it).second;
                if (j_num > 0) continue;

                int sum = 1;
                map<int,int>::iterator it2;
                for (it2=n[j].begin();it2!=n[j].end();it2++) {
                    int k     = (*it2).first;
                    int k_num = (*it2).second;
                    if (i == k) continue;
                    if (k_num < 0) break;
                    sum += k_num;
                }

                if (it2==n[j].end()) n[i][j] = sum;
                else loop_flag = true;
            }
        }
    }

}

void _reduce(int v, int from, int dec) {
    for (map<int,int>::iterator it=n[v].begin();it!=n[v].end();it++) {
        if ((*it).first != from) {
            _reduce((*it).first, v, dec);
        }
    }
    n[v][from] -= dec;
}

int query(int v) {
    for (map<int,int>::iterator it=n[v].begin();it!=n[v].end();it++) {
        int nei = (*it).first;
        _reduce(nei, v, n[nei][v]);
        n[v].erase(nei);
        n[nei].erase(v);
    }

    int ret = 0;
    for (int i=0;i<N;i++) {
        int ret1 = 1;
        for (map<int,int>::iterator it=n[i].begin();it!=n[i].end();it++) {
            ret1 += (*it).second;
        }
        ret = max(ret, ret1);
    }
    return ret;
}
