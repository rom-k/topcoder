#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long LL;

int _gcd2(LL a, LL b) {
    if (a < b) { LL c = a; a = b; b = c; }
    if (b == 0) return a;
    return _gcd2(b, a%b);
}

int main() {
    LL x, y;
    scanf("%lld/%lld", &x, &y);
    LL gcd = _gcd2(x, y);
    x /= gcd;
    y /= gcd;
    if (y % 2 != 0) {
        x *= 2;
        y *= 2;
    }
    double z = (double)x / (double)y;

    LL k = 1;
    LL n, m;
    bool ok = false;
    if (x < y) {
        if (x == 1 and y == 2) {
            n = 2;
            m = 1;
            ok = true;
        }
    }
    else {
        while (!ok) {
            n = k * y / 2;
            if (n == 1) {
                k++;
                continue;
            }
            if (z * 2 < n - 1) break;
            m = (k * y * (k * y + 2) - 4 * k * x);
            if (m % 8 == 0) {
                m /= 8;
                if (m <= n and 0 < m) {
                    ok = true;
                    break;
                }
            }
            k++;
        }
    }

    if (ok) { cout <<n <<" " <<m  <<endl; }
    else    { cout <<"Impossible" <<endl; }
    return 0;
}
