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

class FoxAndDoraemon {
public:
    int minTime(vector <int> wc, int sc) {
        SORT(wc);
        REVERSE(wc);
        
        int n = SZ(wc);
        VI c(n, 0);
        
        FORI(i, n) {c[i] = sc * (i+1) + wc[i];}
        c[n-1] -= sc;
        
        int ret = 0;
        FORI(i, n) {ret = max(ret, c[i]);}
        
        //FORI(i, n) {DBG2(i, wc[i]);}
        FORI(i, n) {DBG2(i, c[i]);}
        DBG2("ret",ret);
        
        for(int i=n-4; i>=0; i--) {
            //if (c[i] + sc < c[i+2]) {
            if (c[i] + sc < ret) {
                c[i] += sc;
                c[i+1] -= sc;
                c[i+2] -= sc;
                ret -= sc;
                ret = max(ret, max(c[i], c[i+1]));
            }
            
            else if (c[i+1] + sc < c[i+2]
                 and c[i+1] + sc < c[i+3]) {
                //TODO
            }
        }
        
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 1002; verify_case(0, Arg2, minTime(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,6,9,12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 2012; verify_case(1, Arg2, minTime(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1000,100,10,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1001; verify_case(2, Arg2, minTime(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1712,1911,1703,1610,1697,1612}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 2012; verify_case(3, Arg2, minTime(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3000; int Arg2 = 15000; verify_case(4, Arg2, minTime(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {58}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3600; int Arg2 = 58; verify_case(5, Arg2, minTime(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FoxAndDoraemon ___test;
    ___test.run_test(-1);
}
// END CUT HERE
