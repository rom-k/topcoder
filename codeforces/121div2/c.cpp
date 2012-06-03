#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    int m = 'z'-'a'+1;
    int a[m][m];
    for (int i=0;i<m;i++)
        for (int j=0;j<m;j++)
            a[i][j] = 0;

    cin >>n;
    for (int i=0;i<n;i++) {
        string s;
        cin >>s;

        int ns = s.size();
        int first = s[0]    - 'a';
        int last  = s[ns-1] - 'a';

        for (int j=0;j<m;j++)
            if (a[j][first] > 0)
                a[j][last] = max(a[j][last], a[j][first] + ns);
        a[first][last] = max(a[first][last], ns);
    }

    int ret = 0;
    for (int i=0;i<m;i++) {
        ret = max(ret, a[i][i]);
    }

    cout <<ret <<endl;
    return 0;
}
