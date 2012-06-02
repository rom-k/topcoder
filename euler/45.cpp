#include <iostream>
using namespace std;
typedef long long LL;
#define t(n) n * (n + 1) / 2
#define p(n) n * (3 * n - 1) / 2
#define h(n) n * (2 * n - 1)

int main() {
    LL t = 40755;
    LL p = 40755;
    LL h = 40755;
    LL nt = 285;
    LL np = 165;
    LL nh = 143;
    while (t != p or t != h or t <= 40755) {
        while ((t == p and t == h)
            or t < p or t < h) {
            t = t(++nt);
        }
        while (p < t or p < h) {
            p = p(++np);
        }
        while (h < t or h < p) {
            h = h(++nh);
        }
    }
    cout <<t <<endl;
    return 0;
}
