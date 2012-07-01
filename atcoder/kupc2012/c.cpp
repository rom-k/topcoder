#include <iostream>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
    int Nusa, Nboat, Nbad;
    cin >>Nusa >>Nboat;
    int m[Nboat];
    int usa[Nboat][Nusa];
    REP(i,Nboat) {
        cin >>m[i];
        REP(j,m[i]) cin >>usa[i][j];
    }
    cin >>Nbad;
    bool bad[Nusa+1][Nusa+1];
    REP(i,Nusa+1) REP(j,Nusa+1) bad[i][j] = false;
    REP(i,Nbad) {
        int p, q;
        cin >>p >>q;
        bad[p][q] = true;
        bad[q][p] = true;
    }

    int cnt = 0;
    REP(i,Nboat) {
        int mem = m[i];
        REP(j,mem) {
            int usa0 = usa[i][j];
            bool hukigen = false;
            REP(k,mem) if(bad[usa[i][j]][usa[i][k]])
                hukigen = true;
            if (hukigen) cnt++;
        }
    }
    cout <<cnt <<endl;

    return 0;
}
