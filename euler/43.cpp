#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

int divr[] = {0, 2, 3, 5, 7, 11, 13, 17};

int main() {
    LL ret   = 0;
    vector<int> vi;
    for (int i=0;i<10;i++) vi.push_back(i);
    do {
        bool ok = true;
        for (int i=1;i<8;i++) {
            if ((vi[i] * 100 + vi[i+1] * 10 + vi[i+2]) % divr[i] != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            LL a = 0;
            for (int i=0;i<10;i++) {
                a *= 10;
                a += vi[i];
            }
            ret += a;
        }
    } while (next_permutation(vi.begin(), vi.end()));
    cout <<ret <<endl;
    return 0;
}
