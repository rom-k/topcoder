#include <iostream>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;

int main(void) {
    LL ret = -1;
    set<LL> pr;
    vector<int> vi;
    vi.push_back(0); //0
    vi.push_back(0); //1

    for (LL i=2;true;i++) {
        if (vi.size() <= i) vi.push_back(0); //normal_flag

        bool is_prime = true;
        if (vi[i] & 2) is_prime = false;
        for (set<LL>::iterator it=pr.begin();
             it!=pr.end();
             it++) {
            if (i % (*it) == 0) is_prime = false;
            if (!is_prime) break;
        }

        if (is_prime) {
            vi[i] |= 1; //prime_flag
            pr.insert(i);
        }
        else {
            if (i % 2 == 1) {
                bool flag = true;
                for (set<LL>::iterator it=pr.begin();
                     it!=pr.end();
                     it++) {
                    if (vi[i - (*it)] & 2) {
                        //ret = i;
                        flag = false;
                        break;
                    }
                }
                if (flag) ret = i;
            }
        }

        if (i % 2 == 0
        and (LL)sqrt(i/2) * (LL)sqrt(i/2) == i/2) {
            vi[i] |= 2; //twice_square_flag
        }

        if (0 < ret) break;
    }
    cout <<ret <<endl;
    return 0;
}
