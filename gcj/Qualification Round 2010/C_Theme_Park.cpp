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

int main() {
	int N;
	cin >>N;
	cin.ignore();
	
	for(int n=1; n<=N; n++) {
		int R, k, N;
		cin >>R;
		cin >>k;
		cin >>N;
		DBG2("R",R);
		DBG2("k",k);
		
		vector<int> g(N, 0);
		FORI(i, N) {
			cin >>g[i];
			DBG2(i,g[i]);
		}
		
		vector<int> next(N, 0);
		vector<int> gain(N, 0);
		FORI(i, N) {
			int hc = g[i];
			int j = i + 1;
			if (j >= N) j = 0;
			while(true) {
				if (hc + g[j] > k) break;
				if (j == i) break;
				hc += g[j];
				j++;
				if (j >= N) j = 0;
			}
			next[i] = j;
			gain[i] = hc;
			DBG2("next[i]",next[i]);
			DBG2("gain[i]",gain[i]);
		}
		
		double ret = 0;
		int j = 0;
		FORI(r, R) {
			ret += (double)gain[j];
			j = next[j];
		}
		
		//cout <<"Case #" <<n <<": " <<ret <<endl;
		printf("Case #%d: %.0lf\n", n, ret);
	}
	
	return 0;
}
