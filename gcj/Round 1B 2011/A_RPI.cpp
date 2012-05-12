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
	int T;
	cin >>T;
	cin.ignore();
	
	for(int t=1; t<=T; t++) {
		
		int N;
		cin >>N;
		
		vector<string> m(N);
		FORI(i, N) cin >>m[i];
		
		vector<double> WP(N, 0.);
		vector<vector<double> > WPt(N, vector<double>(N, -1));
		
		FORI(i, N) {
			double nwin = 0.;
			double nlos = 0.;
			FORI(j, N) {
				if     (m[i][j] == '1') nwin++;
				else if(m[i][j] == '0') nlos++;
			}
			WP[i] = nwin / (nwin + nlos);
			DBG2("WP[i]",WP[i]);
			
			FORI(j, N) {
				if     (m[i][j] == '1') WPt[i][j] = (nwin - 1) / (nwin - 1 + nlos);
				else if(m[i][j] == '0') WPt[i][j] = nwin / (nwin + nlos - 1);
			}
		}
		
		vector<double> OWP(N, 0.);
		
		FORI(i, N) {
			double cnt = 0.;
			double sum = 0.;
			FORI(j, N) {
				if(WPt[j][i] != -1) {
					cnt++;
					sum += WPt[j][i];
				}
			}
			OWP[i] = sum / cnt;
			DBG2("OWP[i]",OWP[i]);
		}
		
		vector<double> OOWP(N, 0.);
		
		FORI(i, N) {
			double cnt = 0.;
			double sum = 0.;
			FORI(j, N) {
				if(m[i][j] != '.') {
					cnt++;
					sum += OWP[j];
				}
			}
			OOWP[i] = sum / cnt;
			DBG2("OOWP[i]",OOWP[i]);
		}
		
		cout <<"Case #" <<t <<":" <<endl;
		FORI(i, N) {
			cout <<setprecision(12);
			cout <<(0.25 * WP[i] + 0.50 * OWP[i] + 0.25 * OOWP[i]);
			cout <<endl;
		}
	}
	
	return 0;
}
