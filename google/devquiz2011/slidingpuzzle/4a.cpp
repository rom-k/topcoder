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

/****************************************************************************
 * Definition
 ****************************************************************************/

struct compare_value {
    bool operator()(const pair<string, int>& x, const pair<string, int>& y) const {
        return x.second > y.second;
    }
};

/****************************************************************************
 * Global variable
 ****************************************************************************/

priority_queue<pair<string, int>, vector<pair<string, int> >, compare_value> open;
priority_queue<pair<string, int>, vector<pair<string, int> >, compare_value> close;
map<string, string> path;
const int fact[36] = {
    89, 55, 34, 21, 13,  8,
    55, 34, 21, 13,  8,  5,
    34, 21, 13,  8,  5,  3,
    21, 13,  8,  5,  3,  2,
    13,  8,  5,  3,  2,  1,
     8,  5,  3,  2,  1,  0,
};

/****************************************************************************
 * Function
 ****************************************************************************/

// Local atoi
int l_atoi(char a) {
    int i = a - '0';
    if(0 <= i && i <= 9) return i;
    i = a - 'A' + 10;
    return i;
}

// Local itoa
char l_itoa(int i) {
    return (i < 10) ? '0' + i
         :            'A' + i - 10;
}

// Convert to equivalent 6*6 panel
string conv(int w, int h, string a) {
    string b = "====================================";
    FORI(i, 36) {
        if(6 <= h + i / 6 and 6 <= w + i % 6)
            b[i] = a[(i / 6 + h - 6) * w + (i % 6 + w - 6)];
        
        if(b[i] != '=' and b[i] != '0') {
            int n = l_atoi(b[i]) - 1;
            b[i] = l_itoa((n / w + 6 - h) * 6 + (n % w + 6 - w) + 1);
        }
    }
    return b;
}

// Check for panel difference
// O(36)
bool clear(string p, string p_goal) {
    FORI(i, 36) {
        if(p_goal[i] == '=' and p[i] != '='
        or p_goal[i] != '=' and p[i] != '='
                            and p[i]      != p_goal[i]
        or p[i] == '='      and p_goal[i] != '='
                            and p_goal[i] != l_itoa(i+1)) {
            return false;
        }
    }
    return true;
}

// Calc f'
// O(36)
int calc_f(string p, string p_goal, int dist[36][36], map<char, int> g_map) {
    
    FORI(i, 36) if (p_goal[i] == '=' and p[i] != '=') return 999;
    
    int ret = SZ(path[p]);
    
    FORI(i, 36) {
        if (p[i] == '0') continue;
        if (p[i] == '=' and p_goal[i] == '=') continue;
        char c = (p[i] != '=') ? p[i] : l_itoa(i+1);
        if (g_map.find(c) != g_map.end()) {
            int j = g_map[c];
            ret += fact[j] * dist[i][j];
        }
    }
    
    return ret;
}

