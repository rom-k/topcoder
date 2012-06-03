#include <iostream>
using namespace std;
typedef long long LL;

int main() {
    LL n = 1000;
    LL ret = 0;
    for (int i=1;i<=n;i++) {
        LL a = 1;
        for (int j=0;j<i;j++) {
            a *= i;
            a %= 10000000000;
        }
        ret += a;
        ret %= 10000000000;
    }
    cout <<ret <<endl;
    return 0;
}
