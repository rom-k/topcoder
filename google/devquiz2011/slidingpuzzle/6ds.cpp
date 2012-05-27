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

//#define DUAL

#define DUMP 0

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

/****************************************************************************
 * Definition
 ****************************************************************************/

struct compare_value {
    bool operator()(const pair<string, int>& x, const pair<string, int>& y) const {
        return (x.second != y.second) ? x.second < y.second
             :                          x.first  < y.first;
    }
};

/****************************************************************************
 * Global variable
 ****************************************************************************/

set<pair<string, int>, compare_value> open;
set<pair<string, int>, compare_value> close;
map<string, string> path;
const int fact[36] = {
    89, 55, 34, 21, 13,  8,
    55, 34, 21, 13,  8,  5,
    34, 21, 13,  8,  5,  3,
    21, 13,  8,  5,  3,  2,
    13,  8,  5,  3,  2,  1,
     8,  5,  3,  2,  1,  0,
//    512, 256, 128,  64, 32,
//    256, 128,  64,  32, 16,
//    128,  64,  32,  16,  8,
//     64,  32,  16,   8,  4,
//     32,  16,   8,   4,  2,
//     16,   8,   4,   2,  1,
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
int calc_f(string p, string p_goal, string t, int dist[36][36], map<char, int> g_map) {
    
    FORI(i, 36) if (p_goal[i] == '=' and p[i] != '=') return 99999;
    
    int ret = SZ(t);
    
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
string a_star(string p_goal) {
    string ret = "";
    int cnt = 10000;
    
    // Calc distance map
    // O(36^3)
    int dist[36][36];
    FORI(i, 36) FORI(j, 36) {
        dist[i][j]
        = (p_goal[i] == '=' or p_goal[j] == '=') ? 99999
        : (i == j)                               ? 0
        : ((i / 6 == j / 6) and abs(i - j) == 1) ? 1
        : (                     abs(i - j) == 6) ? 6
        :                                          99999;
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
    // O((Nop + Ncl))
    map<string, int> mp;
    for(set<pair<string, int> >::iterator it = open.begin(); it != open.end(); it++)
        mp[it->first] = calc_f(it->first, p_goal, path[it->first], dist, g_map);
    while(SZ(open)) open.clear();
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
        open.insert(pair<string, int>(it->first, it->second));
    
    mp.clear();
    for(set<pair<string, int> >::iterator it = close.begin(); it != close.end(); it++)
        mp[it->first] = calc_f(it->first, p_goal, path[it->first], dist, g_map);
    while(SZ(close)) close.clear();
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
        close.insert(pair<string, int>(it->first, it->second));
    
    // clear check & dump
    for(set<pair<string, int> >::iterator it = open.begin(); it != open.end(); it++) {
        if (clear(it->first, p_goal) and (ret == "" or SZ(path[it->first]) < SZ(ret))) ret = path[it->first];
        if(DUMP) cout <<"DUMP: o " <<it->first <<" " <<path[it->first] <<" " <<it->second <<endl;
    }
    for(set<pair<string, int> >::iterator it = close.begin(); it != close.end(); it++) {
        if (clear(it->first, p_goal) and (ret == "" or SZ(path[it->first]) < SZ(ret))) ret = path[it->first];
        if(DUMP) cout <<"DUMP: c " <<it->first <<" " <<path[it->first] <<" " <<it->second <<endl;
    }
    
    if(DEBUG) cout <<"g: " <<p_goal <<endl;
    
    // return if found
    if (ret != "") return ret;
    
    
    
#ifdef DUAL
    // dual search (rev)
    set<pair<string, int>, compare_value> open_r;
    set<pair<string, int>, compare_value> close_r;
    map<string, string> path_r;
    string p_0 = "====================================";
    FORI(i, 36) p_0[i] = (i == 35)          ? '0'
                       : (p_goal[i] == '=') ? '='
                       :                      l_itoa(i+1);
    
    // Calc distance map (rev)
    // O(36^3)
    int dist_r[36][36];
    FORI(i, 36) FORI(j, 36) {
        dist_r[i][j]
        = (p_0[i] == '=' or p_0[j] == '=')       ? 99999
        : (i == j)                               ? 0
        : ((i / 6 == j / 6) and abs(i - j) == 1) ? 1
        : (                     abs(i - j) == 6) ? 6
        :                                          99999;
    }
    FORI(i, 36) FORI(j, 36) FORI(k, 36) {
        dist_r[i][k] = (dist_r[i][k] < dist_r[i][j] + dist_r[j][k])
                     ? dist_r[i][k]
                     : dist_r[i][j] + dist_r[j][k];
        dist_r[k][i] = dist_r[i][k];
    }
    
    // make goal charactor map (rev)
    map<char, int> g_map_r;
    FORI(i, 36) g_map_r[p_0[i]] = i;
    
    // init (rev)
    path_r[p_goal] = "";
    open_r.insert(pair<string, int>(p_goal, calc_f(p_goal, p_0, path_r[p_goal], dist_r, g_map_r)));
#endif
    
    while(0 < cnt--) {
        
        // error exit if no entry in open.
        if (open.empty()) {
            cout <<"ERROR: No open status.\n" <<endl;
            exit(-1);
        }
        
        // get n from open.
        //set<pair<string, int> >::iterator it = open.begin();
        //TODO: how to get least one???
        set<pair<string, int> >::iterator it = open.lower_bound(pair<string, int>("", 0));
        string p_n = it->first;
        string t_n = path[p_n];
        int    f_n = it->second;
        open.erase(it);
        
        if(DEBUG) cout <<"n: " <<p_n <<" (f=" <<f_n <<", t=" <<t_n <<") / "
            <<SZ(open) <<" & " <<SZ(close) <<endl;
        
        // error exit if n is invalid.
        if (f_n >= 99999) {
            cout <<"ERROR: Invalid f(n) for " <<p_n <<endl;
            exit(-1);
        }
        
        // solved if n is goal.
        // O((Nop + Ncl) * 36)
#ifdef DUAL
        for(map<string, string>::iterator it = path_r.begin(); it != path_r.end(); it++) {
            if (clear(p_n, it->first)) {
                open.insert(pair<string, int>(p_n, f_n));
                return it->second + t_n;
            }
        }
#else
        if (clear(p_n, p_goal)) {
            open.insert(pair<string, int>(p_n, f_n));
            return t_n;
        }
#endif
        
        // put n to close.
        close.insert(pair<string, int>(p_n, f_n));
        
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
            f_m = calc_f(p_m, p_goal, t_m, dist, g_map);
            
            bool new_p = 1;
            
            // Check for duplication
            if (path.find(p_m) != path.end()) {
                
                if (SZ(t_m) < SZ(path[p_m])) {
                    map<string, int> mp;
                    
                    // Update path
                    string t_old = path[p_m];
                    for(map<string, string>::iterator it = path.begin(); it != path.end(); it++) {
                        if (SZ(it->second)-SZ(t_old) > 0
                        and it->second.substr(SZ(it->second)-SZ(t_old)) == t_old) {
                            it->second = it->second.substr(0,SZ(it->second)-SZ(t_old)) + t_m;
                            mp[it->first] = 1;
                        }
                    }
                    mp[p_m] = 1;
                    
                    // Update f'
                    
                    mp.clear();
                    for(set<pair<string, int> >::iterator it = open.begin(); it != open.end(); it++) {
                        if(mp.find(it->first) != mp.end()) {
                            int f = calc_f(it->first, p_goal, path[it->first], dist, g_map);
                            if (it->second != f) mp[it->first] = f;
                        }
                    }
                    int n = 0;
                    while(n < SZ(mp)) {
                        for(set<pair<string, int> >::iterator it = open.begin(); it != open.end(); it++) {
                            if (mp.find(it->first) != mp.end()) {
                                open.erase(it--);
                                n++;
                            }
                        }
                    }
                    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
                        open.insert(pair<string, int>(it->first, it->second));
                    
                    mp.clear();
                    for(set<pair<string, int> >::iterator it = close.begin(); it != close.end(); it++) {
                        if(mp.find(it->first) != mp.end()) {
                            int f = calc_f(it->first, p_goal, path[it->first], dist, g_map);
                            if (it->second != f) mp[it->first] = f;
                        }
                    }
                    n = 0;
                    while(n < SZ(mp)) {
                        for(set<pair<string, int> >::iterator it = close.begin(); it != close.end(); it++) {
                            if (mp.find(it->first) != mp.end()) {
                                close.erase(it--);
                                n++;
                            }
                        }
                    }
                    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
                        if (it->first == p_m) {
                            open.insert(pair<string, int>(it->first, it->second));
                        }
                        else {
                            close.insert(pair<string, int>(it->first, it->second));
                        }
                }
                
                new_p = 0;
            }
            
            if(DEBUG) cout <<"  (" <<p_m <<" (f=" <<f_m <<", t=" <<t_m <<") " <<(new_p?"new!":"") <<endl;
            
            if (new_p) {
                open.insert(pair<string, int>(p_m, f_m));
                path[p_m]  = t_m;
            }
        }
        
        
        
#ifdef DUAL
        // rev
        // error exit if no entry in open. (rev)
        if (/*open.empty()*/open_r.empty()) {
            cout <<"ERROR: No open status. (rev)\n" <<endl;
            exit(-1);
        }
        
        // get n from open. (rev)
        /*set<pair<string, int> >::iterator*/ it = /*open.begin()*/open_r.begin();
        /*string*/ p_n = it->first;
        /*string*/ t_n = /*path[p_n]*/path_r[p_n];
        /*int   */ f_n = it->second;
        /*open.erase(it)*/open_r.erase(it);
        
        if(DEBUG) cout <<"x: " <<p_n <<" (f=" <<f_n <<", t=" <<t_n <<") / "
            <<SZ(/*open*/open_r) <<" & " <<SZ(/*close*/close_r) <<endl;
        
        // error exit if n is invalid. (rev)
        if (f_n >= 99999) {
            cout <<"ERROR: Invalid f(n) for " <<p_n <<" (rev)" <<endl;
            exit(-1);
        }
        
        // solved if n is goal. (rev)
        // O((Nop + Ncl) * 36)
        /*for(map<string, string>::iterator it = path.begin(); it != path.end(); it++) {
            if (clear(p_n, it->first)) {
                open.insert(pair<string, int>(p_n, f_n));
                return it->second + t_n;
            }
        }*/
        
        // put n to close.
        /*close*/close_r.insert(pair<string, int>(p_n, f_n));
        
        // find '0' (rev)
        // O(36)
        //int pos0;
        FORI(i, 36) if (p_n[i] == '0') pos0 = i;
        
        FORI(i, 4) {
            // i=0 : /*L*/R : swap pos0 <=> pos0+1
            // i=1 : /*R*/L : swap pos0 <=> pos0-1
            // i=2 : /*U*/D : swap pos0 <=> pos0+6
            // i=3 : /*D*/U : swap pos0 <=> pos0-6
            
            if (i==0 and (pos0%6==5 or t_n[/*0*/SZ(t_n)-1]==/*'R'*/'L')) continue;
            if (i==1 and (pos0%6==0 or t_n[/*0*/SZ(t_n)-1]==/*'L'*/'R')) continue;
            if (i==2 and (pos0/6==5 or t_n[/*0*/SZ(t_n)-1]==/*'D'*/'U')) continue;
            if (i==3 and (pos0/6==0 or t_n[/*0*/SZ(t_n)-1]==/*'U'*/'D')) continue;
            
            string p_m = p_n;
            string t_m = "";
            int f_m    = 0;
            
            int j;
            if (i==0) { t_m = /*"L" + t_n*/t_n + "R"; j = pos0+1; }
            if (i==1) { t_m = /*"R" + t_n*/t_n + "L"; j = pos0-1; }
            if (i==2) { t_m = /*"U" + t_n*/t_n + "D"; j = pos0+6; }
            if (i==3) { t_m = /*"D" + t_n*/t_n + "U"; j = pos0-6; }
            
            p_m[pos0] = (p_m[j] != '=') ? p_m[j] : l_itoa(j+1);
            p_m[j] = '0';
            f_m = calc_f(p_m, /*p_goal, t_m, dist, g_map*/p_0, t_m, dist_r, g_map_r);
            
            bool new_p = 1;
            
            // Check for duplication
            if (/*path*/path_r.find(p_m) != /*path*/path_r.end()) {
                
                if (SZ(t_m) < SZ(/*path*/path_r[p_m])) {
                    map<string, int> mp;
                    
                    // Update path
                    string t_old = /*path*/path_r[p_m];
                    for(map<string, string>::iterator it = /*path*/path_r.begin(); it != /*path*/path_r.end(); it++) {
                        if (SZ(it->second)-SZ(t_old) > 0
                        and it->second.substr(/*SZ(it->second)-*/0,SZ(t_old)) == t_old) {
                            it->second = t_m + it->second.substr(/*0,SZ(it->second)-*/SZ(t_old)) /*+ t_m*/;
                            mp[it->first] = 1;
                        }
                    }
                    mp[p_m] = 1;
                    
                    // Update f'
                    
                    mp.clear();
                    for(set<pair<string, int> >::iterator it = /*open*/open_r.begin(); it != /*open*/open_r.end(); it++) {
                        if(mp.find(it->first) != mp.end()) {
                            int f = calc_f(it->first, /*p_goal*/p_0, /*path*/path_r[it->first], /*dist*/dist_r, /*g_map*/g_map_r);
                            if (it->second != f) mp[it->first] = f;
                        }
                    }
                    int n = 0;
                    while(n < SZ(mp)) {
                        for(set<pair<string, int> >::iterator it = /*open*/open_r.begin(); it != /*open*/open_r.end(); it++) {
                            if (mp.find(it->first) != mp.end()) {
                                /*open*/open_r.erase(it--);
                                n++;
                            }
                        }
                    }
                    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
                        /*open*/open_r.insert(pair<string, int>(it->first, it->second));
                    
                    mp.clear();
                    for(set<pair<string, int> >::iterator it = /*close*/close_r.begin(); it != /*close*/close_r.end(); it++) {
                        if(mp.find(it->first) != mp.end()) {
                            int f = calc_f(it->first, /*p_goal*/p_0, /*path*/path_r[it->first], /*dist*/dist_r, /*g_map*/g_map_r);
                            if (it->second != f) mp[it->first] = f;
                        }
                    }
                    n = 0;
                    while(n < SZ(mp)) {
                        for(set<pair<string, int> >::iterator it = /*close*/close_r.begin(); it != /*close*/close_r.end(); it++) {
                            if (mp.find(it->first) != mp.end()) {
                                /*close*/close_r.erase(it--);
                                n++;
                            }
                        }
                    }
                    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
                        if (it->first == p_m) {
                            /*open*/open_r.insert(pair<string, int>(it->first, it->second));
                        }
                        else {
                            /*close*/close_r.insert(pair<string, int>(it->first, it->second));
                        }
                }
                
                new_p = 0;
            }
            
            if(DEBUG) cout <<"  (" <<p_m <<" (f=" <<f_m <<", t=" <<t_m <<") " <<(new_p?"new!":"") <<endl;
            
            if (new_p) {
                /*open*/open_r.insert(pair<string, int>(p_m, f_m));
                /*path*/path_r[p_m]  = t_m;
            }
        }
#endif
    }
    
    return ret;
}

/****************************************************************************
 * Main
 ****************************************************************************/

int main() {
    
    string p_0 = "===================================0";
    open.insert(pair<string, int>(p_0, 0));
    path[p_0] = "";
    
    LL LX, RX, UX, DX, T;
    cin >>LX >>RX >>UX >>DX >>T;
    //cout <<LX <<" " <<RX <<" " <<UX <<" " <<DX <<endl;
    
    set<pair<string, int>, compare_value> prob;
    map<string, int> mp;
    
    for(int t=1; t<=T; t++) {
        int w, h;
        string line_in, p_in;
        
        cin >>line_in;
        w    = line_in.at(0) - '0';
        h    = line_in.at(2) - '0';
        p_in = line_in.substr(4);
        if(w==0 or h==0) continue;
        
        string p_goal = conv(w, h, p_in);
        
        int dist[36][36];
        FORI(i, 36) FORI(j, 36) {
            dist[i][j]
            = (p_goal[i] == '=' or p_goal[j] == '=') ? 99999
            : (i == j)                               ? 0
            : ((i / 6 == j / 6) and abs(i - j) == 1) ? 1
            : (                     abs(i - j) == 6) ? 6
            :                                          99999;
        }
        FORI(i, 36) FORI(j, 36) FORI(k, 36) {
            dist[i][k] = (dist[i][k] < dist[i][j] + dist[j][k])
                       ? dist[i][k]
                       : dist[i][j] + dist[j][k];
            dist[k][i] = dist[i][k];
        }
        
        map<char, int> g_map;
        FORI(i, 36) g_map[p_goal[i]] = i;
        
        int f = calc_f(p_0, p_goal, "", dist, g_map);
        prob.insert(pair<string, int>(p_goal, f));
        mp[p_goal] = t;
    }
    
    for(set<pair<string, int> >::iterator it = prob.begin(); it != prob.end(); it++) {
        
        string p_goal = it->first;
        int t = mp[p_goal];
        
        string t1 = "";//a_star(p_goal);
        
        if (t1 == "") {
            while(SZ(open)) open.clear();
            while(SZ(close)) close.clear();
            while(SZ(path)) path.clear();
            open.insert(pair<string, int>(p_0, 0));
            path[p_0] = "";
            
            t1 = a_star(p_goal);
        }
        
        if (t1 != "") {
            cout <<t <<" " <<t1 <<endl;
        }
    }
    
    return 0;
}
