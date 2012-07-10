//Powerd by http://www2.tokai.or.jp/deepgreen/shortnotes/numberplace/algorithm.htm

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define REPS(i,s,n) for(int i=s;i<n;i++)

int b[10] = {0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x100};
int bitcnt[0x200] = {
    0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,
    1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
    1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
    2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
    1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
    2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
    2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
    3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,
    1,2,2,3,2,3,3,4,2,3,3,4,3,4,4,5,2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,
    2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
    2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
    3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,
    2,3,3,4,3,4,4,5,3,4,4,5,4,5,5,6,3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,
    3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,
    3,4,4,5,4,5,5,6,4,5,5,6,5,6,6,7,4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,
    4,5,5,6,5,6,6,7,5,6,6,7,6,7,7,8,5,6,6,7,6,7,7,8,6,7,7,8,7,8,8,9,
};
int b2num[0x200] = {
    0,1,2,0,3,0,0,0,4,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};
int tuple[27][9] = {
    { 0, 1, 2, 3, 4, 5, 6, 7, 8},
    { 9,10,11,12,13,14,15,16,17},
    {18,19,20,21,22,23,24,25,26},
    {27,28,29,30,31,32,33,34,35},
    {36,37,38,39,40,41,42,43,44},
    {45,46,47,48,49,50,51,52,53},
    {54,55,56,57,58,59,60,61,62},
    {63,64,65,66,67,68,69,70,71},
    {72,73,74,75,76,77,78,79,80},

    { 0, 9,18,27,36,45,54,63,72},
    { 1,10,19,28,37,46,55,64,73},
    { 2,11,20,29,38,47,56,65,74},
    { 3,12,21,30,39,48,57,66,75},
    { 4,13,22,31,40,49,58,67,76},
    { 5,14,23,32,41,50,59,68,77},
    { 6,15,24,33,42,51,60,69,78},
    { 7,16,25,34,43,52,61,70,79},
    { 8,17,26,35,44,53,62,71,80},

    { 0, 1, 2, 9,10,11,18,19,20},
    { 3, 4, 5,12,13,14,21,22,23},
    { 6, 7, 8,15,16,17,24,25,26},
    {27,28,29,36,37,38,45,46,47},
    {30,31,32,39,40,41,48,49,50},
    {33,34,35,42,43,44,51,52,53},
    {54,55,56,63,64,65,72,73,74},
    {57,58,59,66,67,68,75,76,77},
    {60,61,62,69,70,71,78,79,80},
};

//void make2d(bool _a[9][9][9], int _b[9][9]) {
//    REP(i,9)REP(j,9) {
//        int sum = 0;
//        REP(k,9) if (_a[i][j][k]) {sum++; _b[i][j] = k;}
//        if (sum!=1) _b[i][j] = -1;
//    }
//}

void disp(int a[81], bool slp) {
    cout <<endl <<"+---+---+---+" <<endl;
    REP(i,9) {
        REP(j,9) {
            if (j==0) cout <<"|";
            if (b2num[a[i*9+j]]==0) cout <<".";
            else                  cout <<b2num[a[i*9+j]];
            if (j%3==2) cout <<"|";
        }
        cout <<endl;
        if (i%3==2) cout <<"+---+---+---+" <<endl;
    }
    if (slp) usleep(100000);
}

void disp_detail(int a[81], bool slp) {
    cout <<endl <<"+--- --- ---+--- --- ---+--- --- ---+" <<endl;
    REP(i,9) {
        REP(p,3) {
            REP(j,9) {
                if (j==0) cout <<"|";
                REP(q,3) {
                    if (a[i*9+j] & b[p*3+q+1]) cout <<p*3+q+1;
                    else                       cout <<".";
                }
                if (j%3==2) cout <<"|";
                else        cout <<" ";
            }
            cout <<endl;
        }
        if (i%3==2) cout <<"+--- --- ---+--- --- ---+--- --- ---+" <<endl;
        else        cout <<"|           |           |           |" <<endl;
    }
    if (slp) usleep(100000);
}

void check(int a[81], bool& completed, bool& error) {
    completed = true;
    error = false;
    REP(i,81) { /* for each cell */
        if (bitcnt[a[i]] == 0) error = true;
        if (bitcnt[a[i]] != 1) completed = false;
    }
    REP(i,27) { /* for each tuple */
        int all = 0;
        REP(j,9) all |= a[tuple[i][j]];
        if (all != 0x1ff) error = true;
    }
}

void sbit(int a[81], bool& update, bool& error) {
    update = false;
    error = false;
    REP(i,81) if (bitcnt[a[i]] == 0) error = true;

    REP(i,27)REP(j,9) { /* for each cell in tuple */
        if (bitcnt[a[tuple[i][j]]]==1) {
            int b1 = a[tuple[i][j]];
            REP(k,9) if (j!=k and a[tuple[i][k]] & b1) {
                a[tuple[i][k]] -= b1;
                update = true;
            }
        }
    }
}

