#include <iostream>
using namespace std;
typedef long long LL;

int main() {
    LL n, m;
    cin >>n >>m;
    int x[m], y[m];
    for (int i=0;i<m;i++) cin >>x[i] >>y[i];

    int ret = -1;
    bool a[n+4][n+4];
    for (int i=0;i<n+4;i++) for (int j=0;j<n+4;j++) a[i][j]=false;
    int dx[] = {-1,-1,-1, 0, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1,-1, 0, 1,-1, 0, 1};
    for (int i=0;i<m;i++) {
        int xi = x[i]+1;
        int yi = y[i]+1;
        a[xi][yi] = true;
        for (int j=0;j<9;j++) {
            int dxj = dx[j];
            int dyj = dy[j];
            bool ok = true;
            for (int k=0;k<9;k++) {
                int dxk = dx[k];
                int dyk = dy[k];
                if (!a[xi+dxj+dxk][yi+dyj+dyk]) {ok = false; break;}
            }
            if (ok) {ret = i+1; break;}
        }
        if (0<ret) break;
    }

    cout <<ret <<endl;
    return 0;
}
