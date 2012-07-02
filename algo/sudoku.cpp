#include <iostream>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int a[9][9][9];
int b[9][9];

void disp(bool slp) {
    cout <<"------------" <<endl;
    REP(i,9) {
        REP(j,9) {
            if (b[i][j]<0) cout <<".";
            else           cout <<b[i][j]+1;
            if (j%3==2) cout <<"|";
        }
        cout <<endl;
        if (i%3==2) cout <<"------------" <<endl;
    }
    if (slp) usleep(100000);
}

void disp_detail(bool slp) {
    cout <<"--- --- ---|--- --- ---|--- --- ---|" <<endl;
    REP(i,9) {
        REP(p,3) {
            REP(j,9) {
                REP(q,3) {
                    if (0<a[i][j][p*3+q]) cout <<p*3+q+1;
                    else                  cout <<".";
                }
                if (j%3==2) cout <<"|";
                else        cout <<" ";
            }
            cout <<endl;
        }
        if (i%3==2) cout <<"--- --- ---|--- --- ---|--- --- ---|" <<endl;
        else        cout <<"           |           |           |" <<endl;
    }
    if (slp) usleep(100000);
}

int main() {
    /* initialize */
    REP(i,9)REP(j,9)REP(k,9) a[i][j][k]=1;
    REP(i,9)REP(j,9) b[i][j]=-1;

    /* input */
    REP(i,9) {
        string s;
        getline(cin,s);
        REP(j,9) if (j < s.size() and s[j] != ' ') {
            REP(k,9) a[i][j][k] = 0;
            a[i][j][s[j]-'1'] = 1;
            b[i][j] = s[j]-'1';
        }
    }

    bool ok = false;
    while (!ok) {
        ok = true;

        /* display current status */
        disp(true);
        //disp_detail(true);

        /* step1 check for used */
        REP(i,9)REP(j,9) {
            if (b[i][j]<0) continue;
            int c = b[i][j];
            /* check vertical */
            REP(i2,9) if (b[i2][j]<0 and a[i2][j][c]==1) a[i2][j][c] = 0;
            /* check horizontal */
            REP(j2,9) if (b[i][j2]<0 and a[i][j2][c]==1) a[i][j2][c] = 0;
            /* check little square */
            REP(p,3)REP(q,3) {
                int i2=(i/3)*3+p; int j2=(j/3)*3+q;
                if (b[i2][j2]<0 and a[i2][j2][c]==1) a[i2][j2][c] = 0;
            }
        }

        /* step2 check for only */
        /* check vertical */
        REP(j,9)REP(c,9) {
            int i1, sum = 0;
            REP(i,9) if (a[i][j][c]==1) {sum++; i1=i;}
            if (sum==1 and b[i1][j]!=c) {
                REP(k,9) a[i1][j][k] = 0;
                a[i1][j][c] = 1;
                cout <<"step1v set b[" <<i1 <<"][" <<j <<"] = " <<c+1 <<endl;
            }
        }
        /* check horizontal */
        REP(i,9)REP(c,9) {
            int j1, sum = 0;
            REP(j,9) if (a[i][j][c]==1) {sum++; j1=j;}
            if (sum==1 and b[i][j1]!=c) {
                REP(k,9) a[i][j1][k] = 0;
                a[i][j1][c] = 1;
                cout <<"step1h set b[" <<i <<"][" <<j1 <<"] = " <<c+1 <<endl;
            }
        }
        /* check little square */
        REP(p,3)REP(q,3)REP(c,9) {
            int i1, j1, sum = 0;
            REP(r,3)REP(s,3) {
                int i=p*3+r; int j=q*3+s;
                if (a[i][j][c]==1) {sum++; i1=i; j1=j;}
            }
            if (sum==1 and b[i1][j1]!=c) {
                REP(k,9) a[i1][j1][k] = 0;
                a[i1][j1][c] = 1;
                cout <<"step1s set b[" <<i1 <<"][" <<j1 <<"] = " <<c+1 <<endl;
            }
        }

        /* step3 assumption */
        //TODO

        /* update table b */
        REP(i,9)REP(j,9) {
            if (0<b[i][j]) continue;
            int c, sum = 0;
            REP(k,9) {
                sum += a[i][j][k];
                if (a[i][j][k]==1) c = k;
            }
            if (sum==1) b[i][j] = c;
        }

        /* check for completion */
        REP(i,9)REP(j,9) {
            if (b[i][j]<0) {
                ok = false;
                break;
            }
        }
    }

    disp(false);
    return 0;
}
