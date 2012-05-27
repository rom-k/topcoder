#include <iostream>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
typedef long long LL;

int N;
int x[2005];
LL y[2005];

void d_and_c (int a, int c) {
    if (a >= c) return;

    int b = x[a];
    REPS(i,a+1,b) y[i] -= b-i;
    d_and_c(a+1, b);
    d_and_c(b, c);
}

//bool test () {
//    bool ok = true;
//    REP(i,N-1) {
//        int i_view = x[i];
//        REPS(j,i+1,N) {
//            LL a = (LL)(i_view - i) * (LL)(y[j]      - y[i]);
//            LL b = (LL)(j      - i) * (LL)(y[i_view] - y[i]);
//            if ((j      < i_view and a >= b)
//            or  (i_view < j      and a >  b)) {
//                cerr <<"ERROR:::  i  j  i_view = "
//                    <<i <<" " <<j <<" " <<i_view <<endl
//                    <<"ERROR::: yi yj yi_view = "
//                    <<y[i] <<" " <<y[j] <<" " <<y[i_view] <<endl;
//                ok = false;
//            }
//        }
//    }
//    return ok;
//}

int main() {
    int T;
    cin >>T;
    cin.ignore();

    for(int t=1; t<=T; t++) {
        cin >>N;
        REP(i,N-1) cin >>x[i];
        REP(i,N-1) x[i]--;
        REP(i,N) y[i] = 500000000;

        bool imp = false;
        REP(i,N-1) REPS(j,i+1,x[i]) if (x[i] < x[j]) imp = true;
        if (imp) {
            cout <<"Case #" <<t <<": Impossible" <<endl;
            continue;
        }

        // devide and conquer
        d_and_c(0, N-1);

//        // test
//        cerr <<"ERROR::: input :";
//        REP(i,N-1) cerr <<" " <<x[i];
//        cerr <<endl;
//        if (!test()) cerr <<"ERROR::: test not passed." <<endl;

        cout <<"Case #" <<t <<":";
        REP(i,N) cout <<" " <<y[i];
        cout <<endl;
    }
    return 0;
}
