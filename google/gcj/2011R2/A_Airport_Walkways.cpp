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
#define PB(n) push_back(n)
#define PI M_PI
#define EPS 1e-13

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

struct cway {
	LL len;
	LL sp;
	
	inline bool operator < (const cway a) const {
		return sp < a.sp;
	}
};

int main() {
	int TT;
	cin >>TT;
	cin.ignore();
	
	for(int tt=1; tt<=TT; tt++) {
		
		LL X, S, R, t, N;
		cin >>X >>S >>R >>t >>N;
		
		vector<LL> B(N, 0);
		vector<LL> E(N, 0);
		vector<LL> w(N, 0);
		FORI(i, N) cin >>B[i] >>E[i] >>w[i];
		
		vector<cway> way(N+1);
		way[0].len = X;
		way[0].sp  = S;
		FORI(i, N) {
			way[i+1].len = E[i] - B[i];
			way[i+1].sp  = S + w[i];
			way[0].len -= E[i] - B[i];
		}
		
		SORT(way);
		
		double t_rest = t;
		double ret = 0;
		FORI(i, N+1) {
			double sp_w = way[i].sp;
			double sp_r = way[i].sp + (R-S);
			double l_w = way[i].len;
			double l_r = min(t_rest * sp_r, l_w);
			l_w -= l_r;
			
			ret += (l_w / sp_w) + (l_r / sp_r);
			t_rest -= (l_r / sp_r);
		}
		
		//cout <<"Case #" <<tt <<": " <<ret <<endl;
		printf("Case #%d: %.09lf\n", tt, ret);
	}
	
	return 0;
}
