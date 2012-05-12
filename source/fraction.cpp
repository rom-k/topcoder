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

int _gcd2(int a, int b) {
	if (a < b) { int c = a; a = b; b = c; }
    if (b == 0) return a;
    return _gcd2(b, a%b);
}

int _lcm2(int a, int b) {
	return b * a / _gcd2(a, b);
}

vector<int> addFractions(vector<int> a, vector<int> b)
{
     vector<int> c;
     int denom = _lcm2(a[1], b[1]);
     c.PB(denom / a[1] * a[0] + denom / b[1] * b[0]);
     c.PB(denom);
     return c;
}

vector<int> subtractFractions(vector<int> a, vector<int> b)
{
     vector<int> d;
     d.PB(- b[0]);
     d.PB(b[1]);
     return addFractions(a, d);
}

vector<int> multiplyFractions(vector<int> a, vector<int> b)
{
     vector<int> c;
     c.PB(a[0] * b[0]);
     c.PB(a[1] * b[1]);
     
     int gcd = _gcd2(c[0], c[1]);
     c[0] /= gcd;
     c[1] /= gcd;
     return c;
}

vector<int> divideFractions(vector<int> a, vector<int> b)
{
     vector<int> d;
     d.PB(b[1]);
     d.PB(b[0]);
     return multiplyFractions(a, d);
}

class ToastXToast {
public:
//	int calc_gcd(vector <int> a) {
//		return _gcd(a);
//	}

// BEGIN CUT HERE
public:
	void run_test() {
		vector<int> a;
		vector<int> b;
		vector<int> add;
		vector<int> sub;
		vector<int> mul;
		vector<int> div;
		
		a.PB(4); a.PB(9);
		b.PB(1); b.PB(6);
		add = addFractions(a,b);
		sub = subtractFractions(a,b);
		mul = multiplyFractions(a,b);
		div = divideFractions(a,b);
		cout <<a[0] <<"/" <<a[1] <<" +-*/ " <<b[0] <<"/" <<b[1] <<endl;
		cout <<"add => " <<add[0] <<"/" <<add[1] <<endl;
		cout <<"sub => " <<sub[0] <<"/" <<sub[1] <<endl;
		cout <<"mul => " <<mul[0] <<"/" <<mul[1] <<endl;
		cout <<"div => " <<div[0] <<"/" <<div[1] <<endl;
	}
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ToastXToast ___test;
	___test.run_test();
}
// END CUT HERE
