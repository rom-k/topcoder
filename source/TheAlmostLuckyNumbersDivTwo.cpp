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

class TheAlmostLuckyNumbersDivTwo {
public:
	LL cnt;
	LL a;
	LL b;
	
	void dfs(LL n, LL flag) {
		if (b < n) return;
		if (a <= n) cnt++;
		
		if(flag == 1) {
			dfs(n * 10 + 4, 1);
			dfs(n * 10 + 7, 1);
		}
		else {
			if (n != 0)
				dfs(n * 10 + 0, 1);
			dfs(n * 10 + 1, 1);
			dfs(n * 10 + 2, 1);
			dfs(n * 10 + 3, 1);
			dfs(n * 10 + 4, 0);
			dfs(n * 10 + 5, 1);
			dfs(n * 10 + 6, 1);
			dfs(n * 10 + 7, 0);
			dfs(n * 10 + 8, 1);
			dfs(n * 10 + 9, 1);
		}
	}
	
	int find(int a0, int b0) {
		cnt = 0;
		a = a0; b = b0;
		dfs(0, 0);
		
		return cnt;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 4; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 19; int Arg2 = 4; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 28; int Arg1 = 33; int Arg2 = 0; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1234; int Arg1 = 4321; int Arg2 = 36; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheAlmostLuckyNumbersDivTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
