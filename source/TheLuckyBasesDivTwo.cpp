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

class TheLuckyBasesDivTwo {
public:
	bool base(LL n0, LL j) {
		LL n = n0;
		
		while(n != 4 and n != 7) {
			DBG2("  n'",n);
			if(n % j == 4 or n % j == 7) {
				n /= j;
			}
			else {
				return false;
			}
		}
		
		DBG("  return true")
		return true;
	}
	
	long long find(long long n) {
		
		if (n == 4 or n == 7) return -1;
		
		LL ret = 0;
		VL a;
		a.PB(4);
		a.PB(7);
		
		FORI(i, SZ(a)) {
			LL m = n - a[i];
			DBG2("i",i);
			DBG2("m",m);
			FORIS(j, 1, (LL)sqrt(m) + 1) {
				if (m % j == 0) {
					DBG2("j",j);
					if (base(n, j)) ret++;
					DBG2(" ->",ret);
					DBG2("m/j",m/j);
					if (m/j != j and base(n, m/j)) ret++;
					DBG2(" ->",ret);
				}
			}
		}
		
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 91)) test_case_91(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 255LL; long long Arg1 = 1LL; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { long long Arg0 = 4LL; long long Arg1 = -1LL; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { long long Arg0 = 13LL; long long Arg1 = 0LL; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { long long Arg0 = 60LL; long long Arg1 = 2LL; verify_case(3, Arg1, find(Arg0)); }
	void test_case_91() { long long Arg0 = 1684LL; long long Arg1 = 4LL; verify_case(91, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheLuckyBasesDivTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
