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
		
		vector<double> list(N, 0.);
		vector<double> sorted;
		vector<double> never;
		
		FORI(i, N) cin >>list[i];
		SORT(list);
		
		double mul = 1.;
		FORI(i, 100) {
			if (list.size() <= 0) break;
			
			mul *= 3;
			DBG2("i",i);
			
			FORI(j, list.size()) {
				
				// num = list[j] * 3^(i+1) % 3
				double num = fmod(list[j] * mul, 3);
				
				DBG2("  list[j]",list[j]);
				DBG2("  fmod(list[j] * mul, 3)",num);
				
				// eliminated at i+1 -th interval
				if(1 <= num and num <= 2) {
					sorted.PB(list[j]);
					list.erase(list.begin()+j); // vector erase (remove) n-th element
					j--;
					
					DBG("    =>erased");
				}
				
				// never eliminated
				else if(fabs(fmod(num, 1) - list[j]) < EPS) {
					never.PB(list[j]);
					list.erase(list.begin()+j);
					j--;
					
					DBG("    =>never");
				}
			}
		}
		SORT(never);
		FORI(j, list.size()) sorted.PB(list[j]);
		FORI(j, never.size()) sorted.PB(never[j]);
		
		cout <<"Case #" <<t <<":" <<endl;
		FORE(it, sorted, vector<double>) {
			cout <<setprecision(15) <<(*it) <<endl;
		}
	}
	
	return 0;
}
