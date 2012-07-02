#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >>n >>m;

    int k[m];
    if (m % 2 == 0) {
        for (int i=0;i<m/2;i++) {
            k[2*i  ] = m / 2 - i;
            k[2*i+1] = m / 2 + i + 1;
        }
    }
    else {
        k[0] = m / 2 + 1;
        for (int i=0;i<m/2;i++) {
            k[2*i+1] = m / 2 - i;
            k[2*i+2] = m / 2 + i + 2;
        }
    }

    for (int i=0;i<n;i++)
        cout <<k[i % m] <<endl;

    return 0;
}
