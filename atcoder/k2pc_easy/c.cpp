#include <iostream>
#include <math.h>
using namespace std;
typedef long long LL;
typedef long double LD;

LL calc_k (LL i) {
    LL k = (LL)sqrt((LD)i*2);
    if (k*(k-1)/2 < i and i <= k*(k+1)/2) return k;
    else                                  return k+1;
}

LL calc_n (LL i, LL k) {
    return i - k*(k-1)/2;
}

LL calc_m (LL i, LL k) {
    return k*(k+1)/2 - i + 1;
}

LL calc_i (LL m, LL n) {
    LL k = m + n - 1;
    return k*(k-1)/2 + n;
}

int main() {
    LL i1, i2;
    cin >>i1 >>i2;

    LL k1 = calc_k(i1);
    LL m1 = calc_m(i1,k1);
    LL n1 = calc_n(i1,k1);
    LL k2 = calc_k(i2);
    LL m2 = calc_m(i2,k2);
    LL n2 = calc_n(i2,k2);
    LL m = m1+m2;
    LL n = n1+n2;
    LL i = calc_i(m,n);

    cout <<i <<endl;
    return 0;
}
