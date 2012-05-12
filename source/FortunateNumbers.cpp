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

class FortunateNumbers {
public:
	bool f(int a) {
		int b = a;
		while (b > 0) {
			if (b%10 != 5 and b%10 != 8) {return false;}
			b /= 10;
		}
		return true;
	}
	int getFortunate(vector <int> a, vector <int> b, vector <int> c) {
		
		VI hoge;
		FORI(i, SZ(a)) FORI(j, SZ(b)) FORI(k, SZ(c))
			if ( f(a[i]+b[j]+c[k]) ) hoge.PB(a[i]+b[j]+c[k]);
		
		SORT(hoge);
		
		int prev=0;
		int ret = 0;
		FORI(i, SZ(hoge)) {
			if (hoge[i] != prev) ret++;
			prev = hoge[i];
		}
		
		return ret;
	}

	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
