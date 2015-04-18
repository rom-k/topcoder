#include <iostream>
#include <algorithm>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

#define MAXN 1005

int main() {
    int T;
    cin >>T;
    cin.ignore();
    
    for(int t=1; t<=T; t++) {
        int N;
        int m[MAXN];
        
        cin >>N;
        REP(i, N) cin >>m[i];
        
        int ans1 = 0;
        int ans2 = 0;
        int maxdiff = 0;
        
        REP(i, N-1) {
            if (m[i] > m[i+1]) {
                ans1 += m[i] - m[i+1];
                maxdiff = max(maxdiff, m[i] - m[i+1]);
            }
        }
        REP(i, N-1) {
            ans2 += min(m[i], maxdiff);
        }
        
        cout <<"Case #" <<t <<": " <<ans1 <<" " <<ans2 <<endl;
    }
    return 0;
}
