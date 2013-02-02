#include <iostream>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    int t;
    cin >>t;
    REP(i, t) {
        int a;
        cin >>a;
        if ((a * 2) % (180 - a) == 0) {
            cout <<"YES" <<endl;
        }
        else {
            cout <<"NO" <<endl;
        }
    }

    return 0;
}
