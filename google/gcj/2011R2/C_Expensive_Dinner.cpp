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

LL _gcd2(LL a, LL b) {
	if (a < b) { LL c = a; a = b; b = c; }
    if (b == 0) return a;
    return _gcd2(b, a%b);
}

LL _gcd(vector<LL> a) {
	LL ret = a[0];
	for(LL i=1; i<a.size(); i++)
		ret = _gcd2(ret, a[i]);
	return ret;
}

LL _lcm2(LL a, LL b) {
	return b * a / _gcd2(a, b);
}

LL _lcm(vector<LL> a) {
	LL ret = a[0];
	for(LL i=1; i<a.size(); i++)
		ret = _lcm2(ret, a[i]);
	return ret;
}

int main() {
	int T;
	cin >>T;
	cin.ignore();
	
	for(int t=1; t<=T; t++) {
		
		int N;
		cin >>N;
		cin.ignore();
		
		LL cnt = 0;
		LL cost = 0;
		
		FORIS(i, 1, N+1) {
			if(cost == 0) {
				cost = i;
				cnt++;
			}
			if(cost % i != 0) {
				cost = _lcm2(cost, i);
				cnt++;
			}
		}
		
		cost = 0;
		for(int i = N; i >= 1; i--) {
			if(cost == 0) {
				cost = i;
				cnt--;
			}
			if(cost % i != 0) {
				cost = _lcm2(cost, i);
				cnt--;
			}
		}
		
		cout <<"Case #" <<t <<": " <<cnt <<endl;
		//printf("Case #%d: %.0lf\n", t, ret);
	}
	
	return 0;
}
