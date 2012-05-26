#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while(1) {
        int n, k;
        cin >>n >>k;
        if (n==0 and k==0) break;

        vector<int> x(n, 0);
        for (int i=0;i<n;i++) cin >>x[i];

        sort(x.begin(), x.end());

        int sum = 0;
        for (int i=0;i<k;i++) {
            sum += x[i];
        }
        cout <<sum <<endl;
    }
    return 0;
}
