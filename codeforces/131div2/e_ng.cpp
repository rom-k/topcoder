#include <iostream>
using namespace std;
typedef long long LL;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
#define max_n 305

int n;
int a[max_n][max_n];
LL sum[max_n][max_n];
bool fromx[max_n][max_n];

int main() {
    cin >>n;
    REP(i,n)REP(j,n) cin >>a[i][j];

    REP(i,n)REP(j,n) sum[i][j]=0;
    REP(i,n)REP(j,n) fromx[i][j]=false;
    REP(i,n)REP(j,n) {
        int costx, costy;
        costy = (0<=i-1 and i-1<n) ? sum[i-1][j] : -1005;
        costx = (0<=j-1 and j-1<n) ? sum[i][j-1] : -1005;
        if (i==0 and j==0) costy = 0;
        sum[i][j] = max(costx,costy) + a[i][j];
        if (costx<costy) fromx[i][j]=true;
    }
    int cost = sum[n-1][n-1];

    int x, y;
    x = y = n-1;
    while(0<=x and 0<=y) {
        if (fromx[x][y]) {
            REP(i,y-1) a[x-1][y]=a[x][y-1];
            x--;
        }
        else {
            y--;
        }
    }

    REP(i,n)REP(j,n) sum[i][j]=0;
    REP(i,n)REP(j,n) fromx[i][j]=false;
    REP(i,n-1)REPS(j,1,n) {
        int costx, costy;
        costy = (0<=i-1 and i-1<n) ? sum[i-1][j] : -1005;
        costx = (0<=j-1 and j-1<n) ? sum[i][j-1] : -1005;
        if (i==0 and j==1) costy = 0;
        sum[i][j] = max(costx,costy) + a[i][j];
        if (costx<costy) fromx[i][j]=true;
    }
    cost += sum[n-2][n-1];

    cout <<cost <<endl;
    return 0;
}
