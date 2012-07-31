#include <iostream>
using namespace std;
typedef long long LL;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    int n;
    cin >>n;
    int a[n][n];
    REP(i,n)REP(j,n) cin >>a[i][j];

    if (n<3) {
        int sum = 0;
        REP(i,n)REP(j,n) sum+=a[i][j];
        cout <<sum <<endl;
        return 0;
    }

    LL sum[n][n];
    bool fromi[n][n];
    REP(i,n)REP(j,n) sum[i][j]=0;
    REP(i,n)REP(j,n) fromi[i][j]=false;
    REP(i,n)REP(j,n) {
        int costi = (0<=i-1 and i-1<n) ? sum[i-1][j] : -1005;
        int costj = (0<=j-1 and j-1<n) ? sum[i][j-1] : -1005;
        if (i==0 and j==0) costj = 0;
        sum[i][j] = max(costi,costj) + a[i][j];
        if (costi>costj) fromi[i][j]=true;
    }
    int cost = sum[n-1][n-1];
REP(i,n){ REP(j,n) cout <<" " <<a[i][j]; cout <<endl; }
cout <<"cost=" <<cost <<endl;

    int a2[n][n];
    REP(i,n)REP(j,n) a2[i][j]=0;
    REPS(i,1,n)REP(j,n-1) a2[i][j]=a[i][j];
    int ii, jj;
    ii = jj = n-1;
    while(0<=ii and 0<=jj) {
        if (!fromi[ii][jj]) {
            REP(i,ii) a2[i+1][jj-1]=a[i][jj];
        }
        if (fromi[ii][jj]) ii--;
        else               jj--;
    }
REP(i,n){ REP(j,n) cout <<" " <<a2[i][j]; cout <<endl; }

    REP(i,n)REP(j,n) sum[i][j]=0;
    REPS(i,1,n)REP(j,n-1) {
        int costi = (0<=i-1 and i-1<n) ? sum[i-1][j] : -1005;
        int costj = (0<=j-1 and j-1<n) ? sum[i][j-1] : -1005;
        if (i==1 and j==0) costj = 0;
        sum[i][j] = max(costi,costj) + a2[i][j];
    }
    cost += sum[n-1][n-2];
REP(i,n){ REP(j,n) cout <<" " <<sum[i][j]; cout <<endl; }

    cout <<cost <<endl;
    return 0;
}
