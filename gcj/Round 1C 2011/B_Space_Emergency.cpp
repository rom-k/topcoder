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

int main() {
	int T;
	cin >>T;
	cin.ignore();
	
	for(int tt=1; tt<=T; tt++) {
		
		LL L, t, N, C;
		cin >>L >>t >>N >>C;
		
		vector<LL> a(C, 0);
		FORI(i, C) cin >>a[i];
		
		double l_sum = 0;
		//vector<LL> l(N);
		vector<double> l_b(N);
		
		LL cnt = 0;
		FORI(i, N) {
			l_b[i] = a[cnt];
			l_sum += a[cnt];
			
			l_b[i] = min(l_b[i], l_sum - (double)t / 2);
			if(l_b[i] < 0) l_b[i] = 0;
			
			if(++cnt >= C) cnt = 0;
		}
		
		SORT(l_b);
		
		double l_b2 = 0.;
		FORI(i, L) {
			l_b2 += l_b[N - 1 - i];
		}
		
		double ret = l_sum * 2 - l_b2;
		
//		cout <<"Case #" <<tt <<": " <<setprecision(10) <<ret <<endl;
		printf("Case #%d: %.0lf\n", tt, ret);
//		printf("Case #%d: %lf\n", tt, ret);
	}
	
	return 0;
}
