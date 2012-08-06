#include <iostream>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    int n, m;
    cin >>n;
    int a[n];
    REP(i,n) cin >>a[i];
    cin >>m;
    int b[m];
    REP(i,m) cin >>b[i];

    int ratio=0;
    int ret=0;
    REP(i,n) REP(j,m) {
        if (b[j]%a[i]==0 and ratio<b[j]/a[i]) {
            ratio=b[j]/a[i];
            ret=1;
        } else if (b[j]%a[i]==0 and ratio==b[j]/a[i]) {
            ret++;
        }
    }
    cout <<ret <<endl;

    return 0;
}
