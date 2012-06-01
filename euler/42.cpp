#include <iostream>
#include <set>
using namespace std;

int main() {
    int j = 1, k = 1;
    int ret = 0;
    set<int> se;
    se.insert(1);
    while (true) {
        string s;
        cin >>s;
        if (s == "") break;

        int n = 0;
        for (int i=0;i<s.size();i++) n += s[i] - 'A' + 1;
        while (k < n) {
            k *= (j + 2);
            k /= j;
            j++;
            se.insert(k);
        }
        if (se.find(n) != se.end()) ret++;
    }
    cout <<ret <<endl;
    return 0;
}
