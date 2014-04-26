#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
typedef long long LL;
#define INF 0x7f7f7f7f;

LL binstr2ll (string str) {
    LL ret = 0;
    int len = str.size();
    REP(i,len) {
        if (str.at(len-i-1) == '1') {
            ret += pow(2, i);
        }
    }
    return ret;
}

int flipcount (LL a, LL b) {
    int ret = 0;
    LL c = a ^ b;
    LL base = 1;
    while (base <= c) {
        if (base & c) {
            c - base;
            ret++;
        }
        base *= 2;
    }
    return ret;
}

int main() {

    int T;
    cin >>T;
    cin.ignore();

    for (int t=1; t<=T; t++) {

        int N, L;
        cin >>N >>L;

        string str_outputs[N], str_devices[N];
        REP(i,N) cin >>str_outputs[i];
        REP(i,N) cin >>str_devices[i];

        LL outputs[N];
        LL devices[N];
        REP(i,N) outputs[i] = binstr2ll(str_outputs[i]);
        REP(i,N) devices[i] = binstr2ll(str_devices[i]);

        sort(devices, devices+N);

        int ans = INF;
        int inf = INF;

        REP(i,N) {
            LL model = devices[i]; // model device
            LL copy[N]; // copy of outputs
            REP(j,N) copy[j] = outputs[j];
            REP(j,N) copy[j] ^= (outputs[0] ^ model);

            sort(copy, copy+N);
            bool match = 1;
            REP(j,N) if (copy[j] != devices[j]) match = 0;

            if (match == 1) {
                ans = min(ans, flipcount(model, outputs[0]));
            }
        }

        if (ans == inf) {
            cout <<"Case #" <<t <<": NOT POSSIBLE" <<endl;
        }
        else {
            cout <<"Case #" <<t <<": " <<ans <<endl;
        }
    }

    return 0;
}
