#include <iostream>
#include <set>
typedef long long LL;
using namespace std;

#define N 4

int main() {
    set<LL> prime;
    LL n = 1;
    int num = 0;

    while (n++) {
        LL n1 = n;
        set<LL> factor;
        for (set<LL>::iterator it=prime.begin();
             it!=prime.end();
             it++) {
            while (n1 % (*it) == 0) {
                factor.insert(*it);
                n1 /= (*it);
            }
        }

        if (factor.size() == 0) { //prime
            prime.insert(n);
            num = 0;
        }
        else if (factor.size() == N) {
            if (++num == N) break;
        }
        else {
            num = 0;
        }
    }

    cout <<n - N + 1 <<endl;
    return 0;
}
