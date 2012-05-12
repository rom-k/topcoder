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

class STable {
public:
	string getString(string s, string t, long long pos) {
		string ret;
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ad"; string Arg1 = "cb"; long long Arg2 = 0LL; string Arg3 = "acbacd"; verify_case(0, Arg3, getString(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "fox"; string Arg1 = "cat"; long long Arg2 = 0LL; string Arg3 = "acfcfoacftacfcfocfox"; verify_case(1, Arg3, getString(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "Ra6b1t"; string Arg1 = "W0lf"; long long Arg2 = 66LL; string Arg3 = "RWab0RWRWa0RWl0RWRWa6RWa0RWRWa6RWa6RWab0RWRWa6RWa6"; verify_case(2, Arg3, getString(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "M0HAXG"; string Arg1 = "COFU12"; long long Arg2 = 919LL; string Arg3 = "MOFU2"; verify_case(3, Arg3, getString(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "a0B1c2D3e4F5gHiJkLmN"; string Arg1 = "A9b8C7d6EfGhIjKlMn"; long long Arg2 = 9876543210LL; string Arg3 = "B10AaB1c0Aa9Aa0AaB0AaB10AaB1c0AaB1c20Aa9Aa0AaB0Aa9"; verify_case(4, Arg3, getString(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "TCOR2"; string Arg1 = "MEDiUm"; long long Arg2 = 350LL; string Arg3 = "MTDEMTiCMTEMTDEMTDEMTiDEMTiUCMTEMTCMTOCMTEMTDEMTCM"; verify_case(5, Arg3, getString(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	STable ___test;
	___test.run_test(-1);
}
// END CUT HERE
