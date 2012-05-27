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
		int num_loop;
		cin >>num_loop;
		
		vector<int> r;
		vector<int> b;
		for(int l=0; l<num_loop; l++) {
			int len;
			char c;
			scanf("%d%c", &len, &c);
			if (c == 'R') { r.PB(len); }
			else          { b.PB(len); }
		}
		
		int num_use = min(r.size(), b.size());
		SORT(r);
		SORT(b);
		REVERSE(r);
		REVERSE(b);
		
		int ret = 0;
		for (int i=0; i<num_use; i++) {
			ret += r[i] + b[i] - 2;
		}
		
		cout <<"Case #" <<n <<": " <<ret <<endl;
	}
	
	return 0;
}
