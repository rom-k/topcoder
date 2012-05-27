#include <iostream>
using namespace std;

int lcs(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    int dp[n1+1][n2+1];
    for (int i1=0;i1<n1+1;i1++) for (int i2=0;i2<n2+1;i2++) dp[i1][i2] = 0;

    for (int i1=0;i1<n1;i1++) for (int i2=0;i2<n2;i2++) {
        if (s1[i1] == s2[i2]) {
            dp[i1+1][i2+1] = dp[i1][i2] + 1;
        }
        else {
            dp[i1+1][i2+1] = max(
                dp[i1+1][i2],
                dp[i1][i2+1]
            );
        }
    }
    return dp[n1][n2];
}

int main() {
    string s1, s2;
    cin >>s1 >>s2;
    cout <<lcs(s1, s2) <<endl;
    return 0;
}

