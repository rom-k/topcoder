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

class MagicalHats {
public:
    int findMaximumReward(vector <string> board, vector <int> coins, int numGuesses) {
        int ret = 0;
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(0, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"HHH",
 "H.H",
 "HH."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 9; verify_case(1, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"HH",
 "HH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(2, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"HHH",
 "HHH",
 "H.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13,13,13,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 13; verify_case(3, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"HHH",
 "HHH",
 "H.H"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13,13,13,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 26; verify_case(4, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"H.H.",
 ".H.H",
 "H.H."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {17}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = -1; verify_case(5, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arr0[] = {"HHH",
 "H.H",
 "HHH",
 "H.H",
 "HHH"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {33,337,1007,2403,5601,6003,9999}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 1377; verify_case(6, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }
	void test_case_7() { string Arr0[] = {".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".............",
 ".....H.H.....",
 "......H......",
 ".....H.H.....",
 ".............",
 ".............",
 ".............",
 "............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {22}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 22; verify_case(7, Arg3, findMaximumReward(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MagicalHats ___test;
    ___test.run_test(-1);
}
// END CUT HERE
