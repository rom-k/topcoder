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
#define PB(n) push_back(n)
#define PI M_PI
#define EPS 1e-13

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

class PerfectSequences {
public:
	string fixIt(vector <int> seq) {
		if (seq.size() == 1) return "Yes";
		
		FORI(i, seq.size()) {
			LL sum = 0;
			LL mul = 1;
			FORI(j, seq.size())
				if (i != j) {
					sum += seq[j];
					mul *= seq[j];
				}
			
			if ((mul - 1) != 0
			and sum % (mul - 1) == 0
			and sum / (mul - 1) >  0
			and sum / (mul - 1) != seq[i]) {
				return "Yes";
			}
			if (sum == 0
			and seq[i] != 0) {
				return "Yes";
			}
		}
		return "No";
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(0, Arg1, fixIt(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(1, Arg1, fixIt(Arg0)); }
	void test_case_2() { int Arr0[] = {1,4,2,4,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(2, Arg1, fixIt(Arg0)); }
	void test_case_3() { int Arr0[] = {1000000,1,1,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(3, Arg1, fixIt(Arg0)); }
	void test_case_4() { int Arr0[] = {8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(4, Arg1, fixIt(Arg0)); }
	void test_case_5() { int Arr0[] = {2,0,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(5, Arg1, fixIt(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PerfectSequences ___test;
	___test.run_test(-1);
}
// END CUT HERE
