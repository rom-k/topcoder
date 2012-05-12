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

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

class MuddyRoad {
public:
	double getExpectedValue(vector <int> road) {
		int N = SZ(road);
		
		vector<double> dp(N, 0.);
		dp[0] = 0.;
		
		double ret = 0.;
		FORIS(i, 1, N) {
			dp[i] = (1-dp[i-1]) * road[i] * .01;
			ret  +=    dp[i-1]  * road[i] * .01;
		}
		
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 60, 60, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.36; verify_case(0, Arg1, getExpectedValue(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 50, 50, 50, 50, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.5625; verify_case(1, Arg1, getExpectedValue(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 0, 100, 100, 100, 100, 100, 100, 0, 0, 100, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0; verify_case(2, Arg1, getExpectedValue(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 12, 34, 56, 78, 91, 23, 45, 67, 89, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.7352539420031923; verify_case(3, Arg1, getExpectedValue(Arg0)); }
	void test_case_4() { int Arr0[] = {0, 50, 50, 100, 50, 100, 50, 50, 100, 66, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 2.288125; verify_case(4, Arg1, getExpectedValue(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MuddyRoad ___test;
	___test.run_test(-1);
}
// END CUT HERE
