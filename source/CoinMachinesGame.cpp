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

struct machine {
	int need;
	int give;
	
	inline bool operator < (const machine a) const {
		return (need - give) < (a.need - a.give);
	}
};

class CoinMachinesGame {
public:
	int maxGames(int coins, vector <int> need, vector <int> give) {
		int N = SZ(need);
		vector<machine> m(N);
		FORI(i, N) {
			m[i].need = need[i];
			m[i].give = give[i];
		}
		
		SORT(m);
		
		LL ret = 0;
		LL c = coins;
		FORI(i, N) {
			if(m[i].need <= c) {
				LL times = (c - m[i].need) / (m[i].need - m[i].give);
//				DBG2("c",c);
//				DBG2("m[i].need",m[i].need);
//				DBG2("m[i].give",m[i].give);
//				DBG2("times",times);
				c -= m[i].need * times;
				c += m[i].give * times;
				ret += times;
			}
			while (m[i].need <= c) {
				c -= m[i].need;
				c += m[i].give;
				ret++;
			}
		}
		
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arr1[] = {5,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(0, Arg3, maxGames(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1000; int Arr1[] = {16,14,11,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {15,12,8,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 988; verify_case(1, Arg3, maxGames(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000000000; int Arr1[] = {1000,900,800,700,600,500,400,300,200,100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {701,802,503,604,405,306,107,208,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10869564; verify_case(2, Arg3, maxGames(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 12345678; int Arr1[] = {342,234,65,76,85,734,67,345,70,234}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {45,78,3,10,45,12,45,57,1,230}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3086370; verify_case(3, Arg3, maxGames(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CoinMachinesGame ___test;
	___test.run_test(-1);
}
// END CUT HERE
