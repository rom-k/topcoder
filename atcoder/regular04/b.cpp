#include <iostream>
using namespace std;
typedef long long LL;

int main() {
    int n;
    cin >>n;
    LL d[n];
    for (int i=0;i<n;i++) cin >>d[i];

    LL maxd = 0;
    LL retmax = 0;
    LL retmin;
    for (int i=0;i<n;i++) {
        maxd = max(maxd, d[i]);
        retmax += d[i];
    }
    retmin = max(0LL, maxd + maxd - retmax);

    cout <<retmax <<endl;
    cout <<retmin <<endl;
    return 0;
}
