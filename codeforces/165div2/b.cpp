#include <iostream>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    int n;
    cin >>n;

    int a[n];
    REP(i,n) cin >>a[i];

    int t;
    for (t=n-2; t>=0; t--) {
        if (a[t] > a[t+1]) break;
    }
    cout <<t+1 <<endl;

    return 0;
}
