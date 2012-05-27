#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int T;
    cin >>T;
    cin.ignore();

    for(int t=1; t<=T; t++) {
        int N, D;
        cin >>N;
        int d[N];
        int l[N];
        for (int i=0;i<N;i++) cin >>d[i] >>l[i];
        cin >>D;

        bool ok = false;
        int dp[N];
        memset(dp, 0, sizeof(dp));

        dp[0] = d[0];
        for (int i=0;i<N;i++) {
            int d_can_reach = d[i] + dp[i];
            if (D <= d_can_reach) {
                ok = true;
                break;
            }
            for (int j=i+1;j<N;j++) {
                if (d_can_reach < d[j]) break;
                dp[j] = max(dp[j], min(d[j]-d[i], l[j]));
            }
        }

        if (ok) cout <<"Case #" <<t <<": YES" <<endl;
        else    cout <<"Case #" <<t <<": NO" <<endl;
    }
    return 0;
}
