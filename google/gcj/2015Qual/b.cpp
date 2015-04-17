#include <iostream>
#include <algorithm>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

#define MAX_P 1005

int main() {
    int T;
    cin >>T;
    cin.ignore();
    
    for(int t=1; t<=T; t++) {
        int D;
        int D_of_P[MAX_P];
        REP(i, MAX_P) D_of_P[i] = 0;
        
        cin >>D;
        REP(i, D) {
            int P;
            cin >>P;
            D_of_P[P]++;
        }
        
        int maxP = MAX_P - 1;
        while (D_of_P[maxP] == 0) maxP--;
        
        int ans = maxP;
        
        for (int upperP = 2; upperP < ans; upperP++) {
            int a = 0;
            REPS(P, upperP + 1, maxP + 1) {
                if (D_of_P[P] != 0) {
                    int div;
                    div = P / upperP;
                    div += (P % upperP == 0 ? 0 : 1);
                    a += D_of_P[P] * (div - 1);
                }
            }
            a += upperP;
            ans = min(ans, a);
        }
        
        cout <<"Case #" <<t <<": " <<ans <<endl;
    
    }
    return 0;
}
