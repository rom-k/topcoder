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

class KingXNewCurrency {
public:
    int howMany(int A, int B, int X) {
        
        if (A % X == 0 && B % X == 0) return -1;
        if (A > B) { int C=A; A=B; B=C; }
        
        int Y = 0;
        
        
        return Y;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 8; int Arg2 = 5; int Arg3 = 5; verify_case(0, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 8; int Arg1 = 4; int Arg2 = 2; int Arg3 = -1; verify_case(1, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 4; int Arg2 = 13; int Arg3 = 1; verify_case(2, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 74; int Arg2 = 44; int Arg3 = 2; verify_case(3, Arg3, howMany(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 128; int Arg1 = 96; int Arg2 = 3; int Arg3 = 65; verify_case(4, Arg3, howMany(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    KingXNewCurrency ___test;
    ___test.run_test(-1);
}
// END CUT HERE
