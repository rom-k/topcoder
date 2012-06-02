#include <stdio.h>
#include <time.h>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <stack>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <utility>
#include <memory>
#include <functional>
#include <complex>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL> VL;

#define FORE(it, c, T) for(T::iterator it = c.begin(); it != c.end(); it++)
#define FORI(i, n) for(int i = 0; i < (n); i++)
#define FORIS(i, s, n) for(int i = (s); i < (n); i++)
#define CLEAR(a) memset(a, 0, sizeof(a))
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define PB(n) push_back(n)
#define SZ(a) int((a).size())
#define IPOW(a,b) ((long long) pow((double)(a),(double)(b)))
#define PI M_PI
#define EPS 1e-13
#define INF 0x7f7f7f7f

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

#define n_MAX 1005
int n, m;
set<LL> c[n_MAX][n_MAX];

int main() {
    cin >>n >>m;
    FORI(i,m) {
        int f, t;
        LL c1;
        cin >>f >>t >>c1;
        c[f][t].insert(c1);
        c[t][f].insert(c1);
    }

    FORI(i,n) FORI(j,n) FORI(k,n) {
        if (i==j or j==k or k==i) continue;
        FORE(it1,c[i][j],set<LL>) FORE(it2,c[j][k],set<LL>) {
            LL l = (*it1) + (*it2);
            c[i][k].insert(l);
            c[k][i].insert(l);
        }
    }

    LL ret = INF;
    FORE(it,c[0][n-1],set<LL>) {
        LL k = (*it);
        while (k % 4 != 0 and k % 7 != 0) k += 2;
        ret = min(ret, k);
    }

    cout <<ret <<endl;
    return 0;
}
