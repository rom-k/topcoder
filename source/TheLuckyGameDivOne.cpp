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

class TheLuckyGameDivOne {
public:
	LL a;
	LL b;
	LL jLen;
	LL bLen;
	VL lucky;
	VL checkpoint;
	
	void dfs(LL n) {
		if(b <  n) return;
		if(a <= n) lucky.PB(n);
		
		dfs(10 * n + 4);
		dfs(10 * n + 7);
	}
	
	int get_superpos(LL n) {
		int ret = 0;
		FORI(i, SZ(lucky)) {
			if(lucky[i] <= n and n <= lucky[i] + bLen - 1) {
				ret++;
			}
		}
		return ret;
	}
	
	int find(LL a0, LL b0, LL jLen0, LL bLen0) {
		a = a0; b = b0; jLen = jLen0; bLen = bLen0;
		lucky.clear();
		checkpoint.clear();
		dfs(0);
		SORT(lucky);
		
		FORI(i, SZ(lucky)) {
			checkpoint.PB(lucky[i]);
			checkpoint.PB(lucky[i] + bLen);
		}
		LL start = a + bLen - 1;
		checkpoint.PB(start);
		SORT(checkpoint);
		
		stack<pair<LL, int> > st;
		st.push(pair<LL, int>(0, 0));
		int ret = 0;
		FORI(i, SZ(checkpoint)) {
			if(checkpoint[i] < start) continue;
			if(b < checkpoint[i]) break;
			
			LL  num = checkpoint[i];
			int superpos = get_superpos(num);
			
			pair<LL, int> p = st.top();
			LL  num_prev   = p.first;
			int superpos_prev = p.second;
			
			if(superpos_prev < superpos) {
				st.push(pair<LL, int>(num, superpos));
			}
			while(superpos_prev > superpos) {
				LL num_prev_save = num_prev;
				LL len = num - num_prev;
				if(jLen - bLen + 1 <= len) {
					ret = max(ret, superpos_prev);
				}
				
				st.pop();
				pair<LL, int> p2 = st.top();
				num_prev   = p2.first;
				superpos_prev = p2.second;
				
				if(superpos_prev < superpos) {
					st.push(pair<LL, int>(num_prev_save, superpos));
					num_prev   = num_prev_save;
					superpos_prev = superpos;
				}
			}
		}
		
		while(!st.empty()) {
			pair<LL, int> p3 = st.top();
			LL  num_prev   = p3.first;
			int superpos_prev = p3.second;
			st.pop();
			
			LL len = b - num_prev + 1;
			if(jLen - bLen + 1 <= len) {
				ret = max(ret, superpos_prev);
			}
		}
		
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 20)) test_case_20(); if ((Case == -1) || (Case == 59)) test_case_59(); if ((Case == -1) || (Case == 63)) test_case_63(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 10LL; long long Arg2 = 2LL; long long Arg3 = 1LL; int Arg4 = 0; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 100LL; long long Arg2 = 100LL; long long Arg3 = 100LL; int Arg4 = 6; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 4LL; long long Arg1 = 8LL; long long Arg2 = 3LL; long long Arg3 = 2LL; int Arg4 = 1; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 100LL; long long Arg2 = 75LL; long long Arg3 = 50LL; int Arg4 = 2; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_20() { long long Arg0 = 77LL; long long Arg1 = 474LL; long long Arg2 = 96LL; long long Arg3 = 65LL; int Arg4 = 0; verify_case(20, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_59() { long long Arg0 = 99LL; long long Arg1 = 9413414523LL; long long Arg2 = 9128363832LL; long long Arg3 = 6954249838LL; int Arg4 = 768; verify_case(59, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_63() { long long Arg0 = 1LL; long long Arg1 = 10000000000LL; long long Arg2 = 9558222065LL; long long Arg3 = 5684483791LL; int Arg4 = 512; verify_case(63, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheLuckyGameDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
