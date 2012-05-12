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
#define PI M_PI
#define EPS 1e-13

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

class TheTicketsDivTwo {
public:
	double prob(int n, int m, int k) {
		double ret = 0;
		
		DBG2("n",n);
		DBG2("m",m);
		DBG2("k",k);
		
		if (n == 1) {
			DBG(" ->last one");
			ret = 1.;
		}
		else if(k <= 0 and m == 1) {
			DBG(" ->tired and selected");
			ret = 1.;
		}
		else if(k <= 0 and m != 1) {
			DBG(" ->tired and not selected");
		}
		else if(m == 1) {
			DBG(" ->first in line");
			ret += 1. / 6;
			ret += prob(n, n, k-1) / 2;
		}
		else {
			DBG(" ->not first in line");
			ret += prob(n, m-1, k-1) / 2;
			ret += prob(n-1, m-1, k-1) / 3;
		}
		
		DBG2("ret",ret);
		
		return ret;
	}
	
	double find(int n, int m, int k) {
		return prob(n, m, k);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; double Arg3 = 0.16666666666666666; verify_case(0, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.5833333333333334; verify_case(1, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 7; int Arg2 = 4; double Arg3 = 0.0; verify_case(2, Arg3, find(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 10; double Arg3 = 0.25264033564814814; verify_case(3, Arg3, find(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheTicketsDivTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
