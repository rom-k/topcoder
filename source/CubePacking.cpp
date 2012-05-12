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

class CubePacking {
public:
	int getMinimumVolume(int Ns, int Nl, int L) {
		
		//LL MAX = 1006;
		//LL MAX_1 = 1259;
		//LL MAX_2 = 31638;
		
		LL ret = (LL)1e11;
		LL all = Ns + Nl * L * L * L;
		LL MAX_1 = (LL) pow(all, 1. / 3.) + 1;
		LL MAX_2 = (LL) pow(all, 1. / 2.) + 1;
		
		FORIS(x, L, MAX_1) FORIS(y, L, MAX_2) {
			LL min_z_by_l = (LL) Nl / (x * y / L / L) * L;
			if((LL) Nl % (x * y / L / L) != 0) min_z_by_l += L;
			
			LL min_z_by_all = all / (x * y);
			if(all % (x * y) != 0) min_z_by_all++;
			
			ret = min(ret, x * y * max(min_z_by_l, min_z_by_all));
			
			if(ret == all) break;
		}
		
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 99)) test_case_99(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 20; verify_case(0, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 19; int Arg1 = 1; int Arg2 = 2; int Arg3 = 27; verify_case(1, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 51; int Arg1 = 7; int Arg2 = 5; int Arg3 = 950; verify_case(2, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 12345; int Arg1 = 987; int Arg2 = 10; int Arg3 = 999400; verify_case(3, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 87549617; int Arg1 = 866889; int Arg2 = 10; int Arg3 = 954438617; verify_case(6, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }
	void test_case_99() { int Arg0 = 27243729; int Arg1 = 1000000; int Arg2 = 10; int Arg3 = 1027243729; verify_case(99, Arg3, getMinimumVolume(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CubePacking ___test;
	___test.run_test(-1);
}
// END CUT HERE
