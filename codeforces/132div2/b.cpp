#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    int n, m, k, A, B;
    cin >>n;
    int x[n];
    REP(i,n) cin >>x[i];
    sort(x,x+n);
    cin >>m;
    int y[m];
    REP(i,m) cin >>y[i];
    sort(y,y+m);
    cin >>k;
    int z[k];
    REP(i,k) cin >>z[i];
    sort(z,z+k);
    cin >>A >>B;

    double r1=x[n-1];
    double p2=z[0];
    double ret=0;
    REP(i,m) ret=max(ret, B*y[i]*r1*r1/(A*p2+B*y[i]));
    printf("%.12f\n",sqrt(ret));

    return 0;
}
