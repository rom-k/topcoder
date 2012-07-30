#include <iostream>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    int n;
    cin >>n;
    int c[n];
    bool a[n][n];
    REP(i,n) REP(j,n) a[i][j]=false;
    REP(i,n) cin>>c[i], c[i]--;
    REP(i,n) {
        int k; cin >>k;
        REP(j,k) {
            int m; cin >>m;
            a[i][m-1]=true;
        }
    }

    int ret = n*3;
    REP(start,3) {
        int ret1 = 0;
        int cur = start;
        int clear = 0;
        bool b[n];
        REP(i,n) b[i]=false;
        while(clear<n) {
            bool stay=false;
            REP(j,n) {
                if(c[j]!=cur) continue;
                if(b[j]) continue;
                bool can=true;
                REP(k,n) if(a[j][k] and !b[k]) can=false;
                if(!can) continue;

                stay=true;
                clear++;
                b[j]=true;
                ret1++;
            }
            if (!stay) {
                cur=(cur+1)%3;
                ret1++;
            }
        }
        ret = min(ret, ret1);
    }

    cout <<ret <<endl;
    return 0;
}
