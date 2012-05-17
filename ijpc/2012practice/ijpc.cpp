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

#define DEBUG 0
#define DBG(a)        if(DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b)    if(DEBUG) cout <<"DEBUG::: " <<a <<":" <<b <<endl;
#define DBG3(a, b, c) if(DEBUG) cout <<"DEBUG::: " <<a <<":" <<b <<":" <<c <<endl;

string SS;
int NN;

int dfs(int i, string need, int skipped) {
    if (i >= NN) {
        if (SZ(need) > skipped) {
            return INF;
        }
        else {
            return SZ(need);
        }
    }
    else {
        int ret = dfs(i+1, need, skipped+1);
        FORI(j, SZ(need)) {
            if(SS[i] == need[j]
            and j <= skipped
            and j < ret) {
                ret = min(ret, dfs(i+1, need.substr(j+1), 0) + j);
            }
        }
        return ret;
    }
}

int replace(int N, char S[]) {
    NN = N;
    SS = S;
    return dfs(0, "IJPC", 0);
}
