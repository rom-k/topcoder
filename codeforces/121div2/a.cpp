#include <iostream>
#include <set>
using namespace std;
typedef long long LL;

int main() {
    LL a;
    set<LL> sl;

    cin >>a;
    for (int i=1;i<44721;i++) sl.insert(i*(i+1)/2);

    bool ok = false;
    for (set<LL>::iterator it=sl.begin();it!=sl.end();it++)
        if (sl.find(a - *it) != sl.end()) ok = true;

    if (ok) cout <<"YES" <<endl;
    else    cout <<"NO"  <<endl;
    return 0;
}
