#include <iostream>
#include <stdio.h>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {

    int T;
    cin >>T;
    cin.ignore();

    for (int t=1; t<=T; t++) {

        int R, C, M;
        cin >>R >>C >>M;

        bool impossible = false;
        char a[R][C];
        REP(i,R) REP(j,C) a[i][j] = '.';
        a[R-1][C-1] = 'c';

        if (M >= R*C) {
            impossible = true;
        }
        else if (M == R*C-1) {
            REP(i,R) REP(j,C) a[i][j] = '*';
            a[R-1][C-1] = 'c';
        }
        else if (R == 1 or C == 1) {
            REP(i,R) REP(j,C) {
                if (i+j < M) {
                    a[i][j] = '*';
                }
            }
        }
        else if (R == 2 or C == 2) {
            if (M%2 == 1 or R*C == M+2) {
                impossible = true;
            }
            else {
                REP(i,R) REP(j,C) {
                    if (R == 2 and j < M/2
                     or C == 2 and i < M/2)
                    {
                        a[i][j] = '*';
                    }
                }
            }
        }
        else {
            if (R*C == M+2
             or R*C == M+3
             or R*C == M+5
             or R*C == M+7)
            {
                impossible = true;
            }
            else if (R*C == M+4
                  or R*C == M+6
                  or R*C == M+8)
                {
                REP(i,R) REP(j,C) {
                    if (i < R-3 or j < C-3) {
                        a[i][j] = '*';
                    }
                }
                a[R-3][C-3] = '*';
                if (R*C <= M+6) {
                    a[R-3][C-1] = '*';
                    a[R-3][C-2] = '*';
                }
                if (R*C == M+4) {
                    a[R-1][C-3] = '*';
                    a[R-2][C-3] = '*';
                }
            }
            else {
                REP(i,R-2) REP(j,C-2) {
                    if (M <= 0) break;
                    a[i][j] = '*';
                    M--;
                }
                if (M%2 == 1) {
                    a[R-3][C-3] = '.';
                    M++;
                }
                REP(i,R-3) {
                    if (M <= 0) break;
                    a[i][C-2] = '*';
                    a[i][C-1] = '*';
                    M-=2;
                }
                REP(j,C-3) {
                    if (M <= 0) break;
                    a[R-2][j] = '*';
                    a[R-1][j] = '*';
                    M-=2;
                }
            }
        }

        cout <<"Case #" <<t <<":" <<endl;
        if (impossible) {
            cout <<"Impossible" <<endl;
        }
        else {
            REP(i,R) {
                REP(j,C) {
                    cout <<a[i][j];
                }
                cout <<endl;
            }
        }
    }

    return 0;
}
