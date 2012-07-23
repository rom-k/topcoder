#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >>n;

    int k;
    set<int> s;
    for (int i=0;i<n;i++) {
        cin >>k;

        set<int>::iterator itlow, itup;
        itlow = s.lower_bound(k);
        itup  = s.upper_bound(k);
        if (itlow != s.end()) {
            if (itlow == itup) itup++;
            s.erase(itlow, itup);
        }

        s.insert(k);
    }

    cout <<s.size() <<endl;

    return 0;
}
