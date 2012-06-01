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
#define PB(n) push_back(n)
#define PI M_PI
#define EPS 1e-13

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

int _is_prime1(int n) {
    if (n     <= 1) return false;
    if (n     == 2) return true;
    if (n % 2 == 0) return false;

    int m = (int) sqrt(n);
    for (int i=3; i<=m; i+=2) 
        if (n%i == 0) return false;

    return true;
}

//    vector<bool> sieve(1000);
//    _is_prime2(sieve);
void _is_prime2(vector<bool>& sieve) {
    int n = sieve.size() - 1;
    for (int i=0; i<n+1; i++)
        sieve[i] = true;

    sieve[0] = false;
    sieve[1] = false;

    int m = (int) sqrt(n);
    for (int i=2; i<=m; i++)
        if (sieve[i])
            for (int k=i*i; k<=n; k+=i)
                sieve[k] = false;

    return;
}

set<int> s;
bool _is_pandegital(int n) {
    s.clear();
    while (n > 0) {
        if (s.find(n % 10) != s.end()) return false;
        s.insert(n % 10);
        n /= 10;
    }
    int i = 1;
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
        if (*it != i++) return false;
    return true;
}

int main() {
    int ret = 87654321;

    vector<bool> s(ret, false);
    _is_prime2(s);
    while (1) {
        if (s[ret] and _is_pandegital(ret)) break;
        ret--;
    }
    cout <<ret <<endl;
    return 0;
}
