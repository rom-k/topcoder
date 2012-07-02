#include <iostream>
using namespace std;
typedef long long LL;

int main() {
    LL N, T, E;
    cin >>N >>T >>E;
    LL x[N];
    for (LL i=0;i<N;i++) cin >>x[i];
    for (LL i=0;i<N;i++) {
        LL k = 1;
        while (1) {
            if (T-E <= k*x[i] and k*x[i] <= T+E) {
                cout <<i+1 <<endl;
                return 0;
            }
            if (T+E < k*x[i]) break;
            k++;
        }
    }
    cout <<-1 <<endl;
    return 0;
}
