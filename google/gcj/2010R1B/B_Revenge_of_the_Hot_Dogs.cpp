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

bool func(vector<LL> p, LL D, double t) {
	double cur = (double)p[0] - t;
	FORIS(i, 1, p.size()) {
		if((double)p[i] + t < cur + D) { return false; }
		cur = max(cur + D, (double)p[i] - t);
	}
	return true;
};

int main() {
	int T;
	cin >>T;
	cin.ignore();
	
	for(int t=1; t<=T; t++) {
		
		LL C, D;
		cin >>C >>D;
		
		vector<LL> p;
		FORI(i, C) {
			int P, V;
			cin >>P >>V;
			FORI(j, V) p.PB(P);
		}
		
		SORT(p);
		
		// binary search
		LL high = 1000000000000000LL;
		LL low  = 0;
		while(low + 1 < high) {
			
			LL mid = (high + low) / 2;
			
			if(func(p, D, mid)) high = mid;
			else                low = mid;
		}
		
		double ret;
		if     (func(p, D, low))                ret = low;
		else if(func(p, D, (double)high - 0.5)) ret = (double)high - 0.5;
		else                                    ret = high;
		
		//cout <<"Case #" <<t <<": " <<ret <<endl;
		printf("Case #%d: %.1llf\n", t, ret);
	}
	
	return 0;
}
