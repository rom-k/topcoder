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

bool symp(LL a, LL b) {
	if(a % b == 0 or b % a == 0)
		return true;
	return false;
}

int main() {
	int T;
	cin >>T;
	cin.ignore();
	
	for(int t=1; t<=T; t++) {
		
		LL N, L, H;
		cin >>N >>L >>H;
		
		vector<LL> f(N, 0);
		FORI(i, N) cin >>f[i];
		
		SORT(f);
		
		vector<LL> gcd(N+1);
		vector<LL> lcm(N+1);
		
		gcd[N]   = -1;
		gcd[N-1] = f[N-1];
		for(int i = N-2; i >= 0; i--) {
			gcd[i] = _gcd2(gcd[i+1], f[i]);
		}
		
		lcm[0] = -1;
		lcm[1] = f[0];
		FORIS(i, 1, N) {
			lcm[i+1] = _lcm2(lcm[i], f[i]);
			DBG2(i+1,lcm[i+1]);
		}
		
		LL i = 0;
		FORI(k, N) {
			if(f[k] <= L) i = k + 1;
			else          break;
		}
		
		LL ret = 0;
		FORIS(j, L, H+1) {
			if(i < N and f[i] <= j) i++;
			
			if(j == 9973) {
				DBG2("j",j);
				DBG2("i",i);
				DBG2("f[i]",f[i]);
				DBG2("lcm[i]",lcm[i]);
				DBG2("gcd[i]",gcd[i]);
			}
			
			if( (lcm[i] < 0 or j % lcm[i] == 0)
			and (gcd[i] < 0 or gcd[i] % j == 0) ) {
				ret = j;
				break;
			}
		}
		
		if(ret == 0) {
			cout <<"Case #" <<t <<": NO" <<endl;
		}
		else {
			cout <<"Case #" <<t <<": " <<ret <<endl;
		}
		//printf("Case #%d: %.0lf\n", t, ret);
	}
	
	return 0;
}
