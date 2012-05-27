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

struct _checkpoint {
    double t;
    int c1, c2;
    
    inline bool operator < (const _checkpoint a) const {
        return t < a.t;
    }
};

//bool add_dup (int &dup[][], int car1, int car2) {
//    if (dup[car1][0] >= 0 and dup[car1][1] >= 0)
//    
//};

int main() {
    int T;
    cin >>T;
    cin.ignore();
    
    for(int t=1; t<=T; t++) {
        
        int N;
        cin >>N;
        
        char C[N];
        double S[N];
        double P[N];
        FORI(i,N) cin >>C[i] >>S[i] >>P[i];
        
        // lane char
        //  L => left lane
        //  R => right lane
        //  X => undefined lane
        char lane[N];
        FORI(i,N) lane[i] = 'X';
        
        // dependency matrix
        // +1 => same lane
        //  0 => independent
        // -1 => different lane
        int dep[N][N];
        FORI(i,N) FORI(j,N) dep[i][j] = 0;
        FORI(i,N) FORI(j,N) {
            if (i==j) continue;
            if (fabs(P[i]-P[j]) < 5.) {
                dep[i][j] = -1;
                lane[i] = C[i];
            }
        }
        FORI(i,N) FORI(j,N) FORI(k,N) {
            if (i==j or i==k or j==k) continue;
            if (dep[i][j] == -1 and dep[j][k] == -1) dep[i][k] = 1;
        }
        
        // count up check points
        vector<_checkpoint> cp;
        FORI(i,N) FORI(j,N) {
            if (i>=j) continue;
            _checkpoint cp_new;
            cp_new.c1 = i;
            cp_new.c2 = j;
            
            cp_new.t = (P[i]-P[j]+5.)/(-S[i]+S[j]);
            if (0 <= cp_new.t and cp_new.t < INF) cp.PB(cp_new);
            
            cp_new.t = (P[i]-P[j]-5.)/(-S[i]+S[j]);
            if (0 <= cp_new.t and cp_new.t < INF) cp.PB(cp_new);
        }
        SORT(cp);
        
        // simulate by check points
        double ret = -1;
        FORI(i,SZ(cp)) {
            double t = cp[i].t;
            int c1 = cp[i].c1;
            int c2 = cp[i].c2;
            double p1 = P[c1]+S[c1]*t;
            double p2 = P[c2]+S[c2]*t;
            if (p1 > p2) {
                c2 = cp[i].c1; c1 = cp[i].c2;
            }
            
            if (DEBUG) {
                cout <<"DEBUG::: t=" <<t <<endl;
                cout <<"DEBUG:::  c1=" <<c1 <<"\ts1=" <<S[c1] <<"\tp1=" <<P[c1]+S[c1]*t <<"\tlane=" <<lane[c1] <<endl;
                cout <<"DEBUG:::  c2=" <<c2 <<"\ts2=" <<S[c2] <<"\tp2=" <<P[c2]+S[c2]*t <<"\tlane=" <<lane[c2] <<endl;
                if (S[c1] > S[c2]) cout <<"DEBUG:::  =>close in (dep=" <<dep[c1][c2] <<")" <<endl;
            }
            
            // close in
            if (S[c1] > S[c2]) {
                if (dep[c1][c2] > 0
                or  lane[c1] == 'L' and lane[c2] == 'L'
                or  lane[c1] == 'R' and lane[c2] == 'R'
                ) {
                    ret = t;
                    break;
                }
                
                FORI(cx,N) {
                    double px = P[cx]+S[cx]*t;
                    if(p1 < px and px < p2) {
                        ret = t;
                        break;
                    }
                }
                if (ret >= 0) break;
                
                if     (lane[c1] == 'R') lane[c2] = 'L';
                else if(lane[c1] == 'L') lane[c2] = 'R';
                else if(lane[c2] == 'R') lane[c1] = 'L';
                else if(lane[c2] == 'L') lane[c1] = 'R';
                
                dep[c1][c2] = dep[c2][c1] = -1;
                FORI(i,N) {
                    if(dep[c1][i] == 0 and dep[c2][i] != 0)
                        dep[c1][i] = dep[i][c1] = -dep[c2][i];
                    if(dep[c2][i] == 0 and dep[c1][i] != 0)
                        dep[c2][i] = dep[i][c1] = -dep[c1][i];
                }
            }
            
            // get away
            else {
                bool c1_free = true;
                bool c2_free = true;
                
                FORI(i,N) {
                    if(i==c1 or i==c2) continue;
                    if(fabs(P[i]+S[i]*t - p1) < 5.) c1_free = false;
                    if(fabs(P[i]+S[i]*t - p2) < 5.) c2_free = false;
                }
                
                if (c1_free) {
                    lane[c1] = 'X';
                    FORI(i,N) dep[c1][i] = dep[i][c1] = 0;
                }
                if (c2_free) {
                    lane[c2] = 'X';
                    FORI(i,N) dep[c2][i] = dep[i][c2] = 0;
                }
            }
            
            if (ret >= 0) break;
        }
        
        if (ret < 0) { cout <<"Case #" <<t <<": Possible" <<endl; }
        else         { cout <<"Case #" <<t <<": " <<ret <<endl;   }
    }
    
    return 0;
}
