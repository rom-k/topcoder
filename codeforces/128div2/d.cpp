#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    double a, b, m, vx, vy, vz;
    cin >>a >>b >>m >>vx >>vy >>vz;
    double x = -vx*m/vy + a/2;
    double z = -vz*m/vy;
    while (x<0 or a<x) {
        if (x<0) x = -x;
        if (a<x) x = 2*a-x;
    }
    while (z<0 or b<z) {
        if (z<0) z = -z;
        if (b<z) z = 2*b-z;
    }
    printf("%.10lf %.10lf\n", x, z);
    return 0;
}
