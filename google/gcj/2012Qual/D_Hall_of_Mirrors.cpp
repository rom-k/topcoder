#include <stdio.h>
#include <time.h>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <stack>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <utility>
#include <memory>
#include <functional>
#include <complex>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL> VL;

#define FORE(it, c, T) for(T::iterator it = c.begin(); it != c.end(); it++)
#define FORI(i, n) for(int i = 0; i < (n); i++)
#define FORIS(i, s, n) for(int i = (s); i < (n); i++)
#define CLEAR(a) memset(a, 0, sizeof(a))
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define PB(n) push_back(n)
#define SZ(a) int((a).size())
#define IPOW(a,b) ((long long) pow((double)(a),(double)(b)))
#define PI M_PI
#define EPS 1e-13
#define INF 0x7f7f7f7f

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;
#define DBG3(a, b, c) if (DEBUG) cout <<"DEBUG::: " <<a <<":" <<b <<":" <<c <<endl;

/*
 * _edge struct
 */
struct _edge {
    double x0, y0;
    double x1, y1;
    double x2, y2;
    bool invert;
    
    void initialize (double x00, double y00,
           double x10, double y10,
           double x20, double y20,
           bool invert0)
    {
        x0 = x00; y0 = y00;
        x1 = x10; y1 = y10;
        x2 = x20; y2 = y20;
        invert = invert0;
    }
    _edge (double x00, double y00,
           double x10, double y10,
           double x20, double y20,
           bool invert0)
    {
        initialize(x00, y00, x10, y10, x20, y20, invert0);
    }
    _edge (double x00, double y00,
           double x10, double y10,
           double x20, double y20)
    {
        initialize(x00, y00, x10, y10, x20, y20, false);
    }
    _edge (double x10, double y10,
           double x20, double y20)
    {
        initialize(0, 0, x10, y10, x20, y20, false);
    }
    _edge (const _edge &a) {
        initialize(0, 0, a.x1, a.y1, a.x2, a.y2, false);
    }
    _edge (double x00, double y00,
           const _edge &a)
    {
        initialize(x00, y00, a.x1, a.y1, a.x2, a.y2, false);
    }
    
    inline bool operator < (const _edge a) const {
        return atan2(y1-y0,x1-x0) < atan2(a.y1-y0,a.x1-x0);
    }
    
    bool parallel (_edge a) {
        return (x2-x1)*(a.x2-a.x1) + (y2-y1)*(a.y2-a.y1) > 0;
    }
    bool includes (double x, double y) {
        if (x == x1 and y == y1) return true;
        if (x == x2 and y == y2) return true;
        return fabs((x2-x)/(x1-x) - (y2-y)/(y1-y)) <= EPS;
    }
    bool includes (_edge a) {
        return parallel(a) and includes(a.x1, a.y1);
    }
    double inner_prod (double x, double y) {
        return (x1-x)*(x2-x) + (y1-y)*(y2-y);
    }
    
    double angle1 () {
        if (x1 == x0 and y1 == y0) return -PI;
        if (fabs(y1-y0) < EPS and x1-x0 < 0) return -PI;
        return atan2(y1-y0, x1-x0);
    }
    double angle2 () {
        if (x2 == x0 and y2 == y0) return PI;
        if (fabs(y2-y0) < EPS and x2-x0 < 0) return PI;
        return atan2(y2-y0, x2-x0);
    }
    double length1() {
        return sqrt(pow(y1-y0,2) + pow(x1-x0,2));
    }
    double length2() {
        return sqrt(pow(y2-y0,2) + pow(x2-x0,2));
    }
};

/*
 * get_around function
 * Get edges full circle from a part of edge e0.
 */
