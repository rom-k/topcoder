#include <iostream>
using namespace std;

#define n_MAX 105
int n;
int t[n_MAX][n_MAX];

int main(void) {
    cin >>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<i+1;j++)
            cin >>t[i][j];

    for (int i=n-2;i>=0;i--)
        for (int j=0;j<i+1;j++) {
            t[i][j] += max(t[i+1][j], t[i+1][j+1]);
        }

    cout <<t[0][0] <<endl;
    return 0;
}
