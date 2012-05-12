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
#define PB(n) push_back(n)
#define PI M_PI
#define EPS 1e-13

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

int main() {
    //int T = 1;
    //cin >>T; cin.ignore();
    //
    //for(int t=1; t<=T; t++) {
        
        int A, B, K;
        cin >>A >>B >>K;
        DBG2("A",A);
        DBG2("B",B);
        DBG2("K",K);
        
        int N = 0;
        for (int i=A; i>0; i/=10) { N++; }
        
        vector<int> aryA(N, 0);
        vector<int> aryB(N, 0);
        
        int aa = A;
        int bb = B;
        FORI(i, N) {
            aryA[i] = aa % 10; aa/=10;
            aryB[i] = bb % 10; bb/=10;
            if (DEBUG) cout <<"DEBUG::: " <<i <<" " <<aryA[i] <<" " <<aryB[i] <<endl;
        }
        
        vector<int> borrow(N+1, 0);
        vector<int> aryC(N, 0);
        borrow[0] = 0;
        FORI(i, N) {
            if (aryA[i] - borrow[i] >= aryB[i]) {
                aryC[i] = aryA[i] - borrow[i] - aryB[i];
                borrow[i+1] = 0;
            }
            else {
                aryC[i] = aryA[i] - borrow[i] + 10 - aryB[i];
                borrow[i+1] = 1;
            }
        }
        
        int i = N-1;
        while (K--) {
            
            while (! borrow[i]
                or aryC[i] == 9) {
                i--;
                if (i < 0) break;
            }
            if (i < 0) break;
            
            aryC[i] += 1;
//            for (int j = i-1; j>=0; j--) {
//                if (aryA[j] != 0 or aryC[j] != 0) break;
//                aryC[j] += 1;
//            }
            
            i--;
        }
        
        int C = 0;
        FORI(i, N) {
            C *= 10; C += aryC[N-1-i];
        }
        cout <<C <<endl;
    //}
    
    return 0;
}
