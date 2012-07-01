#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >>N >>M;
    int c[N];
    for (int i=0;i<N;i++) c[i] = -1;
    for (int i=0;i<M;i++) {
        int a, b;
        cin >>a >>b;
        c[a-1] = max(c[a-1],b-1);
    }

    int d = -1;
    int e = -1;
    int cnt = 0;
    for (int i=0;i<N;i++) {
        d = max(d,c[i]);
        if (e < i) {e = d; cnt++;}
        if (e < i) {cnt = -1; break;}
    }

    if (cnt < 0) cout <<"Impossible" <<endl;
    else         cout <<cnt <<endl;

    return 0;
}
