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

class PlatypusPaternity {
public:
    int maxFamily(vector <string> f,
                  vector <string> m,
                  vector <string> s)
    {
        int n = SZ(s);
        int nf = SZ(f);
        int nm = SZ(m);
        int nc = SZ(s[0]);
        int ret = 0;
        
        FORI(i, n) {
            
            bool valid = false;
            FORI(i2, nf) {
                if (valid) break;
                valid = true;
                FORI(j, nc) {
                    if (s[i][j] == 'Y' and f[i2][j] == 'N') valid = false;
                }
            }
            if (not valid) continue;
            
            valid = false;
            FORI(i2, nm) {
                if (valid) break;
                valid = true;
                FORI(j, nc) {
                    if (s[i][j] == 'Y' and m[i2][j] == 'N') valid = false;
                }
            }
            if (not valid) continue;
            
            int num = 0;
            FORI(j, SZ(s[i])) if (s[i][j] == 'Y') num++;
            
            ret = max(ret, num+2);
        }
        
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"YYYY", "YYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYN", "YYYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYYN", "NNNY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(0, Arg3, maxFamily(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"NNYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYNNN", "NNYYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, maxFamily(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"YYYYYYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYYYYYYYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YNYNYNYNY",
 "NNNYNYNNN",
 "NYNNNNNYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, maxFamily(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"YY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN", "NY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(3, Arg3, maxFamily(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"YYNNYYNNYYNN",
 "YNYNYNYNYNYN",
 "YYYNNNYYYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYYNNYYNNYYN",
 "YYNYYYNYYYNY",
 "NNNNNNYYYYYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"NYNNNYNNNNNN",
 "NNNNNNNNYNNN",
 "NNYNNNNNNNYN",
 "YNNNNNNYNNNN",
 "NNNNNNNNNYNY",
 "NNNYYNYNNNNN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(4, Arg3, maxFamily(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PlatypusPaternity ___test;
    ___test.run_test(-1);
}
// END CUT HERE
