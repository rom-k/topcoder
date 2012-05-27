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

int main() {
    int T;
    cin >>T;
    cin.ignore();
    
    for(int t=1; t<=T; t++) {
        
        string a;
        //cin >>a;
        getline(cin, a);
        
        string b = a;
        
        FORI(i, SZ(a)) {
            if (a[i] == 'a') b[i] = 'y';
            if (a[i] == 'b') b[i] = 'h';
            if (a[i] == 'c') b[i] = 'e';
            if (a[i] == 'd') b[i] = 's';
            if (a[i] == 'e') b[i] = 'o';
            if (a[i] == 'f') b[i] = 'c';
            if (a[i] == 'g') b[i] = 'v';
            if (a[i] == 'h') b[i] = 'x';
            if (a[i] == 'i') b[i] = 'd';
            if (a[i] == 'j') b[i] = 'u';
            if (a[i] == 'k') b[i] = 'i';
            if (a[i] == 'l') b[i] = 'g';
            if (a[i] == 'm') b[i] = 'l';
            if (a[i] == 'n') b[i] = 'b';
            if (a[i] == 'o') b[i] = 'k';
            if (a[i] == 'p') b[i] = 'r';
            if (a[i] == 'q') b[i] = 'z';
            if (a[i] == 'r') b[i] = 't';
            if (a[i] == 's') b[i] = 'n';
            if (a[i] == 't') b[i] = 'w';
            if (a[i] == 'u') b[i] = 'j';
            if (a[i] == 'v') b[i] = 'p';
            if (a[i] == 'w') b[i] = 'f';
            if (a[i] == 'x') b[i] = 'm';
            if (a[i] == 'y') b[i] = 'a';
            if (a[i] == 'z') b[i] = 'q';
        }
        
        cout <<"Case #" <<t <<": " <<b <<endl;
    }
    
    return 0;
}
