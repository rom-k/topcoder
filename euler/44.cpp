#include <iostream>
#include <set>
using namespace std;
#define p(n) (n*(3*n-1)/2)

int n;
int n2;
set<int> se;

int _add_p() {
    if (n2 < n) { n2 = n; }
    else        { n2++;   }
    int ret = p(n2);
    se.insert(ret);
    return ret;
}

int add_p(int target) {
    int ret = 0;
    while (ret < target) { ret = _add_p(); }
    return ret;
}

int main() {
    n  = 1;
    n2 = 1;
    int p_cur = 1;
    int p_nxt;
    int D = 0x7F7F7F7F;
    se.insert(p_cur);

    while (true) {
        n++;
        p_nxt = p(n);
        if (D < p_nxt - p_cur) break;

        for (set<int>::reverse_iterator it=se.rbegin();it!=se.rend();it++) {
            int p = (*it);
            if (p_nxt <= p) continue;
            if (D < p_nxt - p) break;
            if (se.find(p_nxt - p) == se.end()) continue;
            add_p(p_nxt + *it);
            if (se.find(p_nxt + p) == se.end()) continue;
            D = p_nxt - p;
cout <<"  => D = " <<D <<endl;
        }

        se.insert(p_nxt);
        p_cur = p_nxt;
    }
    cout <<D <<endl;
    return 0;
}
