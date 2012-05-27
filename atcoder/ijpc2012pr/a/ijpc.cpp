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

bool check(int N, char S[], string C) {
    int x = 0;
    FORI(i,N) {
        if (C[x] == '.'
        or  C[x] == S[i]) {
            x++;
        }
        if (x >= 4) {
            return true;
        }
    }
    return false;
}

int replace(int N, char S[]) {
    if(check(N, S, "IJPC")) return 0;
    if(check(N, S, ".JPC")) return 1;
    if(check(N, S, "I.PC")) return 1;
    if(check(N, S, "IJ.C")) return 1;
    if(check(N, S, "IJP.")) return 1;
    if(check(N, S, "..PC")) return 2;
    if(check(N, S, ".J.C")) return 2;
    if(check(N, S, ".JP.")) return 2;
    if(check(N, S, "I..C")) return 2;
    if(check(N, S, "I.P.")) return 2;
    if(check(N, S, "IJ..")) return 2;
    if(check(N, S, "...C")) return 3;
    if(check(N, S, "..P.")) return 3;
    if(check(N, S, ".J..")) return 3;
    if(check(N, S, "I...")) return 3;
    return 4;
}

