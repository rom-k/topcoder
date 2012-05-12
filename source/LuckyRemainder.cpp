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

int _atoi(char a) {
	if(a == '0') return 0;
	if(a == '1') return 1;
	if(a == '2') return 2;
	if(a == '3') return 3;
	if(a == '4') return 4;
	if(a == '5') return 5;
	if(a == '6') return 6;
	if(a == '7') return 7;
	if(a == '8') return 8;
	if(a == '9') return 9;
	return -1;
};

class LuckyRemainder {
public:
	int getLuckyRemainder(string X) {
		double N = SZ(X);
		LL ret = 0;
		FORI(i, N) ret += _atoi(X[i]);
		
		return (ret * (LL) pow(2., N-1)) % 9;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123"; int Arg1 = 6; verify_case(0, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_1() { string Arg0 = "24816"; int Arg1 = 3; verify_case(1, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_2() { string Arg0 = "8"; int Arg1 = 8; verify_case(2, Arg1, getLuckyRemainder(Arg0)); }
	void test_case_3() { string Arg0 = "11235813213455"; int Arg1 = 7; verify_case(3, Arg1, getLuckyRemainder(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LuckyRemainder ___test;
	___test.run_test(-1);
}
// END CUT HERE
