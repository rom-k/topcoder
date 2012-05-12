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

class ThreeTeleports {
public:
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
            if(DEBUG) cout <<"DEBUG::: " <<from_x[i] <<" " <<from_y[i] <<" " <<to_x[i] <<" " <<to_y[i] <<endl;
        }
        
        LL a[2+nt*2][2+nt*2];
        FORI(i, 2+nt) FORI(j, 2+nt) { a[i][j] = -1; }
        a[0][0] = 0;
        a[1][1] = 0;
        a[0][1] = abs(xMe - xHome) + abs(yMe - yHome);
        
        DBG2("a[0][1]",a[0][1]);
        
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
//            a[2+j*2+1][2+i*2] = abs(to_x[j] - from_x[i]) + abs(to_y[j] - from_y[i]);
//            a[2+i*2+1][2+j*2] = abs(to_x[i] - from_x[j]) + abs(to_y[i] - from_y[j]);
//            a[2+i*2][2+j*2+1] = abs(from_x[i] - to_x[j]) + abs(from_y[i] - to_y[j]);
//            a[2+j*2][2+i*2+1] = abs(from_x[j] - to_x[i]) + abs(from_y[j] - to_y[i]);
            a[2+i*2][2+j*2+1] = abs(from_x[i] - to_x[j]) + abs(from_y[i] - to_y[j]);
            a[2+i*2][2+j*2] = abs(from_x[i] - from_x[j]) + abs(from_y[i] - from_y[j]);
            a[2+i*2+1][2+j*2] = abs(to_x[i] - from_x[j]) + abs(to_y[i] - from_y[j]);
            a[2+i*2+1][2+j*2+1] = abs(to_x[i] - to_x[j]) + abs(to_y[i] - to_y[j]);
        }
        
        FORI(i, 2+nt*2) FORI(j, 2+nt*2) FORI(k, 2+nt*2) {
//            if(a[i][k] < 0) continue;
//            if(a[k][j] < 0) continue;
//            if(a[i][j] < 0) {a[i][j] = a[i][k] + a[k][j]; continue;}
//            a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            if(a[j][i] < 0) continue;
            if(a[i][k] < 0) continue;
            if(a[j][k] < 0) {a[j][k] = a[j][i] + a[i][k]; continue;}
            a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
        }
        
        if(DEBUG)
        FORI(i, 2+nt*2) {
            cout <<"DEBUG::: ";
            FORI(j, 2+nt*2) cout <<a[i][j] <<" , ";
            cout <<endl;
        }
        
        DBG2("a[0][1]",a[0][1]);
        DBG2("a[0][4]",a[0][4]);
        DBG2("a[4][5]",a[4][5]);
        DBG2("a[5][1]",a[5][1]);
        
        return (int)a[0][1];
    }

    

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
