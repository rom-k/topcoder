#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
#define SORT(a) sort(a.begin(), a.end())

int main() {
    int n;
    cin >>n;

    vector<pair<LL, LL> > a(n);
    REP(i,n) cin >>a[i].first >>a[i].second;
    SORT(a);

//    REP(i,n) {
//        cout <<a[i].first <<" " <<a[i].second <<endl;
//    }
    for (int i=n-1; i>=0; i--) {
        
    }

//    int t;
//    for (t=n-2; t>=0; t--) {
//        if (a[t] > a[t+1]) break;
//    }
//    cout <<t+1 <<endl;

    return 0;
}
