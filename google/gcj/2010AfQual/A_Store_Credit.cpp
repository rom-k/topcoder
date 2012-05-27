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
	int N;
	cin >>N;
	
	for(int n=1; n<=N; n++) {
		int C;
		int I;
		vector<int> P;
		
		cin >>C;
		cin >>I;
		FORI(i, I) {
			int a;
			cin >>a;
			P.PB(a);
		}
		
		int i;
		map<int, int> m;
		for(i=0; i<I; i++) {
			int p = P[i];
			if(m.find(C - p) != m.end()) {
				break;
			}
			m.insert(map<int, int>::value_type(p, i));
		}
		
		cout <<"Case #" <<n <<": " <<m[C-P[i]]+1 <<" " <<i+1 <<endl;
	}
	
	return 0;
}
