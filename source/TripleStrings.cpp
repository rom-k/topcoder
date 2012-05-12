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

class TripleStrings {
public:
	int getMinimumOperations(string init, string goal) {
		int N = SZ(init);
		int i;
		for(i = 0; i<N; i++) {
			bool ok = true;
			FORI(j, N-i) {
				if(init[i+j] != goal[j]) {
					ok = false;
					break;
				}
			}
			if(ok) break;
		}
		return i*2;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ooxxox"; string Arg1 = "xoxoxo"; int Arg2 = 6; verify_case(0, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "oooxxoo"; string Arg1 = "oooxxoo"; int Arg2 = 0; verify_case(1, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "ox"; string Arg1 = "xo"; int Arg2 = 2; verify_case(2, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ooxxooxx"; string Arg1 = "xxoxoxoo"; int Arg2 = 12; verify_case(3, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "oxxoxxoooxooooxxxoo"; string Arg1 = "oxooooxxxooooxoxxxo"; int Arg2 = 16; verify_case(4, Arg2, getMinimumOperations(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "xxxoxoxxooxooxoxooo"; string Arg1 = "oxxooxxooxxoxoxooxo"; int Arg2 = 36; verify_case(5, Arg2, getMinimumOperations(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TripleStrings ___test;
	___test.run_test(-1);
}
// END CUT HERE
