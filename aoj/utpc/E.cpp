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

struct prob {
	LL use;
	LL limit;
	
	inline bool operator < (const prob a) const {
		return limit < a.limit;
	}
};

int main() {
	int N;
	cin >>N;
	
	LL maxtime = 0;
	vector<prob> p(N);
	FORI(i, N) {
		cin >>p[i].use >>p[i].limit;
		maxtime = max(maxtime, p[i].limit);
	}
	
	SORT(p);
	
	vector<int> dp(maxtime+1, 0);
	for(LL i=p.size()-1; i>=0; i--) {
		for(LL j=0; j<=p[i].limit - p[i].use; j++) {
			dp[j] = max(dp[j], dp[j+p[i].use] + 1);
		}
	}
	
	int ret = 0;
	for(LL i=0; i<p.size(); i++) {
		ret = max(ret, dp[i]);
	}
	
	cout <<ret <<endl;
	return 0;
}