//  A* Algorithm
//TODO: dual search (from start and from goal)
string a_star(string p_goal) {
    string ret = "";
    
    // Calc distance map
    // O(36^3)
    int dist[36][36];
    FORI(i, 36) FORI(j, 36) {
        dist[i][j]
        = (p_goal[i] == '=' or p_goal[j] == '=') ? 999
        : (i == j)                               ? 0
        : ((i / 6 == j / 6) and abs(i - j) == 1) ? 1
        : (                     abs(i - j) == 6) ? 6
        :                                          999;
    }
    FORI(i, 36) FORI(j, 36) FORI(k, 36) {
        dist[i][k] = (dist[i][k] < dist[i][j] + dist[j][k])
                   ? dist[i][k]
                   : dist[i][j] + dist[j][k];
        dist[k][i] = dist[i][k];
    }
    
    // make goal charactor map
    map<char, int> g_map;
    FORI(i, 36) g_map[p_goal[i]] = i;
    
    // calc f and sort open/close
    // O((Nop + Ncl) * 36)
    set<string> st;
    while (!open.empty()) {
        st.insert(open.top().first); open.pop();
    }
    FORE(it, st, set<string>) {
        open.push(pair<string, int>(*it, calc_f(*it, p_goal, dist, g_map)));
        if (clear(*it, p_goal)) ret = path[*it];
    }
    st.clear();
    while (!close.empty()) {
        st.insert(close.top().first); close.pop();
    }
    FORE(it, st, set<string>) {
        close.push(pair<string, int>(*it, calc_f(*it, p_goal, dist, g_map)));
        if (clear(*it, p_goal)) ret = path[*it];
    }
    
    if(DEBUG) cout <<"g: " <<p_goal <<endl;
    
    // return if found
    if (ret != "") return ret;
    
    while(1) {
        
        // error exit if no entry in open.
        if (open.empty()) {
            cout <<"ERROR: No open status.\n" <<endl;
            exit(-1);
        }
        
        // get n from open.
        pair<string, int> s_n = open.top(); open.pop();
        string p_n = s_n.first;
        string t_n = path[p_n];
        int    f_n = s_n.second;
        
        if(DEBUG) cout <<"n: " <<p_n <<" (f=" <<f_n <<", t=" <<t_n <<") / "
            <<SZ(open) <<" & " <<SZ(close) <<endl;
        
        // error exit if n is invalid.
        if (f_n >= 999) {
            cout <<"ERROR: Invalid f(n) for " <<p_n <<endl;
            exit(-1);
        }
        
        // solved if n is goal.
        // O(36)
        if (clear(p_n, p_goal)) {
            open.push(pair<string, int>(p_n, f_n));
            return t_n;
        }
        
        // put n to close.
        close.push(pair<string, int>(p_n, f_n));
        
        // find '0'
        // O(36)
        int pos0;
        FORI(i, 36) if (p_n[i] == '0') pos0 = i;
        
        FORI(i, 4) {
            // i=0 : L : swap pos0 <=> pos0+1
            // i=1 : R : swap pos0 <=> pos0-1
            // i=2 : U : swap pos0 <=> pos0+6
            // i=3 : D : swap pos0 <=> pos0-6
            
            if (i==0 and (pos0%6==5 or t_n[0]=='R')) continue;
            if (i==1 and (pos0%6==0 or t_n[0]=='L')) continue;
            if (i==2 and (pos0/6==5 or t_n[0]=='D')) continue;
            if (i==3 and (pos0/6==0 or t_n[0]=='U')) continue;
            
            string p_m = p_n;
            string t_m = "";
            int f_m    = 0;
            
            int j;
            if (i==0) { t_m = "L" + t_n; j = pos0+1; }
            if (i==1) { t_m = "R" + t_n; j = pos0-1; }
            if (i==2) { t_m = "U" + t_n; j = pos0+6; }
            if (i==3) { t_m = "D" + t_n; j = pos0-6; }
            p_m[pos0] = (p_m[j] != '=') ? p_m[j] : l_itoa(j+1);
            p_m[j] = '0';
            f_m = calc_f(p_m, p_goal, dist, g_map);
            
            pair<string, int> s_m;
            s_m.first  = p_m;
            path[p_m]  = t_m;
            s_m.second = f_m;
            
            bool new_p = 1;
            
            // Check for duplication
            if (path.find(p_m) != path.end()) {
                
                //priority_queue<pair<string, int>, vector<pair<string, int> >, compare_value> open;
                //deque< int >::iterator it = find( qu.begin(), qu.end(), 8888 );
                //priority_queue<pair<string, int> >::iterator it = find(open.begin(), open.end(), pair<string, int>(p_m, f_m));
                
                //for(vector<pair<string, int> >::iterator it = open.begin(); it != open.end(); it++) {
                //}
                
                priority_queue<pair<string, int> >::iterator it = find(open.begin(), open.end(), pair<string, int>(p_m, f_m));
                
                //TODO:ˆÚA
                //my $s = $exist{$m->[0]};
                //if($m->[2] < $s->[2]) {
                //    
                //    # Update other node
                //    my $old_t = $s->[1];
                //    my $new_t = $m->[1];
                //    $_->[1] =~ s/$old_t$/$new_t/ foreach(@op);
                //    $_->[1] =~ s/$old_t$/$new_t/ foreach(@cl);
                //    
                //    # Update this node
                //    @op = grep {$_->[0] ne $m->[0]} @op;
                //    @cl = grep {$_->[0] ne $m->[0]} @cl;
                //    
                //    # O(log_2(Nop))
                //    &l_push(\@op, $m);
                //    #push @op, $m;
                //    
                //    if(DEBUG) {print "update m.\n\n";}
                //}
                
                new_p = 0;
                break;
            }
            
            if (new_p) {
                
                //TODO:ˆÚA
                //# O(log_2(Nop))
                //&l_push(\@op, $m);
                //#push @op, $m;
                //
                //$exist{$m->[0]} = $op[-1];
                //if(DEBUG) {print "add new m to open.\n\n";}
            }
        }
    }
    
    return ret;
}

/****************************************************************************
 * Main
 ****************************************************************************/

int main() {
    
    string p_0 = "===================================0";
    
//    pair<string, int> state0;
//    state0.first = p_0;
//    state0.second = 0;
//    open.push(state0);
    open.push(pair<string, int>(p_0, 0));
    path[p_0] = "";
    
//    pair<string, int> p;
//    p.first = "‚ "; p.second = 3;  open.push(p);
//    p.first = "‚¢"; p.second = 2;  open.push(p);
//    p.first = "‚¤"; p.second = 1;  open.push(p);
//    p.first = "‚¦"; p.second = 10; open.push(p);
//    p.first = "‚¨"; p.second = 8;  open.push(p);
//    
//    while (!open.empty()) {
//        pair<string, int> item = open.top();
//        cout << item.first << "(" << item.second << ")" << endl;
//        open.pop();
//    }
    
    LL LX, RX, UX, DX, T;
    cin >>LX >>RX >>UX >>DX >>T;
    cout <<LX <<" " <<RX <<" " <<UX <<" " <<DX <<endl;
    
    for(int t=1; t<=T; t++) {
        int w, h;
        string line_in, p_in;
        
        cin >>line_in;
        w    = line_in.at(0) - '0';
        h    = line_in.at(2) - '0';
        p_in = line_in.substr(4);
        string p_goal = conv(w, h, p_in);
        
        string path = a_star(p_goal);
        
        int L = 0; int R = 0; int U = 0; int D = 0;
        FORI(i, SZ(path)) {
            if(path[i] == 'L') L++;
            if(path[i] == 'R') R++;
            if(path[i] == 'U') U++;
            if(path[i] == 'D') D++;
        }
        cout <<endl
             <<t <<": " <<L <<" " <<R <<" " <<U <<" " <<D <<" " <<path <<endl
             << "----------------------------------------------------------------" <<endl;
    }
    
    return 0;
}