void get_around (int H, int W, string blocks[], _edge e0, vector<_edge> &edges) {
    DBG("  get_around");
    DBG3("  (e0.x1:e0.y1)",e0.x1,e0.y1);
    DBG3("  (e0.x2:e0.y2)",e0.x2,e0.y2);
    
    DBG2("  SZ(edges)",SZ(edges));
    FORI(i, SZ(edges)) {
        if (edges[i].includes(e0)) {
            DBG("  => included");
            return;
        }
    }
    
    _edge e = _edge(e0);
    double x0 = e.x1;
    double y0 = e.y1;
    double dx = e.x2 - e.x1;
    double dy = e.y2 - e.y1;
    
    while (e.x2 != x0 or e.y2 != y0) {
        double ddx = -dy;
        double ddy = dx;
        double x3 = e.x2 + 0.5 + 0.5*(dx+dy);
        double y3 = e.y2 + 0.5 + 0.5*(-dx+dy);
        DBG("----");
        DBG3("    (dx    :dy    )",dx,dy);
        DBG3("    (ddx   :ddy   )",ddx,ddy);
        DBG3("    (x3    :y3    )",x3,y3);
        DBG3("    (x3+ddx:y3+ddy)",x3+ddx,y3+ddy);
        
        if (x3 < 0 or W <= x3 or y3 < 0 or H <= y3 or
            x3+ddx < 0 or W <= x3+ddx or y3+ddy < 0 or H <= y3+ddy)
        {
            cout <<"ERROR" <<endl;
            return;
        }
        
        if (blocks[(int)(x3)][(int)(y3)] == '#' and
            blocks[(int)(x3+ddx)][(int)(y3+ddy)] != '#')
        {
            DBG("    ->go straight");
            e.x2 += dx; e.y2 += dy;
        }
        else {
            edges.PB(e);
            DBG("    ->corner");
            DBG3("     add edge (x1,y1)",e.x1,e.y1);
            DBG3("              (x2,y2)",e.x2,e.y2);
            
            if (blocks[(int)(x3)][(int)(x3)] == '#') {
                dx = ddx; dy = ddy;
                DBG("     ->turn right");
            }
            else {
                dx = -ddx; dy = -ddy;
                DBG("     ->turn left");
            }
            e.x1 = e.x2; e.y1 = e.y2;
            e.x2 += dx; e.y2 += dy;
        }
    }
    DBG("----end");
    
    //fix first edge's start point
    if (e.parallel(e0)) {
        FORI(i, SZ(edges)) {
            if (edges[i].x1 == e0.x1 and
                edges[i].y1 == e0.y1 and
                edges[i].parallel(e0))
            {
                edges[i].x1 = e.x1;
                edges[i].y1 = e.y1;
                DBG3("  fix first edge (x1,y1)",e.x1,edges[i].y1);
                DBG3("                 (x2,y2)",e.x2,edges[i].y2);
                return;
            }
        }
    }
    
    edges.PB(e);
    DBG3("  add edge (x1,y1)",e.x1,e.y1);
    DBG3("           (x2,y2)",e.x2,e.y2);
    return;
};

/*
 * _edge_set struct
 */
struct _edge_set {
    double x0;
    double y0;
    set<_edge> edges;
    
    _edge_set (double x00, double y00) {
        x0 = x00; y0 = y00;
    }
    
    void add_edge(double x1d, double y1d, double x2d, double y2d) {
        edges.insert(_edge(x0, y0, x1d, y1d, x2d, y2d));
    }
    void add_edge(_edge a) {
        add_edge(a.x1, a.y1, a.x2, a.y2);
    }
    void remove_edge(double x1d, double y1d, double x2d, double y2d) {
        FORE(it, edges, set<_edge>) {
            if ((*it).x1 == x1d and (*it).y1 == y1d and
                (*it).x2 == x2d and (*it).y2 == y2d)
            {
                edges.erase(it);
                break;
            }
        }
        cout <<"ERROR2" <<endl;
        return;
    }
    void remove_edge(_edge a) {
        remove_edge(a.x1, a.y1, a.x2, a.y2);
    }
};

