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
#define PI M_PI
#define EPS 1e-13

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

LL _gcd2(LL a, LL b) {
	if (a < b) { LL c = a; a = b; b = c; }
    if (b == 0) return a;
    return _gcd2(b, a%b);
}

LL _gcd(vector<LL> a) {
	LL ret = a[0];
	for(LL i=1; i<a.size(); i++)
		ret = _gcd2(ret, a[i]);
	return ret;
}

LL _lcm2(LL a, LL b) {
	return b * a / _gcd2(a, b);
}

LL _lcm(vector<LL> a) {
	LL ret = a[0];
	for(LL i=1; i<a.size(); i++)
		ret = _lcm2(ret, a[i]);
	return ret;
}

class AllButOneDivisor {
public:
	int getMinimum(vector <int> d) {
		int N = SZ(d);
		
		vector<LL> results;
		FORI(i, N) {
			DBG2("i",i);
			LL result = 1;
			FORI(j, N) {
				if(j==i) continue;
				result = _lcm2(result, d[j]);
				DBG2("  j",j);
				DBG2("  d[j]",d[j]);
				DBG2("  result",result);
			}
			if(result % d[i] != 0) {
				results.PB(result);
				DBG("  => OK");
			}
			else {
				DBG("  => NG");
			}
		}
		SORT(results);
		
		if(SZ(results) >= 1)
			return results[0];
		return -1;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,3,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, getMinimum(Arg0)); }
	void test_case_1() { int Arr0[] = {2,4,3,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(1, Arg1, getMinimum(Arg0)); }
	void test_case_2() { int Arr0[] = {3,2,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(2, Arg1, getMinimum(Arg0)); }
	void test_case_3() { int Arr0[] = {6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 360; verify_case(3, Arg1, getMinimum(Arg0)); }
	void test_case_4() { int Arr0[] = {10,6,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, getMinimum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AllButOneDivisor ___test;
	___test.run_test(-1);
}
// END CUT HERE
