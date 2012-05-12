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

class NetworkXZeroOne {
public:
	string reconstruct(string message) {
		string ret = message;
		FORI(i, SZ(ret)-1) {
			if(ret[i+0] == 'x' and ret[i+1] == '?') ret[i+1] = 'o';
			if(ret[i+0] == 'o' and ret[i+1] == '?') ret[i+1] = 'x';
		}
		for(int i = SZ(ret)-1; i>=0; i--) {
			if(ret[i+0] == '?' and ret[i+1] == 'x') ret[i+0] = 'o';
			if(ret[i+0] == '?' and ret[i+1] == 'o') ret[i+0] = 'x';
		}
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "x?x?"; string Arg1 = "xoxo"; verify_case(0, Arg1, reconstruct(Arg0)); }
	void test_case_1() { string Arg0 = "?xo?"; string Arg1 = "oxox"; verify_case(1, Arg1, reconstruct(Arg0)); }
	void test_case_2() { string Arg0 = "xo"; string Arg1 = "xo"; verify_case(2, Arg1, reconstruct(Arg0)); }
	void test_case_3() { string Arg0 = "o??x??o"; string Arg1 = "oxoxoxo"; verify_case(3, Arg1, reconstruct(Arg0)); }
	void test_case_4() { string Arg0 = "???????x"; string Arg1 = "oxoxoxox"; verify_case(4, Arg1, reconstruct(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NetworkXZeroOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