/*
 * calc_d function
 */
double calc_d (double angle, double x1, double y1, double x2, double y2) {
    double dx12 = x2 - x1;
    double dy12 = y2 - y1;
    return (dx12 * x1 - dy12 * y1) / (dx12 * cos(angle) - dy12 * sin(angle));
}
double calc_d (double angle, _edge e) {
    return calc_d (angle, e.x1, e.y1, e.x2, e.y2);
}

/*
 * expand_edge function
 * Expand edge to new edges by reflection.
 */
void expand_edge (int H, int W,
                  vector<_edge> &edges,
                  double xme, double yme,
                  set<pair<double, double> > &mypos,
                  _edge_set &edge_set,
                  _edge edge_expand) //edge_expand‚Ìx0‚Æy0‚ðŠm”F angle‚à
{
    //preparing
    edge_expand.x0 = xme;
    edge_expand.y0 = yme;
    
    //initialize
    double angle_from = edge_expand.angle1();
    double angle_to   = edge_expand.angle2();
    DBG2("  angle_from",angle_from);
    DBG2("  angle_to  ",angle_to  );
    
    //make temporary edge_set to clarify modification
    _edge_set tmp = _edge_set(xme, yme);
    tmp.add_edge(edge_expand);
    
    //loop for all edges
    FORI(i, SZ(edges)) {
        
        _edge e0 = _edge(xme, yme, edges[i]);
        double ang1 = e0.angle1();
        double ang2 = e0.angle2();
        DBG("---");
        DBG3("   (e0.x1:e0.y1)",e0.x1,e0.y1);
        DBG3("   (e0.x2:e0.y2)",e0.x2,e0.y2);
        DBG2("   ang1",ang1);
        DBG2("   ang2",ang2);
        
        vector<_edge> tmp2;
        if (e0.inner_prod(0, 0) < 0) {
            //edge is not facing to me
            DBG("   ->not facing");
            continue;
        }
        else if (ang2 < ang1) {
            //split edge
            tmp2.PB(_edge(e0.x1, e0.y1, e0.x2, edge_set.y0));
            tmp2.PB(_edge(e0.x1, edge_set.y0, e0.x2, e0.y2));
            DBG("   ->split to 2 edges");
            DBG3("    /one(x,y)",e0.x1, e0.y1);
            DBG3("    /   (x,y)",e0.x2, edge_set.y0);
            DBG3("    /two(x,y)",edge_set.y0, e0.x2);
            DBG3("    /   (x,y)",e0.x2, e0.y2);
        }
        else {
            tmp2.PB(e0);
        }
        
        FORI(j, SZ(tmp2)) {
            _edge e = _edge(xme, yme, tmp2[j]);
            double ang1 = e.angle1();
            double ang2 = e.angle2();
            DBG3("    e",e.x1,e.y1);
            DBG3("     ",e.x2,e.y2);
            
            if (ang2 <= angle_from or angle_to <= ang1) {
                //not inside the from-to range
                DBG("    ->not in the range(angle_from ~ angle_to)");
                continue;
            }
            
            double d_from = calc_d(angle_from, e);
            double d_to   = calc_d(angle_to  , e);
            double x_from = d_from * cos(angle_from);
            double y_from = d_from * sin(angle_from);
            double x_to   = d_to   * cos(angle_to  );
            double y_to   = d_to   * sin(angle_to  );
            
            if (ang1 < angle_from) { e.x1 = x_from; e.y1 = y_from; ang1 = angle_from; }
            if (angle_to   < ang2) { e.x2 = x_to;   e.y2 = y_to;   ang2 = angle_to;   }
            
            bool repeat = true;
            while(repeat) {
                repeat = false;
                FORE(it, tmp.edges, set<_edge>) {
                    _edge e2 = _edge(xme, yme, (*it));
                    
                    if (e2.angle2() <= ang1 or ang2 <= e2.angle1()) {
                        continue;
                    }
                    double ang3 = max(ang1, e2.angle1());
                    double ang4 = min(ang2, e2.angle2());
                    
                    if (ang3 < ang4 and
                        (calc_d(ang3, e2) == 0 or
                        calc_d(ang3, e2) > calc_d(ang3, e)))
                    {
                        //remove current edge
                        tmp.remove_edge(e2);
                        
                        //add some parts of current edge
                        if (e2.angle1() < ang1) {
                            double d_tmp = calc_d(ang1, e2);
                            tmp.add_edge(e2.x1, e2.y1, d_tmp*cos(ang1), d_tmp*sin(ang1));
                        }
                        if (ang2 < e2.angle2()) {
                            double d_tmp = calc_d(ang2, e2);
                            tmp.add_edge(d_tmp*cos(ang1), d_tmp*sin(ang1), e2.x2, e2.y2);
                        }
                        
                        //add new edge
                        double d3 = calc_d(ang3, e);
                        double d4 = calc_d(ang4, e);
                        tmp.add_edge(d3*cos(ang3), d3*sin(ang3), d4*cos(ang4), d4*sin(ang4));
                        
                        //repeat
                        repeat = true; break;
                    }
                }
            }
        }
    }
    DBG("---end");
    
    //remove from and add to edge_set
    edge_set.remove_edge(edge_expand);
    FORE(it, tmp.edges, set<_edge>) {
        edge_set.add_edge(*it);
    }
};

