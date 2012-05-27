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

#define MIN 0.000006

double _atod(char a) {
	if(a == '0') return 0.;
	if(a == '1') return 1.;
	if(a == '2') return 2.;
	if(a == '3') return 3.;
	if(a == '4') return 4.;
	if(a == '5') return 5.;
	if(a == '6') return 6.;
	if(a == '7') return 7.;
	if(a == '8') return 8.;
	if(a == '9') return 9.;
}

int main() {
	int TT;
	cin >>TT;
	cin.ignore();
	
	for(int tt=1; tt<=TT; tt++) {
		
		int R, C, D;
		cin >>R >>C >>D;
		
		vector<string> m(R);
		FORI(i, R) cin >>m[i];
		
		int ret = min(R, C);
		
		bool flag = false;
		while(ret >= 3) {
			DBG2("ret",ret);
			FORIS(r, 0, R-ret+1) FORIS(c, 0, C-ret+1) {
				double center_x = ((double)ret-1)/2;
				double center_y = ((double)ret-1)/2;
				double cx = 0.;
				double cy = 0.;
				double sum = 0.;
				
				double tmp = 0;
				FORI(y, ret) {
					tmp += _atod(m[r+y][c+center_x]) * ((double)y - center_y);
				}
				if(fabs(tmp) > MIN) continue;
				
				tmp = 0;
				FORI(x, ret) {
					tmp += _atod(m[r+center_y][c+x]) * ((double)x - center_x);
				}
				if(fabs(tmp) > MIN) continue;
				
				FORI(y, ret) FORI(x, ret) {
					if(x == 0     and y == 0    ) continue;
					if(x == 0     and y == ret-1) continue;
					if(x == ret-1 and y == 0    ) continue;
					if(x == ret-1 and y == ret-1) continue;
					
					//int mass = m[r+y][c+x];
					double mass = _atod(m[r+y][c+x]);
					
					cx += (double)mass * ((double)x - center_x);
					cy += (double)mass * ((double)y - center_y);
					sum += (double)mass;
				}
				cx /= sum;
				cy /= sum;
				if((fabs(cx) < MIN and fabs(cy) < MIN)
				or sum == 0) {
					flag = true;
					break;
				}
			}
			if(flag) break;
			ret --;
		}
		
		if(flag) {
			cout <<"Case #" <<tt <<": " <<ret <<endl;
		}
		else {
			cout <<"Case #" <<tt <<": IMPOSSIBLE" <<endl;
		}
		//cout <<"Case #" <<tt <<": " <<ret <<endl;
		//printf("Case #%d: %.0lf\n", tt, ret);
	}
	
	return 0;
}
