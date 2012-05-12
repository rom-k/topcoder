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

string _cng_fmt(int n, int b) {
    string chars = "0123456789ABCDEFGHIJ";
    string ret = "";
    while(n > 0) {
        ret = chars[n % b] + ret;
        n /= b;
    }
    return ret;
}

class ToastXToast {
public:
//	int calc_gcd(vector <int> a) {
//		return _gcd(a);
//	}

// BEGIN CUT HERE
public:
	void run_test() {
		int a;
		
		a = 10;
		cout <<a <<" => " <<_cng_fmt(a, 2) <<", " <<_cng_fmt(a, 16) <<endl;
	}
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ToastXToast ___test;
	___test.run_test();
}
// END CUT HERE
