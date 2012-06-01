#include <iostream>
#include <set>
using namespace std;
#define p(n) (n*(3*n-1)/2)

int n;
int r;
int diff;
set<int> se;

int add_p(int target) {
    //TODO
}

int _add_p() {
    int ret = n * (3 * n - 1) / 2;
    diff = ret - r;
    r = ret;
    se.insert(ret);
    return ret;
}

int main() {
    n = 1;
    r = 0;
    int ret = -1;
    while (true) {
        //TODO
//        string s;
//        cin >>s;
//        if (s == "") break;

//        int n = 0;
//        for (int i=0;i<s.size();i++) n += s[i] - 'A' + 1;
//        while (k < n) {
//            k *= (j + 2);
//            k /= j;
//            j++;
//            se.insert(k);
        }
        if (se.find(n) != se.end()) ret++;
    }
    cout <<ret <<endl;
    return 0;
}
