#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define REPS(i,s,n) for(int i=s;i<n;i++)

int main() {
    int n;
    vector<int> a(10,0);
    cin >>n;
    REP(i,10) cin >>a[i];
    string c[n];
    REP(i,n) cin >>c[i];

    vector<int> vi(7,0);
    REP(i,7) {
        int cnt = 0;
        REP(j,n) {
            if (c[j][i]=='X') {cnt++;}
            else {vi[i]=max(vi[i],cnt); cnt=0;}
        }
        vi[i]=max(vi[i],cnt);
    }

    sort(a.begin(),a.end());
    sort(vi.begin(),vi.end(),greater<int>());

    vector<bool> used(10,false);
    string ret = "YES";
    REP(i,7) {
        bool ok = false;
        REP(j,10) {
            if (!used[j] and vi[i]<=a[j]) {
                ok = true;
                used[j] = true;
                break;
            }
        }
        if (!ok) ret = "NO";
    }
    cout <<ret <<endl;

    return 0;
}
