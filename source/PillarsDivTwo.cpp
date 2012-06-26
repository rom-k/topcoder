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

class PillarsDivTwo {
public:
    double maximalLength(vector <int> h, int w) {
        double dp[] = {0., 0.};
        FORIS(i, 1, SZ(h)) {
            double hp = h[i-1] - 1.;
            double hc = h[i] - 1.;
            double tmpdp0 = max(
                dp[0] + w,
                dp[1] + sqrt(w*w+hp*hp));
            dp[1] = max(
                dp[0] + sqrt(w*w+hc*hc),
                dp[1] + sqrt(w*w+(hc-hp)*(hc-hp)));
            dp[0] = tmpdp0;
        }
        return max(dp[0], dp[1]);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 5.656854249492381; verify_case(0, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; double Arg2 = 300.0; verify_case(1, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100,2,100,2,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 396.32310051270036; verify_case(2, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 3.82842712474619; verify_case(3, Arg2, maximalLength(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PillarsDivTwo ___test;
    ___test.run_test(-1);
}
// END CUT HERE
