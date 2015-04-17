#include <iostream>
#include <string.h>
#include <string>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
typedef long long LL;

#define max_N 1005

int main() {
    int T;
    cin >>T;
    cin.ignore();
    
    for(int t=1; t<=T; t++) {
        int Smax;
        string s;
        int n[max_N];
        
        cin >>Smax >>s;
        
        REP(i, Smax + 1) {
            n[i] = s[i] - '0';
        }
        
        int standing = 0;
        int ans = 0;
        
        REP(i, Smax + 1) {
            if (standing < i) {
                ans += i - standing;
                standing = i;
            }
            standing += n[i];
        }
        
        cout <<"Case #" <<t <<": " <<ans <<endl;
    
    }
    return 0;
}
