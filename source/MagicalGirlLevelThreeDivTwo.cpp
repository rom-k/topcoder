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

class MagicalGirlLevelThreeDivTwo {
public:
	int theCount(vector <string> first, int n, long long lo, long long hi) {
		int ret = 0;
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"101", "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 2LL; long long Arg3 = 5LL; int Arg4 = 2; verify_case(0, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; long long Arg2 = 4LL; long long Arg3 = 5LL; int Arg4 = 1; verify_case(1, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"1", "11", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; long long Arg2 = 10000LL; long long Arg3 = 11000LL; int Arg4 = 1001; verify_case(2, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"0", "00", "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; long long Arg2 = 10000LL; long long Arg3 = 11000LL; int Arg4 = 0; verify_case(3, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"00110110101101001111101101001011010011111011010010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long long Arg2 = 999999999999915LL; long long Arg3 = 1000000000000000LL; int Arg4 = 50; verify_case(4, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arr0[] = {"10000", "011011001011000001101000010100000111000110110", 
"000001010001011000001101110", "100100000110100001010000", 
"011011010", "01100000010101101110000011100011001000",
"0001010", "010011000", "000101001", "00", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 91; long long Arg2 = 123456LL; long long Arg3 = 123654LL; int Arg4 = 76; verify_case(5, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MagicalGirlLevelThreeDivTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
