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

class KindAndCruel {
public:
	int crossTheField(string field, int K, int C) {
		int N = SZ(field);
		vector<int> can(N+1, 0);
		vector<int> tmp(N+1, 0);
		can[0] = 1;
		
		int t = 0;
		while(can[N-1] == 0) {
			t++;
			
			int cur_l = 0;
			int cur = can[0];
			FORI(i, N) {
				if(cur_l + cur + can[i+1] > 0) can[i] = 1;
				
				if(field[i] == 'K' and t % K == 0) can[i] = 0;
				if(field[i] == 'C' and t % C != 0) can[i] = 0;
				
				cur_l = cur;
				cur = can[i+1];
			}
			
			if(t % K == 0 and t % C == 0) {
				bool diff = false;
				FORI(i, N) if(can[i] != tmp[i]) diff = true;
				if(!diff) return -1;
				copy(can.begin(), can.end(), tmp.begin());
			}
		}
		
		return t;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "..."; int Arg1 = 2; int Arg2 = 5; int Arg3 = 2; verify_case(0, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = ".K.C."; int Arg1 = 3; int Arg2 = 4; int Arg3 = 5; verify_case(1, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = ".CCCC."; int Arg1 = 3; int Arg2 = 5; int Arg3 = -1; verify_case(2, Arg3, crossTheField(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = ".CKKKKCKKKKC.KKKKCKKKKC.CKKKKCKKKKCKKKKCKKKKCKKKK."; int Arg1 = 5; int Arg2 = 5; int Arg3 = 60; verify_case(3, Arg3, crossTheField(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KindAndCruel ___test;
	___test.run_test(-1);
}
// END CUT HERE
