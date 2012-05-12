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

//priority_queue<pair<string, int>, vector<pair<string, int> >, compare_value> open;
//priority_queue<pair<string, int>, vector<pair<string, int> >, compare_value> close;
set<pair<string, int>, compare_value> open;
set<pair<string, int>, compare_value> close;

/****************************************************************************
 * Main
 ****************************************************************************/

int main() {
    
    string p_0 = "===================================0";
    
//    pair<string, int> state0;
//    state0.first = p_0;
//    state0.second = 0;
//    open.push(state0);
    open.insert(pair<string, int>(p_0, 0));
    //path[p_0] = "";
    
    pair<string, int> p;
    p.first = "‚ "; p.second = 3;  open.insert(p);
    p.first = "‚¢"; p.second = 2;  open.insert(p);
    p.first = "‚¤"; p.second = 1;  open.insert(p);
    p.first = "‚¦"; p.second = 10; open.insert(p);
    p.first = "‚¨"; p.second = 8;  open.insert(p);
    
//    while (!open.empty()) {
//        pair<string, int> item = open.top();
//        cout << item.first << "(" << item.second << ")" << endl;
//        open.pop();
//    }
    
//    pair<string, int> p1;
//    p1.first = "‚¦";
//    
//    if (open.find(p1) != open.end()) {
//        cout <<"find. " <<open.find(p1)->second <<endl;
//    }
//    else {
//        cout <<"x" <<endl;
//    }
    
    for(set<pair<string, int> >::iterator it = open.begin(); it != open.end(); it++) {
        if (it->first == "‚­") cout <<"find. " <<it->second <<endl;
    }
    
    return 0;
}
