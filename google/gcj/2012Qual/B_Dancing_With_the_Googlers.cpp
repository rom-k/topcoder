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

int main() {
    int T;
    cin >>T;
    cin.ignore();
    
    for(int t=1; t<=T; t++) {
        
        int N, S, p;
        cin >>N >>S >>p;
        //getline(cin, a);
        
        vector<int> tt(N, 0);
        FORI(i, N) cin >>tt[i];
        
        int ret = 0;
        int ret_if = 0;
        
        FORI(i, N) {
            int mod = tt[i] % 3;
            int max = tt[i] / 3 + (mod == 0 ? 0 : 1);
            if      (max >= p                              ) { ret++;    }
            else if (max == p-1 and mod != 1 and tt[i] != 0) { ret_if++; }
        }
        
        ret += min(ret_if, S);
        
        cout <<"Case #" <<t <<": " <<ret <<endl;
        //printf("Case #%d: %.0lf\n", t, ret);
    }
    
    return 0;
}
