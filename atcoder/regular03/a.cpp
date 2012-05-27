#include <stdio.h>
#include <iostream>
using namespace std;
#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    int N;
    cin >>N;
    string r;
    cin >>r;

    double sum = 0;
    REP(i,N) sum += (r[i] == 'F') ? 0 : 'E'-r[i];

    printf("%.9lf\n", sum/N);

    return 0;
}
