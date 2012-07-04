#include <iostream>
#include <set>
using namespace std;
typedef long long LL;

int main() {
    LL n, d, a, b;
    cin >>n >>d >>a >>b;
    LL x[n], y[n];
    for (int i=0;i<n;i++) cin >>x[i] >>y[i];

    set<pair<LL,LL> > s;
    for (int i=0;i<n;i++) {
        LL need = a*x[i]+b*y[i];
        s.insert(pair<LL,LL>(need, i+1));
    }

    set<LL> ret;
    for (set<pair<LL,LL> >::iterator it=s.begin();it!=s.end();it++) {
        if (d < (*it).first) break;
        d -= (*it).first;
        ret.insert((*it).second);
    }

    cout <<ret.size() <<endl;
    for (set<LL>::iterator it=ret.begin();it!=ret.end();it++) {
        cout <<(*it) <<" ";
    }
    cout <<endl;

    return 0;
}
