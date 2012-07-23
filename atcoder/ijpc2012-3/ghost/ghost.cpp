#include <algorithm>
#include "grader.h"
#include "ghost.h"
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

void FindGhost(
    int N,
    double Cx[],double Cy[],double Cz[],
    double Ty[],double Tz[]
) {
    double minTy = Ty[0];
    double maxTy = Ty[0];
    double minTz = Tz[0];
    double maxTz = Tz[0];
    REPS(i,1,N) {
        minTy = min(minTy,Ty[i]);
        maxTy = max(maxTy,Ty[i]);
        minTz = min(minTz,Tz[i]);
        maxTz = max(maxTz,Tz[i]);
    }

    int i_minTy, i_maxTy, i_minTz, i_maxTz;
    double j_minTy, j_maxTy, j_minTz, j_maxTz;
    i_minTy = i_maxTy = i_minTz = i_maxTz = 0;
    j_minTy = (Cy[0]-minTy)/Cx[0];
    j_maxTy = (maxTy-Cy[0])/Cx[0];
    j_minTz = (Cz[0]-minTz)/Cx[0];
    j_maxTz = (maxTz-Cz[0])/Cx[0];
    REPS(i,1,N) {
        if ( j_minTy < (Cy[i]-minTy)/Cx[i] )
           { i_minTy=i; j_minTy=(Cy[i]-minTy)/Cx[i]; }
        if ( j_maxTy < (maxTy-Cy[i])/Cx[i] )
           { i_maxTy=i; j_maxTy=(maxTy-Cy[i])/Cx[i]; }
        if ( j_minTz < (Cz[i]-minTz)/Cx[i] )
           { i_minTz=i; j_minTz=(Cz[i]-minTz)/Cx[i]; }
        if ( j_maxTz < (maxTz-Cz[i])/Cx[i] )
           { i_maxTz=i; j_maxTz=(maxTz-Cz[i])/Cx[i]; }
    }

    double s1, s2;
    double gx, gy, gz;
    s1 = ( (Cx[i_maxTy]-0) * (minTy-maxTy) ) / 2;
    s2 = ( (Cx[i_maxTy]-0) * (maxTy-Cy[i_minTy])
         - (Cy[i_maxTy]-maxTy) * (0-Cx[i_minTy]) ) / 2;
    gx =     0 + (Cx[i_minTy]-    0) * s1 / (s1+s2);
    gy = minTy + (Cy[i_minTy]-minTy) * s1 / (s1+s2);
    s1 = ( (Cx[i_maxTz]-0) * (minTz-maxTz)
         - (Cz[i_maxTz]-maxTz) * (0-0) ) / 2;
    s2 = ( (Cx[i_maxTz]-0) * (maxTz-Cz[i_minTz])
         - (Cz[i_maxTz]-maxTz) * (0-Cx[i_minTz]) ) / 2;
    gz = minTz + (Cz[i_minTz]-minTz) * s1 / (s1+s2);
    if (s1+s2 == 0) gz = 0;

    answer(gx, gy, gz);
}
