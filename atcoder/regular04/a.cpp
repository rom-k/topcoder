#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >>n;
    int x[n], y[n];
    for (int i=0;i<n;i++) cin >>x[i] >>y[i];

    double ret = 0.;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
        int dx = x[i] - x[j];
        int dy = y[i] - y[j];
        ret = max(ret, sqrt(dx*dx+dy*dy));
    }

    printf("%.8f\n", ret);
    return 0;
}
