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

class SubFibonacci {
public:
	int maxElements(vector <int> s) {
		
		LL a[55][55][55];
		FORI(i, 55) FORI(j, 55) FORI(k, 55) a[i][j][k]=0;
		
		SORT(s);
		int n = SZ(s);
		
		map<LL, LL> m;
		FORI(i, n) m[s[i]] = i;
		
		if(DEBUG) FORI(i, n) DBG(s[i]);
		
		FORI(i, n) FORI(j, n) {
			if (i == j) continue;
			a[i][j][0] = s[i];
			a[i][j][1] = s[j];
			
			DBG2("i",i);
			DBG2("j",j);
			DBG2(" ",a[i][j][0]);
			DBG2(" ",a[i][j][1]);
			
			FORIS(k, 2, n) {
				LL num = a[i][j][k-2] + a[i][j][k-1];
				if (m.find(num) == m.end()) break;
				a[i][j][k] = num;
				DBG2(" ",a[i][j][k]);
			}
		}
		
		int ret = 0;
		
		FORI(i, n) FORI(j, n) {
			if(i == j) continue;
			
			bool used[55];
			FORI(ii, 55) used[ii]=false;
			
			int cnt1 = 0;
			FORI(k, n) {
				if (a[i][j][k] == 0) break;
				used[m[a[i][j][k]]] = true;
				cnt1++;
			}
			
			int cnt2 = 0;
			FORI(ii, n) FORI(jj, n) {
				if (ii == jj) continue;
				if (used[ii]) continue;
				if (used[jj]) continue;
				
				FORI(kk, n) {
					if (a[ii][jj][kk] == 0) break;
					used[m[a[ii][jj][kk]]] = true;
					cnt2++;
				}
			}
			
			ret = max(ret, cnt1 + cnt2);
		}
		
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8, 1, 20, 3, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxElements(Arg0)); }
	void test_case_1() { int Arr0[] = {19, 47, 50, 58, 77, 99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, maxElements(Arg0)); }
	void test_case_2() { int Arr0[] = {512}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, maxElements(Arg0)); }
	void test_case_3() { int Arr0[] = {3, 5, 7, 10, 13, 15, 20, 90}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, maxElements(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(4, Arg1, maxElements(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SubFibonacci ___test;
	___test.run_test(-1);
}
// END CUT HERE
