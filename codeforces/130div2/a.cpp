#include <iostream>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    string s;
    cin >>s;
    bool b[s.size()];
    REP(i,s.size()) b[i] = true;
    REP(i,s.size()-2) {
        if (s[i]=='W' and s[i+1]=='U' and s[i+2]=='B') {
            b[i] = b[i+1] = b[i+2] = false;
            i+=2;
        }
    }
    bool first = true;
    bool blank = true;
    REP(i,s.size()) {
        if (b[i]) {
            if (blank) {
                if (first) first = false;
                else       cout <<" ";
                blank = false;
            }
            cout <<s[i];
        }
        else blank = true;
    }
    cout <<endl;
    return 0;
}
