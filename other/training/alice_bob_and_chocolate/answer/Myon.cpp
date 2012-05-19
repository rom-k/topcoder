#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num[n];
    int dp[n + 1];
    int sum = 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        dp[i + 1] = sum += num[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i] <= sum - dp[i + 1]) continue;
        else
        {
            cout << i << " " << n - i << endl;
            return 0;
        }
    }
    cout << n << " " << 0 << endl;
    return 0;
}
