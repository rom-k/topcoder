#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    int T;
    cin >>T;
    cin.ignore();

    for (int t=1; t<=T; t++) {

        double C, F, X;
        double ret = 50005.;
        cin >>C >>F >>X;

        double sum_s = 0.;
        double cps = 2.; //cookies per socond

        while (true) {

            double sec;
            sec = X / cps + sum_s;

            if (ret <= sec) {
                break;
            }

            ret    = sec;
            sum_s += C / cps;
            cps   += F;
        }

        printf("Case #%d: %.07lf\n", t, ret);
    }

    return 0;
}
