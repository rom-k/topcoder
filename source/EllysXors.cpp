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
#define DBG3(a, b, c) if (DEBUG) cout <<"DEBUG::: " <<a <<":" <<b <<":" <<c <<endl;

LL _xor(LL a) {
    if(a==1) return 1;
    LL b = ((LL)(a/4))*4;
    LL ret = 0;
    for (LL i=b;i<=a;i++) {
        ret ^= i;
    }
    return ret;
}

class EllysXors {
public:
    LL getXor(LL L, LL R) {
    if (L==R) return R;
    return _xor(L-1) ^ _xor(R);
    }
;

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 10LL; long long Arg2 = 8LL; verify_case(0, Arg2, getXor(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 5LL; long long Arg1 = 5LL; long long Arg2 = 5LL; verify_case(1, Arg2, getXor(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 13LL; long long Arg1 = 42LL; long long Arg2 = 39LL; verify_case(2, Arg2, getXor(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 666LL; long long Arg1 = 1337LL; long long Arg2 = 0LL; verify_case(3, Arg2, getXor(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 1234567LL; long long Arg1 = 89101112LL; long long Arg2 = 89998783LL; verify_case(4, Arg2, getXor(Arg0, Arg1)); }
	void test_case_5() { long long Arg0 = 1LL; long long Arg1 = 4000000000LL; long long Arg2 = 0LL; verify_case(5, Arg2, getXor(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    EllysXors ___test;
    ___test.run_test(-1);
}
// END CUT HERE
