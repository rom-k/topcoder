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

class AkariDaisukiDiv2 {
public:
    int countTuples(string S) {
        int n = SZ(S);
        int ret = 0;
        FORIS(a,1,n-3) {
            FORIS(b,1,n-3) {
                if ((n-a-b+1)/2<2) continue;
                FORIS(l,1,(n-a-b+1)/2) {
                    if(S.substr(a,l) == S.substr(n-b-l,l)) ret++;
                }
            }
        }
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "topcoderdivtwo"; int Arg1 = 2; verify_case(0, Arg1, countTuples(Arg0)); }
	void test_case_1() { string Arg0 = "foxciel"; int Arg1 = 0; verify_case(1, Arg1, countTuples(Arg0)); }
	void test_case_2() { string Arg0 = "magicalgirl"; int Arg1 = 4; verify_case(2, Arg1, countTuples(Arg0)); }
	void test_case_3() { string Arg0 = "waaiusushioakariusushiodaisuki"; int Arg1 = 75; verify_case(3, Arg1, countTuples(Arg0)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; int Arg1 = 8924; verify_case(4, Arg1, countTuples(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    AkariDaisukiDiv2 ___test;
    ___test.run_test(-1);
}
// END CUT HERE
