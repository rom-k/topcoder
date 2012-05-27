#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
#define REPE(it,c,T) for(T::iterator it = c.begin(); it != c.end(); it++)

struct _status {
    int t;
    int x;
    int y;
    int x_from;
    int y_from;
    double l;
    inline bool operator < (const _status a) const {
        if (l != a.l) { return l < a.l; }
        else          { return t > a.t; }
    }
};

int main() {
    int N, M;
    cin >>N >>M;
    string c[N];
    REP(i,N) cin >>c[i];

    int sx, sy, gx, gy;
    REP(y,N) REP(x,M) {
        if (c[y][x] == 's') sx = x, sy = y;
        if (c[y][x] == 'g') gx = x, gy = y;
    }

    _status st0;
    st0.t = 0;
    st0.x = sx;
    st0.y = sy;
    st0.x_from = 0;
    st0.y_from = 0;
    st0.l = 10.;
    priority_queue<_status> qu;
    qu.push(st0);

    // dijkstra?
    double ret = -1;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = { 0,-1, 0, 1};
    while (0 < qu.size()) {
        _status st = qu.top(); qu.pop();

        // goal
        if (st.x == gx and st.y == gy) {
            ret = st.l;
            break;
        }

        // remove duplications
        if (0 < qu.size()) {
            _status st2 = qu.top();
            while (st.t == st2.t
              and st.x == st2.x
              and st.y == st2.y) {
                qu.pop();
                st2 = qu.top();
            }
        }

        // move to 4 directions
        REP(i,4) {
            _status st1;
            st1.x = st.x + dx[i];
            st1.y = st.y + dy[i];
            if (st1.x < 0 or M <= st1.x
            or  st1.y < 0 or N <= st1.y) continue;
            if (st.x_from == st1.x
            and st.y_from == st1.y) continue;
            st1.x_from = st.x;
            st1.y_from = st.y;
            st1.t = st.t + 1;
            st1.l = c[st1.y][st1.x] - '0';
            REP(j,st1.t) st1.l *= 0.99;
            st1.l = min(st1.l, st.l);
            qu.push(st1);
        }
    }

    printf("%.9lf\n", ret);
    return 0;
}
