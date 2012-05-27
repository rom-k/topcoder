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
	
	for(int t=1; t<=T; t++) {
		
		int R, C;
		cin >>R >>C;
		
		vector<string> tile(R);
		FORI(i, R) cin >>tile[i];
		
		cout <<"Case #" <<t <<":" <<endl;
		
		bool impossible = false;
		
		FORI(i, R-1) {
			FORI(j, C-1) {
				if(tile[i][j] == '#') {
					if( tile[i][j+1] == '#'
					and tile[i+1][j] == '#'
					and tile[i+1][j+1] == '#' ) {
						tile[i][j] = '/';
						tile[i][j+1] = '\\';
						tile[i+1][j] = '\\';
						tile[i+1][j+1] = '/';
					}
					else {
						impossible = true;
						break;
					}
				}
			}
			if(tile[i][C-1] == '#') {
				impossible = true;
				break;
			}
			if(impossible)
				break;
		}
		FORI(j, C) {
			if(tile[R-1][j] == '#') {
				impossible = true;
				break;
			}
		}
		
		if(impossible) {
			cout <<"Impossible" <<endl;
		}
		else {
			FORI(i, R) cout <<tile[i] <<endl;
		}
	}
	
	return 0;
}
