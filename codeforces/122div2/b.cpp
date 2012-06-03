#include <iostream>
using namespace std;
typedef long long LL;

LL _gcd2(LL a, LL b) {
    if (a < b) { LL c = a; a = b; b = c; }
    if (b == 0) return a;
    return _gcd2(b, a % b);
}

int main() {
    LL t, n;
    cin >>t;
    for (LL i=0;i<t;i++) {
        cin >>n;
        cout <<4*n / _gcd2(4*n, n+1) + 1 <<endl;
    }

    return 0;
}
