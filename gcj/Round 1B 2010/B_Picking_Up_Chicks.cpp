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
	int C;
	cin >>C;
	cin.ignore();
	
	for(int c=1; c<=C; c++) {
		//N=num of chicken             ~50
		//K=num of desired chicken
		//B=location of the barn       ~1e9
		//T=time                       ~1e3
		//Xi=location of each chicken
		//Vi=speed of each chicken
		
		int N, K, B, T;
		cin >>N >>K >>B >>T;
		
		vector<int> X(N, 0);
		FORI(i, N) cin >>X[i];
		
		vector<int> V(N, 0);
		FORI(i, N) cin >>V[i];
		
		int k = 0;
		int k_not_reached = 0;
		int ret = 0;
		for(int i=N-1; i>=0; i--) {
			if (K <= k) break;
			
			if (B <= X[i] + V[i] * T) {
				k++;
				ret += k_not_reached;
			}
			else {
				k_not_reached++;
			}
		}
		
		if (K <= k) { cout <<"Case #" <<c <<": " <<ret <<endl; }
		else        { cout <<"Case #" <<c <<": IMPOSSIBLE" <<endl; }
		//cout <<"Case #" <<c <<": " <<ret <<endl;
		//printf("Case #%d: %.0lf\n", c, ret);
	}
	
	return 0;
}
