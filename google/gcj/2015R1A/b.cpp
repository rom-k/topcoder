#include <iostream>
#include <algorithm>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
typedef long long LL;

#define MAXB 1005
#define MAXM 100005

int main() {
    int T;
    cin >>T;
    cin.ignore();
    
    for(int tt=1; tt<=T; tt++) {
        
        int B, N;
        int M[MAXB];
        
        cin >>B >>N;
        REP(i, B) cin >>M[i];
        
        int minM = MAXM;
        REP(i, B) minM = min(minM, M[i]);
        
        LL lb = 0;
        LL ub = (LL) minM * (N-1) + 1;
        LL t;
        LL cutting;
        LL starting;
        while (1) {
            t = (ub + lb) / 2;
            
            cutting = 0;
            starting = 0;
            REP(i, B) {
                cutting += t / M[i] + (t % M[i] != 0 ? 1 : 0);
                starting += (t % M[i] == 0 ? 1 : 0);
            }
            
            if (cutting < N && N <= cutting + starting) {
                break;
            }
            else if (N <= cutting) {
                ub = t;
            }
            else {
                lb = t;
            }
        }
        
        int ans;
        REP(i, B) {
            if (t % M[i] == 0) {
                cutting++;
                if (cutting == N) {
                    ans = i;
                }
            }
        }
        
        ans++;
        cout <<"Case #" <<tt <<": " <<ans <<endl;
    }
    return 0;
}
