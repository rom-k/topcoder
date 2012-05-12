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

int main() {
    int T;
    cin >>T;
    cin.ignore();
    
    for(int t=1; t<=T; t++) {
        
        int N;
        cin >>N;
        
        vector<int> a(N, 0);
        vector<int> b(N, 0);
        FORI(i, N) cin >>a[i] >>b[i];
        
        vector<int> clear(N, 0);
        int clear2_num = 0;
        int star = 0;
        int ret = 0;
        bool end_flag = false;
        while(clear2_num < N) {
            ret++;
            
            int target = -1;
            int sub_target = -1;
            FORI(i, N) {
                if (b[i] <= star and clear[i] < 2) {
                    target = i; break;
                }
                else if (a[i] <= star and clear[i] < 1) {
                    if (sub_target < 0
                    or  b[sub_target] < b[i]) {
                        sub_target = i;
                    }
                }
            }
            
            if (target >= 0) {
                int i = target;
                star += (clear[i] == 0 ? 2 : 1);
                clear[i] = 2;
                clear2_num++;
            }
            else if (sub_target >= 0) {
                int i = sub_target;
                star ++;
                clear[i] = 1;
            }
            else {
                cout <<"Case #" <<t <<": Too Bad" <<endl;
                end_flag = true;
            }
            
            if(end_flag) break;
        }
        if(end_flag) continue;
        
        cout <<"Case #" <<t <<": " <<ret <<endl;
    }
    
    return 0;
}
