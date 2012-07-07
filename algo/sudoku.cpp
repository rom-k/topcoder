#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
    int a[9][9];

    /* initialize */
    REP(i,9)REP(j,9) a[i][j] = 0;

    /* input */
    cout <<"Input sudoku(9 lines with 9 chars):" <<endl;
    REP(i,9) {
        string s;
        getline(cin,s);
        REP(j,9) if (j < s.size() and '1' <= s[j] and s[j] <= '9') {
            a[i][j] = s[j]-'0';
        }
    }

    vector<vector<int> > c(9, vector<int>(9, 0));
    REP(i,9)REP(j,9) c[i][j] = a[i][j];
    int row = -1;
    bool next_row = true;
    while(true) {
        if (next_row) {
            row++;
            if (8<row) break;
            REP(j,9) c[row][j] = j+1;
            next_row = false;
        }
        else {
            if (!next_permutation(c[row].begin(), c[row].end())) {
                REP(j,9) c[row][j] = a[row][j];
                row--;
                if (row < 0) break;
                continue;
            }
        }

        bool ok = true;
        REP(j,9) if (a[row][j] != 0 and c[row][j] != a[row][j]) ok = false;
        if (!ok) continue;

        REP(i,9)REP(j,9) if (row != i and c[row][j] == c[i][j]) ok = false;
        if (!ok) continue;

        REP(r,3) {
            int e[10];
            REP(i,10) e[i] = 0;
            REP(p,3)REP(q,3) {
                int cc = c[(int)(row/3)*3+p][r*3+q];
                if (cc==0) continue;
                if (1<++e[cc]) ok = false;
            }
        }
        if (!ok) continue;

        next_row = true;
cout <<row <<":";
REP(j,9) cout <<c[row][j];
cout <<endl;
    }

    cout <<"----- result-" <<endl;
    REP(i,9) {
        REP(j,9) {
            if (j%3==0) cout <<"|";
            if (c[i][j]==0) cout <<".";
            else            cout <<c[i][j];
        }
        cout <<endl;
        if (i%3==2) cout <<"------------" <<endl;
    }

    return 0;
}
