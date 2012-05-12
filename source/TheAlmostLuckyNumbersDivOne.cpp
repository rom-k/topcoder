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

class TheAlmostLuckyNumbersDivOne {
public:
	LL A;
	LL B;
	
	LL dfs(LL n, int non_lucky) {
		LL ret = 0;
		if(B <  n) return 0;
		if(A <= n) ret++;
		
		FORI(i, 10) {
			if(i == 4 or i == 7) {
				ret += dfs(10 * n + i, non_lucky);
			}
			else if(non_lucky < 1 and i + n > 0) {
				ret += dfs(10 * n + i, non_lucky + 1);
			}
		}
		
		return ret;
	}
	
	LL find(LL a, LL b) {
		A = a;
		B = b;
		
		return dfs(0, 0);
		
//		return count(b) - count(a-1);
	}
	
//	LL count(LL num) {
//		if(num < 0) return 0;
//		
//		DBG2("num",num);
//		
//		LL cnt = 0;
//		
//		int n = 0;
//		vector<int> vnum(20, 0);
//		while(num > 0) {
//			vnum[n++] = num % 10;
//			num /= 10;
//		}
//		
//		DBG2("n",n);
//		
//		FORI(i, n) {
//			int num_i = vnum[i];
//			
//			int num_head = 0; //num of unlucky numbers on the top
//			FORIS(j, i+1, n) if(vnum[i] != 4 and vnum[i] != 7) num_head++;
//			
//			DBG2(" i",i);
//			DBG2(" num_i",num_i);
//			DBG2(" num_head",num_head);
//			
//			
//			LL add = 0;
//			
//			if(i == 0) {
//				add = num_i;
//			}
//			else if(i == 1) {
//				add = 2 * (num_i - 1);
//				if(num_i > 4) add += 8;
//				if(num_i > 7) add += 8;
//			}
//			else {
//				if(num_head <= 0) {
//					add += pow(2., i) * (num_i - 1);
//					if(num_i >  4) add += 8 * i * pow(2., i-1) - pow(2., i);
//					if(num_i >  7) add += 8 * i * pow(2., i-1) - pow(2., i);
//				}
//				
//				if(num_head <= 1) {
//					if(num_i > 4) add += pow(2., i);
//					if(num_i > 7) add += pow(2., i);
//				}
//			}
//			
//			cnt += add;
//			DBG2("  add=",add);
//		}
		
//		LL div = 1;
//		int maxlen = (int)log10(num);
//		if (log10(num) != maxlen) maxlen++;
//		DBG2("num",num);
//		DBG2("maxlen",maxlen);
//		
//		while(div <= num) {
//			LL a = (num / div) * div;
//			div *= 10;
//			LL b = (num / div) * div;
//			
//			int len = (int)log10(div);
//			if (log10(div) != len) len++;
//			DBG2("len",len);
//			
//			
//		}
//		return cnt;
//	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 7LL; long long Arg2 = 4LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 8LL; long long Arg1 = 19LL; long long Arg2 = 4LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 28LL; long long Arg1 = 33LL; long long Arg2 = 0LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 12345678900LL; long long Arg1 = 98765432100LL; long long Arg2 = 91136LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheAlmostLuckyNumbersDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
