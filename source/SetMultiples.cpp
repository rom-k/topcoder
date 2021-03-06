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

class SetMultiples {
public:
	long long smallestSubset(long long A, long long B, long long C, long long D) {
//		vector<bool> flag(D+1, true);
//		flag[1] = false;
		
		long long ret = B - A + D - C + 2;
		for(LL i = A; i < D - C + B + 2; i++) {
			//LL j = i;
			//if (j > B) { j += C - B - 1; }
			//
			//if (j == 1) continue;
			//
			//for(LL k = 2; k <= 5 * 1e9; k++) {
			//	if (A <= k * j <= B) {
			//		ret--; break;
			//	}
			//	if (C <= k * j <= D) {
			//		ret--; break;
			//	}
			//	if (D < k * j) {
			//		break;
			//	}
			//}
		}
		
//		LL ret = 0;
//		FORIS(i, A, B+1) if(flag[i]) ret++;
//		FORIS(i, C, D+1) if(flag[i]) ret++;
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 2LL; long long Arg3 = 2LL; long long Arg4 = 1LL; verify_case(0, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; long long Arg3 = 4LL; long long Arg4 = 2LL; verify_case(1, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 2LL; long long Arg1 = 3LL; long long Arg2 = 5LL; long long Arg3 = 7LL; long long Arg4 = 3LL; verify_case(2, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 10LL; long long Arg2 = 100LL; long long Arg3 = 1000LL; long long Arg4 = 500LL; verify_case(3, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 1000000000LL; long long Arg1 = 2000000000LL; long long Arg2 = 9000000000LL; long long Arg3 = 10000000000LL; long long Arg4 = 1254365078LL; verify_case(4, Arg4, smallestSubset(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SetMultiples ___test;
	___test.run_test(-1);
}
// END CUT HERE
