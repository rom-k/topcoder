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
#define REVERSE(a) reverse(a.begin(), a.end())
#define PB(n) push_back(n)
#define PI M_PI
#define EPS 1e-13

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

int main() {
	int N;
	cin >>N;
	cin.ignore();
	
	for(int n=1; n<=N; n++) {
		int M;
		cin >>M;
		
		vector<int> P;
		for(int i=0; i<12; i++) {
			int tmp; cin >>tmp;
			P.PB(tmp);
		}
		
		int max_i = -1;
		int max_j = -1;
		int max_p = -1;
		for(int i=0; i<11; i++) for(int j=i+1; j<12; j++) {
			if (M < P[i] or P[j] < P[i]) continue;
			
			int p = (P[j] - P[i]) * (M / P[i]);
			if (p > max_p
			or p == max_p and P[i] < P[max_i]) {
				max_i = i;
				max_j = j;
				max_p = p;
			}
		}
		
		if (max_p < 0) {
			cout <<"Case #" <<n <<": IMPOSSIBLE"<<endl;
			continue;
		}
		
		cout <<"Case #" <<n <<": " <<max_i+1 <<" " <<max_j+1 <<" " <<max_p <<endl;
	}
	
	return 0;
}