void ubit(int a[81], bool& update, bool& error) {
    update = false;
    error = false;
    REP(i,27) { /* for each tuple */
        REPS(j,1,10) { /* for each bit */
            int c, num = 0;
            REP(k,9) if(a[tuple[i][k]] & b[j]) {num++; c=tuple[i][k];}
            if (num == 0) error = true;
            if (num == 1 and a[c] != b[j]) {
                a[c] = b[j];
                update = true;
            }
        }
    }
}

void intersection(int a[81], bool& update, bool& error) {
    update = false;
    error = false;
    REP(i,27)REP(j,27) { /* for each 2 tuples */
        if (i>=j) continue;
        int type[81]; /* cell type */
        REP(k,81) type[k] = 0;
        REP(k,9) type[tuple[i][k]] += 1;
        REP(k,9) type[tuple[j][k]] += 2;
        int flag[4]; /* bit flag for each type */
        REP(k,4) flag[k] = 0;
        REP(k,81) flag[type[k]] |= a[k];
        REPS(k,1,10) { /* for each bit */
            bool b1  = flag[1] & b[k];
            bool b2  = flag[2] & b[k];
            bool b12 = flag[3] & b[k];
            if ((!b1 or !b2) and !b12) error = true;
            if (b1 and b12 and !b2) {
                REP(l,9) {
                    int c = tuple[i][l];
                    if (type[c]==1 and a[c] & b[k]) a[c] -= b[k];
                }
                update = true;
            }
            if (!b1 and b12 and b2) {
                REP(l,9) {
                    int c = tuple[j][l];
                    if (type[c]==2 and a[c] & b[k]) a[c] -= b[k];
                }
                update = true;
            }
        }
    }
}

void en(int a[81], int k, bool& update, bool& error) {
    update = false;
    error = false;
    REP(i,27) { /* for each tuple */
        vector<bool> bl(9, false);
        REP(j,k) bl[9-1-j] = true;
        do {
            int e = 0x00;
            REP(j,9) if (bl[j]) e |= a[tuple[i][j]];
            if (bitcnt[e] == k) {
                REP(j,9) if (!bl[j] and e & a[tuple[i][j]]) {
                    a[tuple[i][j]] &= (0x1ff - e);
                    update = true;
                }
            }
        } while (next_permutation(bl.begin(),bl.end()));
    }
}

void xn(int a[81], int k, bool& update, bool& error) {
    update = false;
    error = false;
    REP(i,27) { /* for each tuple */
        vector<bool> bl(9, false);
        REP(j,k) bl[9-1-j] = true;
        do {
            int e = 0x00;
            REP(j,9) if(bl[j]) e |= (1<<j);
            int m = 0;
            REP(j,9) if (a[tuple[i][j]] & e) m++;
            if (m == k) {
                REP(j,9) if (a[tuple[i][j]] & e
                         and a[tuple[i][j]] & (0x1ff - e)) {
                    a[tuple[i][j]] &= e;
                    update = true;
                }
            }
        } while (next_permutation(bl.begin(),bl.end()));
    }
}

int main() {
    int a[81];

    /* initialize */
    REP(i,81) a[i] = 0x1ff;

    /* input */
    cout <<"Input sudoku(9 lines with 9 chars):" <<endl;
    REP(i,9) {
        string s;
        getline(cin,s);
        REP(j,9) if (j < s.size() and '1' <= s[j] and s[j] <= '9') {
            a[i*9+j] = b[s[j]-'0'];
        }
    }

    bool completed, update, error;
    string msg = "";
    while (true) {
        completed = update = error = false;

        /* debugging */
        if (msg!="") cout <<"update : " <<msg <<endl;

        /* display current status */
        //disp(a, true);
        //disp_detail(a, true);

        /* check for completion */
        msg = "check";
        check(a, completed, error);
        if (completed or error) break;
        if (update) continue;

        /* A2-1: Sbit search */
        msg = "Sbit";
        sbit(a, update, error);
        if (error) break;
        if (update) continue;

        /* A2-2: Ubit search */
        msg = "Ubit";
        ubit(a, update, error);
        if (error) break;
        if (update) continue;

        /* A2-3: Intersection */
        msg = "Intersection";
        intersection(a, update, error);
        if (error) break;
        if (update) continue;

        /* A2-3: E(n) */
        /* A2-4: X(n) */
        msg = "E(2)";
        en(a, 2, update, error);
        if (error) break;
        if (update) continue;

        msg = "X(2)";
        xn(a, 2, update, error);
        if (error) break;
        if (update) continue;

        msg = "E(3)";
        en(a, 3, update, error);
        if (error) break;
        if (update) continue;

        msg = "X(3)";
        xn(a, 3, update, error);
        if (error) break;
        if (update) continue;

        msg = "E(4)";
        en(a, 4, update, error);
        if (error) break;
        if (update) continue;

        msg = "X(4)";
        xn(a, 4, update, error);
        if (error) break;
        if (update) continue;

        /* A2-5: Negation */
        //TODO
        if (error) break;
        if (update) continue;

        /* cannot solve */
        break;
    }

    if (error) {
        cout <<"Sorry, error occured at " <<msg <<"." <<endl;
        return -1;
    }
    else if (!completed) {
        cout <<"Sorry, cannot solve." <<endl;
        return -1;
    }
    else {
        disp(a, false);
    }

    return 0;
}
