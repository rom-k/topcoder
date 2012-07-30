#include <iostream>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    int n, m;
    cin >>n >>m;
    int a, b, cnt;
    a = cnt = 0;
    while(a*a<=n and a<=m) {
        if(a*a*a*a-2*n*a*a+a+n*n-m==0) {
            b = 0;
            while(a*a+b<=n and a+b*b<=m) {
                if(a*a+b==n and a+b*b==m) {
                    cnt++;
                }
                b++;
            }
        }
        a++;
    }
    cout <<cnt <<endl;
    return 0;
}
