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

class TheJackpotDivOne {
public:
	vector<LL> find(vector<LL> m, LL jp) {
		int N = m.size();
		
		SORT(m);
		
		while(jp > 0) {
			if(m.front() == m.back()) break;
			
			// add and divide over long long integer
			LL mean    = 0;
			LL residue = 0;
			FORI(i, N) {
				mean    += m[i] / N;
				residue += m[i] % N;
			}
			mean += residue / N;
			
			DBG2("mean",mean);
			
			LL give = mean + 1 - m[0];
			if (give > jp) give = jp;
			DBG2("give",give);
			
			m[0] += give;
			jp   -= give;
			DBG2("jp",jp);
			
			SORT(m);
		}
		
		if(jp > 0) {
			LL quotient = jp / N;
			LL residue  = jp % N;
			FORI(i, N) {
				m[i] += quotient;
				if(i < residue) m[i] ++;
			}
		}
		
		SORT(m);
		
		return m;
	}

	
// BEGIN CUT HERE
	public:
//	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 10001)) test_case_10001(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { long Arr0[] = {1, 2, 3, 4}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; long Arr2[] = {2, 3, 3, 4 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long Arr0[] = {4}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; long Arr2[] = {11 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long Arr0[] = {4, 44, 7, 77}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 47LL; long Arr2[] = {24, 34, 44, 77 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long Arr0[] = {4, 10, 8, 3, 6, 5, 8, 3, 7, 5}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1000LL; long Arr2[] = {105, 106, 106, 106, 106, 106, 106, 106, 106, 106 }; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_10001() { long Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 1000000000000000000LL}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 900000000000000000LL; long Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 1000000000000000000LL}; vector<long long> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(10001, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheJackpotDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
