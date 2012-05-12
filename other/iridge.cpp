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
	LL N = 1000000;
	
	double c15[16];
	c15[0]  = 1.;
	c15[1]  = 15.;
	c15[2]  = 105.;
	c15[3]  = 455.;
	c15[4]  = 1365.;
	c15[5]  = 3003.;
	c15[6]  = 5005.;
	c15[7]  = 6435.;
	c15[8]  = 6435.;
	c15[9]  = 5005.;
	c15[10] = 3003.;
	c15[11] = 1365.;
	c15[12] = 455.;
	c15[13] = 105.;
	c15[14] = 15.;
	c15[15] = 1.;
	
	double s[16];
	double p[16];
	FORI (i, 16) s[i] = 0.;
	FORI (i, 16) p[i] = 0.;
	
	double p1 = c15[0];
	FORI (k, 15) p1 *= (15. - k) / (N - k);
	
	p[15%16] = 1.;
	s[15%16] = 1. / (1. - p1);
	
	if(DEBUG) printf("i\tp\ts\n");
	if(DEBUG) printf("%d\t%f\t%f\n",15, p[15%16], s[15%16]);
	
	FORIS (i, 16, N+1) {
		
		p[i%16] = 0.;
		s[i%16] = 0.;
		FORI (j, 15) {
			double p2 = c15[j];
			FORI (k, 15-j) p2 *= (N - (i - 15 + j) - k);
			FORI (k, j   ) p2 *= (i - 15 + j - k);
			FORI (k, 15  ) p2 /= (N - k);
			
			double p3 = c15[0];
			FORI (k, 15) p3 *= ((double)i - 15 + j - k) / (N - k);
			
			p[i%16] +=  p[(i-15+j)%16] * p2 / (1. - p3);
			s[i%16] += (p[(i-15+j)%16] * p2 / (1. - p3)) * s[(i-15+j)%16];
		}
		s[i%16] /= p[i%16];
		
		if (i != N) {
			double p1 = c15[0];
			FORI (k, 15) p1 *= ((double)i - k) / (N - k);
			s[i%16] += 1. / (1. - p1);
		}
		else {
			s[i%16]++;
		}
		
		if(DEBUG) cout <<i <<"\t" <<p[i%16] <<"\t" <<setprecision(10) <<s[i%16] <<endl;
	}
	
	if(DEBUG) cout <<endl;
	printf("=> %d\n", (LL)(525 * s[N%16]));
	
	//=> 503742154
	
	return 0;
}
