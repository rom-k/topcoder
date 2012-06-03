#include <iostream>
#include <vector>
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

// make_prime_list function : using make_sieve func
void make_prime_list(vector<long long> &p, long long n) {
    vector<bool> s(n+1, false);
    make_sieve(s);
    for (long long i=0;i<n+1;i++)
        if (s[i]) p.push_back(i);
}

int main() {
    LL N = 1000000;

    vector<bool> s(N+1, false);
    make_sieve(s);

    vector<LL> p;
//    make_prime_list(p, N);
    for (long long i=0;i<s.size();i++)
        if (s[i]) p.push_back(i);
    LL n = p.size();

    LL ret;
    vector<LL> vl(n, 0);
    for (LL i=0;i<n;i++) {
        for (LL j=0;j<n;j++) {
            if (n <= j+i) break;
            if (N < vl[j]) break;
            vl[j] += p[j+i];
            if (N < vl[j]) break;
            if (s[vl[j]]) ret = vl[j];
        }
    }

    cout <<ret <<endl;
    return 0;
}
