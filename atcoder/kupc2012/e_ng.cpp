#include <stdio.h>
#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long LL;

#define NN 1000

int main() {
    int n;
    cin >>n;
    string s[n];
    REP(i,n) cin >>s[i];

    LL ai[n];
    REP(i,n) ai[i] = 1;

    REP(i,NN) {
        int myhand = 0;
        int aihand;

        LL maxpoint = 0;
        REP(j,n) {
            LL point = 0;
            REP(k,n) point += ai[k] * (s[j][k]=='o'?3:s[j][k]=='-'?1:0);
            if (maxpoint < point) {
                myhand = j;
                maxpoint = point;
            }
        }

        printf("%d\n",myhand+1);
        fflush(stdout);
        scanf("%d", &aihand);
        aihand--;

        ai[aihand]++;
    }

    return 0;
}
