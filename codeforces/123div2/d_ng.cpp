#include <iostream>
#include <map>
using namespace std;
typedef long long LL;

int main() {
    LL n;
    cin >>n;
    map<double,LL> mp;
    LL ret = 0;

    for (LL i=0;i<n;i++) {
        LL k, b;
        cin >>k >>b;

        if (k == 0) continue;
        double p = -(double)b / k;
        if (mp.find(p) == mp.end()) mp[p] = 0;
        mp[p] += k;
    }

    for (map<double,LL>::iterator it=mp.begin();it!=mp.end();it++) {
//        if ((*it).second != 0) ret++;
        ret++;
    }

    cout <<ret <<endl;
    return 0;
}
