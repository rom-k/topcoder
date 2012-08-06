#include <iostream>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    int n, m, s;
    cin >>n >>m >>s;

    long long ret=0;
    for(int x=1;x<=min(s,m);x+=2) for(int y=1;y<=min(s,n);y+=2) {
        if (x*y<s or s<x+y-1 or (x*y-s)%4!=0) continue;
        int r=(x*y-s)/4;
        if (r==0) {
            ret+=(m-x+1)*(n-y+1)*((x+1)*(y+1)/2-1);
        }
        else {
            for(int p=1;p<=min(r,(x-1)/2);p++) {
                if (r%p!=0) continue;
                int q=r/p;
                int a=(x-1)/2-p;
                int b=(y-1)/2;
                int c=(x-1)/2;
                int d=(y-1)/2-q;
                if (a<0 or b<0 or c<0 or d<0) continue;
                ret+=(m-x+1)*(n-y+1);
                if (a!=c or b!=d) {
                    ret+=(m-x+1)*(n-y+1);
                }
            }
        }
    }
    cout <<ret <<endl;

    return 0;
}
