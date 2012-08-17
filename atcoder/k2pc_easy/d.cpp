#include <iostream>
#include <math.h>
using namespace std;
typedef long long LL;

#define REP(i,n) for(int i=0;i<n;i++)
#define REPS(i,s,n) for(int i=s;i<n;i++)

int main() {
    int K, N;
    cin >>K >>N;
    K++;
    int p[N], q[N];
    REP(i,N) cin >>p[i] >>q[i];

    LL dat[(int)pow(2,K)-1];
    REP(i,pow(2,K)-1) dat[i]=1;

    for(int i=pow(2,K-1)-2;i>=0;i--)
        dat[i]+=dat[i*2+1]+dat[i*2+2];

    REP(i,N) {
        int k = pow(2,p[i])-1 + q[i]-1;
        LL sub = dat[k];
        while(1) {
            if (dat[k]==0) break;
            dat[k] -= sub;
            if (k==0) break;
            k = (int)(k-1)/2;
        }
    }

    cout <<dat[0] <<endl;

    return 0;
}
