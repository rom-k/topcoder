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
//#define INF 0x7f7f7f7f

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

#define INF 2000000005

class ThreeTeleports {
public:
    LL x[8];
    LL y[8];
    LL m[8][8];
    
    LL dist(int i, int j) {
        return abs(x[i] - x[j]) + abs(y[i] - y[j]);
    }
    
    int shortestDistance(int x0, int y0, int x1, int y1, vector <string> t) {
        
        x[0] = x0; y[0] = y0;
        x[1] = x1; y[1] = y1;
        FORI(i, 8) FORI(j, 8) m[i][j] = INF;
        
        FORI(i, 3) {
            // atoc atoi string-to-char string-to-int (istringstream)
            istringstream is(t[i]);
            is >>x[2+i*2] >>y[2+i*2] >>x[2+i*2+1] >>y[2+i*2+1];
        }
        
        FORI(i, 3)
            m[2+i*2][2+i*2+1] = m[2+i*2+1][2+i*2] = 10;
        
        FORI(i, 8) FORI(j, 8)
            m[i][j] = min(m[i][j], dist(i, j));
        
        FORI(i, 8) FORI(j, 8) FORI(k, 8)
            m[j][k] = min(m[j][k], m[j][i] + m[i][k]);
        
        return m[0][1];
    }
    
    /*
    int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> t) {
        
        int nt = SZ(t);
        LL from_x[nt];
        LL from_y[nt];
        LL to_x[nt];
        LL to_y[nt];
        FORI(i, nt) {
            // atoc atoi string-to-char string-to-int (istringstream)
            istringstream is(t[i]);
            is >>from_x[i] >>from_y[i] >>to_x[i] >>to_y[i];
        }
        
        LL a[2+nt*2][2+nt*2];
        FORI(i, 2+nt) FORI(j, 2+nt) { a[i][j] = -1; }
        a[0][0] = 0;
        a[1][1] = 0;
        a[0][1] = abs(xMe - xHome) + abs(yMe - yHome);
        
        FORI(i, nt) {
            a[2+i*2][2+i*2] = 0;
            a[2+i*2+1][2+i*2+1] = 0;
            
            a[0][2+i*2] = abs(xMe - from_x[i]) + abs(yMe - from_y[i]);
            a[0][2+i*2+1] = abs(xMe - to_x[i]) + abs(yMe - to_y[i]);
            
            a[2+i*2][1] = abs(from_x[i] - xHome) + abs(from_y[i] - yHome);
            a[2+i*2+1][1] = abs(to_x[i] - xHome) + abs(to_y[i] - yHome);
            
            a[2+i*2][2+i*2+1] = 10;
            a[2+i*2+1][2+i*2] = 10;
        }
        
        FORI(i, nt) FORI(j, nt) {
            if(i == j) continue;
            a[2+i*2][2+j*2+1] = abs(from_x[i] - to_x[j]) + abs(from_y[i] - to_y[j]);
            a[2+i*2][2+j*2] = abs(from_x[i] - from_x[j]) + abs(from_y[i] - from_y[j]);
            a[2+i*2+1][2+j*2] = abs(to_x[i] - from_x[j]) + abs(to_y[i] - from_y[j]);
            a[2+i*2+1][2+j*2+1] = abs(to_x[i] - to_x[j]) + abs(to_y[i] - to_y[j]);
        }
        
        FORI(i, 2+nt*2) FORI(j, 2+nt*2) FORI(k, 2+nt*2) {
            if(a[j][i] < 0) continue;
            if(a[i][k] < 0) continue;
            if(a[j][k] < 0) {a[j][k] = a[j][i] + a[i][k]; continue;}
            a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
        }
        
        return (int)a[0][1];
    }
    */

    
// BEGIN CUT HERE
    public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
    private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 4; int Arg3 = 5; string Arr4[] = {"1000 1001 1000 1002", "1000 1003 1000 1004", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 3; verify_case(0, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_1() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 20; int Arg3 = 20; string Arr4[] = {"1 1 18 20", "1000 1003 1000 1004", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 14; verify_case(1, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_2() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 20; int Arg3 = 20; string Arr4[] = {"1000 1003 1000 1004", "18 20 1 1", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 14; verify_case(2, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 10000; int Arg3 = 20000; string Arr4[] = {"1000 1003 1000 1004", "3 3 10004 20002", "1000 1005 1000 1006"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 30; verify_case(3, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_4() { int Arg0 = 3; int Arg1 = 7; int Arg2 = 10000; int Arg3 = 30000; string Arr4[] = {"3 10 5200 4900", "12212 8699 9999 30011", "12200 8701 5203 4845"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 117; verify_case(4, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }
    void test_case_5() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1000000000; int Arg3 = 1000000000; string Arr4[] = {"0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"}; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 36; verify_case(5, Arg5, shortestDistance(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ThreeTeleports ___test;
    ___test.run_test(-1);
}
// END CUT HERE
