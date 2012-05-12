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

class FoxIntegerLevelThree {
public:
	long long count(long long min, long long max) {
		long long ret = 0;
//		FORIS(x, min, max+1) {
//			if((x % 1 == 0 and (x / 1) % 9 == 1)
//			or (x % 2 == 0 and (x / 2) % 9 == 2)
//			or (x % 3 == 0 and (x / 3) % 9 == 3)
//			or (x % 4 == 0 and (x / 4) % 9 == 4)
//			or (x % 5 == 0 and (x / 5) % 9 == 5)
//			or (x % 6 == 0 and (x / 6) % 9 == 6)
//			or (x % 7 == 0 and (x / 7) % 9 == 7)
//			or (x % 8 == 0 and (x / 8) % 9 == 8)
//			or (x % 9 == 0 and (x / 9) % 9 == 0)
//			) {
//				ret++;
//			}
//		}
		FORIS(n, 1, 9+1) {
			LL c = (n == 9) ? 0 : (LL)pow((double)n, 2.);
			LL num_max = (max < c) ? 0 : (max - c) / (9 * n);
			LL num_min = (min - 1 < c) ? 0 : (min - 1 - c) / (9 * n);
			DBG2("c",c);
			DBG2("num_max",num_max);
			DBG2("num_min",num_min);
			ret += num_max - num_min;
			//ret += (LL)((double)(max - c) / n / 9 + 1) - (LL)((double)(min - c - 1) / n / 9 + 1);
		}
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; long long Arg1 = 16LL; long long Arg2 = 2LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 123LL; long long Arg1 = 123LL; long long Arg2 = 0LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 160LL; long long Arg1 = 160LL; long long Arg2 = 1LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 47LL; long long Arg1 = 58LL; long long Arg2 = 4LL; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 123456789LL; long long Arg1 = 9876543210LL; long long Arg2 = 2618024258LL; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FoxIntegerLevelThree ___test;
	___test.run_test(-1);
}
// END CUT HERE
