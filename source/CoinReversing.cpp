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

class CoinReversing {
public:
    
    // calc aCb
    double comb(int a, int b) {
        double ret = 1;
        int c = min(a, b);
        int d = max(a, b);
        FORIS(i, c+1, d+1) ret *= (double)i;
        return ret;
    }
    
    double expectedHeads(int N, vector <int> a) {
        
        double ret = 1.;
        FORI(i, SZ(a)) ret = ret + (1 - 2 * ret) * a[i] / N;
        return ret * N;
        
        /*
        int na = SZ(a);
        
        double dp[51][1001];
        FORI(i, na+1) FORI(j, N+1) dp[i][j] = 0.;
        dp[0][N] = 1.;
        
        FORI(t, na) {
            FORI(k, N+1) {
                if (dp[t][k] == 0.) continue;
                int k_change = a[t];
                
                FORIS(k_change_omote, 0, k_change+1) {
                    int k_ura = N - k;
                    int k_change_ura = k_change - k_change_omote;
                    
                    if (k < k_change_omote or k_ura < k_change_ura) continue;
                    
                    int k_next = k - k_change_omote + k_change_ura;
                    
                    dp[t+1][k_next] += dp[t][k]
                    * comb(k_change, k_change_omote) / comb(k_change_ura, 1)
                    * comb(k, k - k_change_omote) * comb(k_ura, k_ura - k_change_ura)
                    / comb(N, N - k_change);
                }
            }
            
            if(DEBUG) cout <<t <<": ";
            if(DEBUG) FORI(k, N+1) cout <<dp[t+1][k] <<" ";
            if(DEBUG) cout <<endl;
        }
        
        double ret = 0.;
        FORI(j, N+1) ret += j * dp[na][j];
        return ret;
        */
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.6666666666666667; verify_case(0, Arg2, expectedHeads(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {10,10,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(1, Arg2, expectedHeads(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 10; int Arr1[] = {2,7,1,8,2,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.792639999999999; verify_case(2, Arg2, expectedHeads(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000; int Arr1[] = {916,153,357,729,183,848,61,672,295,936}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 498.1980774932278; verify_case(3, Arg2, expectedHeads(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CoinReversing ___test;
    ___test.run_test(-1);
}
// END CUT HERE
