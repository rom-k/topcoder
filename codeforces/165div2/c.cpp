#include <iostream>
#include <cmath>

using namespace std;
typedef long long LL;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    int n;
    cin >>n;

    LL k[n], a[n];
    REP(i,n) cin >>k[i] >>a[i];

    LL ret = 0;
    REP(i,n) {
        LL s = (0 == a[i] ? 0 : 1);
        while (pow(4,s) < a[i]) {
            s++;
        }
        if (0 < s) {
            ret = max(ret, k[i] + s);
        }
    }
    cout <<ret <<endl;

    return 0;
}
