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

int _gcd(vector<int> a) {
	int ret = a[0];
	for(int i=1; i<a.size(); i++)
		ret = _gcd2(ret, a[i]);
	return ret;
}

int _lcm2(int a, int b) {
	return b * a / _gcd2(a, b);
}

int _lcm(vector<int> a) {
	int ret = a[0];
	for(int i=1; i<a.size(); i++)
		ret = _lcm2(ret, a[i]);
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
		vector <int> a;
		
		a.push_back(2); a.push_back(6); a.push_back(15);
		for(int i=0; i<a.size(); i++) { cout <<a[i] <<" "; }
		cout <<"=> " <<_gcd(a) <<", " <<_lcm(a) <<endl;
		a.clear();
		
		a.push_back(2336); a.push_back(1314);
		for(int i=0; i<a.size(); i++) { cout <<a[i] <<" "; }
		cout <<"=> " <<_gcd(a) <<", " <<_lcm(a) <<endl;
		
		a.push_back(1314);
		for(int i=0; i<a.size(); i++) { cout <<a[i] <<" "; }
		cout <<"=> " <<_gcd(a) <<", " <<_lcm(a) <<endl;
		
		a.push_back(18031);
		for(int i=0; i<a.size(); i++) { cout <<a[i] <<" "; }
		cout <<"=> " <<_gcd(a) <<", " <<_lcm(a) <<endl;
	}
// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ToastXToast ___test;
	___test.run_test();
}
// END CUT HERE
