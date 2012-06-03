#include <iostream>
#include <vector>
using namespace std;

bool same(int a, int b) {
    vector<int> s(10,0);
    vector<int> t(10,0);
    while (a > 0) { s[a%10]++; a/=10; }
    while (b > 0) { t[b%10]++; b/=10; }
    for (int j=0;j<10;j++) if (s[j] != t[j]) return false;
    return true;
}

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
    vector<bool> sve(10005, false);
    make_sieve(sve);

    for (int i=1000;i<9997;i++) {
        for (int d=1;d<(9999-i)/2;d++) {

            if (sve[i] and sve[i+d] and sve[i+2*d]
                and same(i,i+d) and same(i+d,i+2*d)) {
                cout <<i <<i+d <<i+2*d <<endl;
            }
        }
    }
    return 0;
}
