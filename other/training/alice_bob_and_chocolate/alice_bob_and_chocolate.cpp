#include <iostream>
using namespace std;

main () {
    int n;
    cin >>n;
    int l[n];
    for (int i=0; i<n; i++) cin >>l[i];

    int ret1 = 0;
    int ret2 = 0;
    int t1 = 0;
    int t2 = 0;
    while(ret1 + ret2 < n) {
        if (t1 <= t2) {
            t1 += l[ret1];
            ret1++;
        }
        else {
            t2 += l[n-1-ret2];
            ret2++;
        }
    }

    cout <<ret1 <<" " <<ret2 <<endl;
    return 0;
}
