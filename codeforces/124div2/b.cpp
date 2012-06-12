#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

int _gcd(int a, int b) {
    if (a < b) { int c = a; a = b; b = c; }
    if (b == 0) return a;
    return _gcd(b, a % b);
}

int main() {
    int n, m;
    cin >>n >>m;
    n++;
    m++;
    int l = max(n,m);
    int a[l], b[l];
    for (int i=0;i<l;i++) a[i] = 0;
    for (int i=0;i<l;i++) b[i] = 0;
    for (int i=n-1;i>=0;i--) cin >>a[i];
    for (int i=m-1;i>=0;i--) cin >>b[i];

    string ret = "1/1";
    for (int i=l-1;i>=0;i--) {
        if      (a[i] == 0 and b[i] == 0) continue;
        else if (a[i] >  0 and b[i] == 0) {
            if (b[m-1] > 0) ret = "Infinity";
            else            ret = "-Infinity";
        }
        else if (a[i] <  0 and b[i] == 0) {
            if (b[m-1] > 0) ret = "-Infinity";
            else            ret = "Infinity";
        }
        else if (a[i] == 0              ) ret = "0/1";
        else {
            int gcd = _gcd(abs(a[i]),abs(b[i]));
            if (b[i] < 0) gcd *= -1;
            stringstream ss;
            ss <<a[i]/gcd <<"/" <<b[i]/gcd;
            ret = ss.str();
        }
        break;
    }

    cout <<ret <<endl;
    return 0;
}
