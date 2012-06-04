#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;

// make_sieve function : to specify prime numbers
void make_sieve(vector<bool> &s) {
    long long n = s.size();
    for (long long i=0;i<n;i++) s[i] = true;
    s[0] = s[1] = false;

    for (long long i=2;i*i<n;i++) {
        if (!s[i]) continue;
        for (long long j=2;i*j<n;j++) s[i*j] = false;
    }
}

int main() {
    LL n = 1000000;
    vector<bool> s(n,true);

    make_sieve(s);

    stringstream ss;
    map<string,int> num;
    map<string,LL> small;
    int ret = -1;

    for (int i=n/10;i<n;i++) {
        if (!s[i]) continue;

        ss <<i;
        string s = ss.str();

        for (int j=0;j<10;j++) {
            char c1 = '0' + j;
            string s1 = s;

            int num_x = 0;
            for (int k=0;k<s1.size();k++) {
                if (s1[k] == c1) {
                    s1[k] = 'x';
                    num_x++;
                }
            }
            if (num_x < 3) continue;

            if (num.find(s1) == num.end()) {
                num[s1] = 1;
                small[s1] = i;
            }
            else {
                num[s1]++;
                if (num[s1] >= 7) ret = small[s1];
            }

            if (0 < ret) break;
        }
        if (0 < ret) break;
    }

    cout <<ret <<endl;
    return 0;
}