/*
 * main funtion
 */
int main() {
    int T;
    cin >>T;
    cin.ignore();
    
    for(int t=1; t<=T; t++) {
        
        //input
        int H, W, D;
        cin >>H >>W >>D;
        string blocks[H];
        FORI(i, H) cin >>blocks[i];
        DBG2("H", H);
        DBG2("W", W);
        DBG2("D", D);
        
        //initialize
        double xme, yme;
        vector<_edge> edges;
        FORI(y, H) FORI(x, W) {
            DBG3(" (x:y)",x, y);
            
            if (blocks[y][x] == 'X') {
                xme = x + 0.5;
                yme = y + 0.5;
                DBG3(" (xme:yme)",xme,yme);
            }
            
            if (x == W-1) continue;
            if (y == H-1) continue;
            DBG3(" blocks",blocks[y][x],blocks[y][x+1]);
            DBG3("       ",blocks[y+1][x],blocks[y+1][x+1]);
            _edge e(x, y, 0, 0);
            if (blocks[y][x]   == '#' and blocks[y][x+1]   != '#') {
                e.x2 = x; e.y2 = y-1;
                get_around(H, W, blocks, e, edges);
            }
            if (blocks[y][x+1] == '#' and blocks[y+1][x+1] != '#') {
                e.x2 = x+1; e.y2 = y;
                get_around(H, W, blocks, e, edges);
            }
            if (blocks[y+1][x+1] == '#' and blocks[y+1][x] != '#') {
                e.x2 = x; e.y2 = y+1;
                get_around(H, W, blocks, e, edges);
            }
            if (blocks[y+1][x]   == '#' and blocks[y][x]   != '#') {
                e.x2 = x-1; e.y2 = y;
                get_around(H, W, blocks, e, edges);
            }
        }
        
        DBG("--------");
        
        //re-construct edges which can be seen from the start point
        set<pair<double, double> > mypos;
        mypos.insert(pair<double, double> (0, 0));
        //_edge_set edge_set = _edge_set(xme, yme, -1, -1, W-1, H-1);
        _edge_set edge_set = _edge_set(xme, yme);
        edge_set.add_edge(xme, yme, xme, yme);
        
        expand_edge(H, W, edges, xme, yme, mypos, edge_set, _edge(xme, yme, xme, yme));
        
        //TODO
        
        
        int ret = 0;
        cout <<"Case #" <<t <<": " <<ret <<endl;
    }
    
    return 0;
}

