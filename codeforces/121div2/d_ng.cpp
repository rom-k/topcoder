#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
#define REP(i,n) for(LL i=0;i<n;i++)
#define REPS(i,s,n) for(LLi=s;i<n;i++)

int main() {
    LL n, k, b;
    LL a[n];
    LL ret = n-1;
    cin >>n >>k >>b;
    REP(i,n) cin>>a[i];

//    set<pair<LL,LL> > c;
//    for (LL i=n-2;i>=0;i--) {
//        set<pair<LL,LL> > c2;
//        for (set<pair<LL,LL> >::iterator it=c.begin();
//            it!=c.end();
//            it++)
//        {
//            if ((*it).first)
//        }
//    }

    cout <<ret+1 <<endl;
    return 0;
}
