#include "grader.h"
#include <algorithm>
#include <set>
#include <vector>
//#include <iostream> //DEBUG
typedef long long LL;
using namespace std;

void schedule(int W, int N, int X[], int D[]) {
    set<pair<LL,int> > cp;
    for (int i=0;i<N;i++) {
        cp.insert( pair<LL,int>(max(0, X[i]-D[i]+1), i) );
        cp.insert( pair<LL,int>(min(W, X[i]+D[i]  ), i+N) );
    }

    LL yaruki = 0;
    LL L[N+1], L_keep[N+1], R_keep[N+1];
    for (int i=0;i<N+1;i++) {L[i]=-1;L_keep[i]=-1;R_keep[i]=-1;}
    for (set<pair<LL,int> >::iterator it=cp.begin();it!=cp.end();it++) {
        LL day = (*it).first;
        LL i   = (*it).second;
        //bool is_start = (day == max(0,X[i]-D[i]+1));
        bool is_start = (i < N);
        if (!is_start) i-=N;
//        cout <<"DEBUG::: day     =" <<day <<endl;
//        cout <<"DEBUG::: i       =" <<i <<endl;
//        cout <<"DEBUG::: is_start=" <<is_start <<endl;

        if (is_start) {
            yaruki++;
            L[yaruki] = day;
//            cout <<"DEBUG:::   => L[" <<yaruki <<"]=" <<day <<endl;
        }
        else {
            LL R = day-1;
//            cout <<"DEBUG:::  L_keep=" <<L_keep[yaruki] <<endl;
//            cout <<"DEBUG:::  R_keep=" <<R_keep[yaruki] <<endl;
//            cout <<"DEBUG:::   //=> L[" <<yaruki <<"]=" <<L[yaruki] <<endl;
//            cout <<"DEBUG:::  L     =" <<L[yaruki] <<endl;
//            cout <<"DEBUG:::  R     =" <<R <<endl;
            if ((L_keep[yaruki] < 0
            or  R_keep[yaruki] - L_keep[yaruki] < R - L[yaruki])
            and L[yaruki] <= R) {
                L_keep[yaruki] = L[yaruki];
                R_keep[yaruki] = R;
//                cout <<"DEBUG:::   => L_keep=" <<L_keep[yaruki] <<endl;
//                cout <<"DEBUG:::   => R_keep=" <<R_keep[yaruki] <<endl;
            }
            yaruki--;
        }
    }

    for (int i=1;i<=N;i++) {
        if (L_keep[i]<0) {
            answer(i, 0, 0);
        }
        else {
            answer(i, L_keep[i], R_keep[i]);
        }
    }
}

