#include <iostream>
#include <set>
using namespace std;
#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
#define REPE(it,c,T) for(T::iterator it = c.begin(); it != c.end(); it++)

struct _string {
    string s;
    inline bool operator < (const _string a) const {
        int n = s.size();
        int m = a.s.size();
        REP(i,min(n,m)) {
            if      (s[n-1-i] < a.s[m-1-i]) { return true; }
            else if (s[n-1-i] > a.s[m-1-i]) { return false; }
        }
        return n < m;
    }
};

int main() {
    int N;
    cin >>N;
    set<_string> S;
    REP(i,N) {
        string s1;
        cin >>s1;
        _string S1;
        S1.s = s1;
        S.insert(S1);
    }

    REPE(it,S,set<_string>) cout <<(*it).s <<endl;

    return 0;
}
