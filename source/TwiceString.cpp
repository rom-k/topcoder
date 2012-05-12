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

class TwiceString {
public:
    string getShortest(string s) {
        int n = SZ(s);
        int i = 1;
        while(1) {
            bool flg = true;
                FORI(j, n-i) if (s[j] != s[j+i]) {flg = false;}
            if (flg) break;
            i++;
        }
        return s + s.substr(n-i);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; string Arg1 = "ababa"; verify_case(0, Arg1, getShortest(Arg0)); }
	void test_case_1() { string Arg0 = "xxxxx"; string Arg1 = "xxxxxx"; verify_case(1, Arg1, getShortest(Arg0)); }
	void test_case_2() { string Arg0 = "topcoder"; string Arg1 = "topcodertopcoder"; verify_case(2, Arg1, getShortest(Arg0)); }
	void test_case_3() { string Arg0 = "abracadabra"; string Arg1 = "abracadabracadabra"; verify_case(3, Arg1, getShortest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TwiceString ___test;
    ___test.run_test(-1);
}
// END CUT HERE
