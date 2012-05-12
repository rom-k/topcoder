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

class CountingSeries {
public:
    LL countThem(LL a, LL b, LL c, LL d, LL u) {
        
        LL ret = u >= a ? 1 + (u - a) / b : 0;
        
        LL i = c;
        if (d==1) {
            if ( c <= u ) ret++;
        }
        else {
            while(i <= u) {
                if ( i - a < 0 or (i - a) % b != 0 ) ret++;
                i *= d;
            }
        }
        
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 1000LL; long long Arg5 = 1000LL; verify_case(0, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 3LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 1000LL; long long Arg5 = 343LL; verify_case(1, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 40LL; long long Arg1 = 77LL; long long Arg2 = 40LL; long long Arg3 = 100000LL; long long Arg4 = 40LL; long long Arg5 = 1LL; verify_case(2, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 452LL; long long Arg1 = 24LL; long long Arg2 = 4LL; long long Arg3 = 5LL; long long Arg4 = 600LL; long long Arg5 = 10LL; verify_case(3, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { long long Arg0 = 234LL; long long Arg1 = 24LL; long long Arg2 = 377LL; long long Arg3 = 1LL; long long Arg4 = 10000LL; long long Arg5 = 408LL; verify_case(4, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_7() { long long Arg0 = 867388102154LL; long long Arg1 = 369340281620LL; long long Arg2 = 588218623027LL; long long Arg3 = 20738LL; long long Arg4 = 595665623712LL; long long Arg5 = 1LL; verify_case(7, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CountingSeries ___test;
    ___test.run_test(-1);
}
// END CUT HERE
