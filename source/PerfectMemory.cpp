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

class PerfectMemory {
public:
	double getExpectation(int N, int M) {
		
		int max = 2505;
		
		//2-dimensional vector filled with 0.
		vector<vector<double> > dp(max, vector<double>(max, 0.));
		dp[0][0] = 0.;
		dp[1][1] = 1.;
		
		FORIS(x0, 2, max) FORIS(y0, 2, max/2) {
			double x = (double)x0;
			double y = (double)y0;
			double z = 0.;
			double p = 1.;
			DBG2("x",x);
			DBG2("y",y);
			
			if(0 < y and 0 < x) {
				DBG2(" 1: ",    dp[x0 - 1][y0 - 1] + 1);
				z += (y / x) * (dp[x0 - 1][y0 - 1] + 1);
				p -= (y / x);
			}
			if (x - y >= 4) {
				DBG2(" 2: ",                    dp[x0 - 2][y0 + 2] + 1);
				z += (p * (x - 2) / (x - 1)) * (dp[x0 - 2][y0 + 2] + 1);
				p -= (p * (x - 2) / (x - 1));
			}
			DBG2(" 3: ", dp[x0 - 2][y0] + 1);
			z += p * (dp[x0 - 2][y0] + 1);
		}
		
		return dp[N*M][0];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 2.6666666666666665; verify_case(1, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; double Arg2 = 4.333333333333334; verify_case(2, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; double Arg2 = 12.392984792984793; verify_case(3, Arg2, getExpectation(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PerfectMemory ___test;
	___test.run_test(-1);
}
// END CUT HERE
