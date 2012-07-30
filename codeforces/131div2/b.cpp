#include <iostream>
using namespace std;
typedef long long LL;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    LL n;
    LL k[10];
    REP(i,10) k[i]=0;
    cin >>n;
    REP(i,n) {
        int a; cin >>a;
        k[a]++;
    }

    if (k[0]==0) {
        cout <<"-1" <<endl;
        return 0;
    }

    LL rem, n0, n1, n2;
    rem = n0 = n1 = n2 = 0;
    REP(i,10) {
        REP(j,k[i]) rem+=i, rem%=3;
        if (i%3==0) n0+=k[i];
        if (i%3==1) n1+=k[i];
        if (i%3==2) n2+=k[i];
    }
    if (rem==2 and n2>=1) {rem=0; n2--;}
    if (rem==2 and n1>=2) {rem=0; n1-=2;}
    if (rem==1 and n1>=1) {rem=0; n1--;}
    if (rem==1 and n2>=2) {rem=0; n2-=2;}

    string out = "";
    for(int i=9;i>=0;i--) {
        REP(j,k[i]) {
            if (i%3==0 and n0>0) {out+=('0'+i); n0--;}
            if (i%3==1 and n1>0) {out+=('0'+i); n1--;}
            if (i%3==2 and n2>0) {out+=('0'+i); n2--;}
        }
    }
    if (out[0]=='0') cout <<"0" <<endl;
    else             cout <<out <<endl;

    return 0;
}
