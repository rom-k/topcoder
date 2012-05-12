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

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

class PasswordXGuessing {
public:
    long long howMany(vector <string> g) {
        int n = SZ(g);
        int l = SZ(g[0]);
        
        long long ret = 0;
        
        FORI(i,l) {
            DBG2("i",i);
            bool invalid = false;
            char fix = 'x';
            VI prob(10,1);
            prob[g[0][i]-'0'] = 0;
            FORIS(j,1,n) {
                int same = 0;
                FORI(k,l) if (k != i and g[0][k] == g[j][k]) same++;
                if (same == l-1) {
                    if (g[0][i] != g[j][i]) {
                        prob[g[j][i]-'0'] = 0;
                    }
                    //else -> completely same number.
                }
                else if (same == l-2) {
                    if (fix != 'x' and fix != g[j][i]) {
                        invalid = true; break;
                    }
                    else {
                        fix = g[j][i];
                    }
                }
                else {
                    invalid = true; break;
                }
            }
            DBG2(" invalid",invalid);
            DBG2(" fix",fix);
            FORI(j,10) if(DEBUG) cout <<"DEBUG:::  prob[" <<j <<"]=" <<prob[j] <<endl;
            if (invalid) continue;
            if (fix != 'x') {
                if (prob[fix-'0'] == 1) {
                    ret++;
                    DBG2("  => +",1);
                }
            }
            else {
                int sum = 0;
                FORI(j,10) sum += prob[j];
                ret += sum;
                DBG2("   => +",sum);
            }
        }
        
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"58", "47"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"539", "540", "541"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"12", "34", "56", "78"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"2", "3", "5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"4747", "4747", "4747", "4747"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 36LL; verify_case(4, Arg1, howMany(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PasswordXGuessing ___test;
    ___test.run_test(-1);
}
// END CUT HERE
