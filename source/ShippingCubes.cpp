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

struct choice {
    int square;
    int cost;

    inline bool operator < (const choice a) const {
        return square * a.cost < a.square * cost;
    }
};

vector<choice> c;

int recursive(int i1, int n1) {
    if(n1 == 0) return 0;
    
    for(int i = i1; i >= 0; i--) {
        if (n1 >= c[i].square) {
            
            if (i > 0) {
            return min(
                recursive(i, n1 - c[i].square) + c[i].cost,
                recursive(i-1, n1) );
            }
            else {
                return recursive(i, n1 - c[i].square) + c[i].cost;
            }
        }
    }
}

class ShippingCubes {
public:
    int minimalCost(int N) {
        DBG2("N",N);
        
        c.clear();
        
        FORIS(i, 1, 15) FORIS(j, 1, 15) {
            choice a;
            a.square = i*j;
            a.cost = i+j+1;
            c.PB(a);
        }
        SORT(c);
        
        return recursive(SZ(c) - 1, N);
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 3; verify_case(0, Arg1, minimalCost(Arg0)); }
	void test_case_1() { int Arg0 = 6; int Arg1 = 6; verify_case(1, Arg1, minimalCost(Arg0)); }
	void test_case_2() { int Arg0 = 7; int Arg1 = 9; verify_case(2, Arg1, minimalCost(Arg0)); }
	void test_case_3() { int Arg0 = 200; int Arg1 = 18; verify_case(3, Arg1, minimalCost(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ShippingCubes ___test;
    ___test.run_test(-1);
}
// END CUT HERE
