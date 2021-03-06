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
#define INF 0x7f7f7f7f

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

class PalindromizationDiv1 {
public:
	LL add[26];
	LL del[26];
	LL cng[26][26];
	LL cost[26];
	LL cost2[26][26];
	
	LL func(string a, string b) {
		REVERSE(a);
		int n = SZ(a);
		int m = SZ(b);
		
		vector<VL> dp(n+1, VL(m+1, INF));
		dp[0][0] = 0;
		
		FORI(i, n+1) FORI(j, m+1) {
			if(i<n) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + cost[a[i]-'a']);
			if(j<m) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + cost[b[j]-'a']);
			if(i<n and j<m) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + cost2[a[i]-'a'][b[j]-'a']);
		}
		
		return dp[n][m];
	}
	int getMinimumCost(string w, vector<string> ope) {
		
		FORI(i,26) add[i] = INF;
		FORI(i,26) del[i] = INF;
		FORI(i,26) FORI(j,26) cng[i][j] = INF;
		
		FORI(i,26) cost[i] = INF;
		FORI(i,26) FORI(j,26) cost2[i][j] = INF;
		
		FORI(i, SZ(ope)) {
			// atoc atoi string-to-char string-to-int (istringstream)
			istringstream is(ope[i]);
			string type;
			char c1, c2;
			is >> type >>c1;
			if(type == "add"   ) { is >> add[c1-'a']; }
			if(type == "erase" ) { is >> del[c1-'a']; }
			if(type == "change") {
				is >> c2;
				is >> cng[c1-'a'][c2-'a'];
			}
		}
		
		// add, del, cngの組み合わせ
		FORI(i,26)                       cng[i][i] = 0;
		FORI(i,26) FORI(j,26)            cng[i][j] = min(cng[i][j], del[i]+add[j]);
		FORI(i,26) FORI(j,26) FORI(k,26) cng[i][j] = min(cng[i][j], cng[i][k]+cng[k][j]);
		FORI(i,26) FORI(j,26)            add[i] = min(add[i], add[j]+cng[j][i]);
		FORI(i,26) FORI(j,26)            del[i] = min(del[i], cng[i][j]+del[j]);
		
		// 文字と文字を同じにするコスト、文字を生成/削除するコスト
		FORI(i,26) FORI(j,26)            cost[i] = min(cost[i], add[i]);
		FORI(i,26) FORI(j,26)            cost[i] = min(cost[i], del[i]); //???
		FORI(i,26) FORI(j,26)            cost[i] = min(cost[i], cng[i][j]+add[j]);
		FORI(i,26) FORI(j,26) FORI(k,26) cost2[i][j] = min(cost2[i][j], cng[i][k]+cng[j][k]);
		
		int n = SZ(w);
		LL ret = INF;
		
		FORI(i, n) ret = min(ret, func(w.substr(0,i), w.substr(i+1)));
		FORI(i, n+1) ret = min(ret, func(w.substr(0,i), w.substr(i)));
		
		if(ret == INF) ret = -1;
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "racecar"; string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(0, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "topcoder"; string Arr1[] = {"erase t 1", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(1, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "topcoder"; string Arr1[] = {"erase t 10", "erase o 1", "erase p 1", "erase c 1", "erase d 1", "erase e 1", "erase r 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(2, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "caaaaaab"; string Arr1[] = {"change b a 100000", "change c a 100000", "change c d 50000", "change b e 50000", "erase d 50000", "erase e 49999"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 199999; verify_case(3, Arg2, getMinimumCost(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "moon"; string Arr1[] = {"erase o 5", "add u 7", "change d p 3", "change m s 12", "change n d 6", "change s l 1"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(4, Arg2, getMinimumCost(Arg0, Arg1)); }

// END CUT HERE

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
