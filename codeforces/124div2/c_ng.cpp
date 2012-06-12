#include <iostream>
using namespace std;

int main() {
    string s;
    cin >>s;

    string ret = s.substr(0,1);
    int l = ret.size();
    for (int i=1;i<s.size();i++) {
        while (0 < ret.size() and ret[ret.size()-1] < s[i]) {
            ret = ret.substr(0,ret.size()-1);
        }
        ret += s[i];
    }
    cout <<ret <<endl;

    return 0;
}
