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

#define DEBUG 1
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
	
	DBG2("maxtime",maxtime);
	
	SORT(p);
	
	map<LL, int> dp;
	for(LL i=p.size()-1; i>=0; i--) {
		map<LL, int> dp2;
		
		if(dp.find(p[i].limit) == dp.end()) dp[p[i].limit] = 0;
		if(dp.find(p[i].limit - p[i].use) == dp.end()) dp[p[i].limit - p[i].use] = 0;
		dp2[p[i].limit - p[i].use] = max(dp[p[i].limit - p[i].use], dp[p[i].limit] + 1);
		
		for(map<LL, int>::iterator it = dp.begin(); it != dp.end(); it++)
			if(0 <= (*it).first - p[i].use) {
				if(dp.find((*it).first - p[i].use) == dp.end()) dp[(*it).first - p[i].use] = 0;
				dp2[(*it).first - p[i].use] = max(dp[(*it).first - p[i].use], (*it).second + 1);
			}
		
		for(map<LL, int>::iterator it = dp2.begin(); it != dp2.end(); it++)
			dp[(*it).first] = (*it).second;
	}
	
	int ret = 0;
	for(map<LL, int>::iterator it = dp.begin(); it != dp.end(); it++)
		ret = max(ret, (*it).second);
	
	cout <<ret <<endl;
	
	return 0;
}
