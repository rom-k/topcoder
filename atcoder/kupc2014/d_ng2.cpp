#include <iostream>
#include <string>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

#define MAXN 100005
#define MOD 1000000007
typedef long long LL;

LL nCr(int n, int r) {
    r = r < n - r ? r : n - r;
    if (r == 0) return 1;
    if (r == 1) return n;

    int numerator[MAXN];
    int denominator[MAXN];
    for (int k = 0; k < r; k++) {
        numerator[k] = n - r + k + 1;
        denominator[k] = k + 1;
    }

    for (int p = 2; p <= r; p++) {
        if (p==7) cout <<" p=" <<p <<endl;
        int pivot = denominator[p - 1];
        if (p==7) cout <<" pivot=" <<pivot <<endl;
        if (pivot > 1) {
            int offset = (n - r) % p;
            if (p==7) cout <<" offset=" <<offset <<endl;
            for (int k = p - 1; k < r; k += p) {
                if (p==7) cout <<" k-offset=" <<k-offset <<endl;
                numerator[k - offset] /= pivot;
                denominator[k] /= pivot;
            }
        }
    }

    LL ret = 1;
    for (int k = 0; k < r; k++) {
        if (numerator[k] > 1) {
            ret *= numerator[k];
            ret %= MOD;
        }
    }

    cout <<"DEBUG::: " <<n <<"C" <<r <<" = " <<ret <<endl;
    REP(k,r) cout <<" " <<numerator[k];
    cout <<endl;

    return ret;
}

int main() {
    string s1, s2;
    int d1, d2;
    cin >> s1;
    cin >> d1;
    cin >> s2;
    cin >> d2;

    int total_count = s1.size();
    int same_count = 0;
    REP(i, total_count) if (s1[i] == s2[i]) same_count++;
    int diff_count = total_count - same_count;

    LL ans;
    int total_d = d1 + d2;
    int same_d1 = (total_d - diff_count) / 2;
    int diff_d1 = d1 - same_d1;

    if (diff_count < total_d
    && (total_d - diff_count) % 2 == 0
    && diff_d1 <= diff_count
    && same_d1 <= same_count) {
        ans = 1;
        ans *= nCr(diff_count, diff_d1);
        ans %= MOD;
        ans *= nCr(same_count, same_d1);
        ans %= MOD;
    }
    else {
        ans = 0;
    }

    cout <<ans <<endl;
    return 0;
}
