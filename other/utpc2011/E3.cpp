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

struct prob {
	LL use;
	LL limit;
	
	inline bool operator < (const prob a) const {
		return limit < a.limit;
	}
};

int main() {
	int N;
	cin >>N;
	
	vector<prob> p(N);
	FORI(i, N) {
		cin >>p[i].use >>p[i].limit;
	}
	
	SORT(p);
	
	//greedy
	list<int> g;
	LL time = 0;
	FORI(i, N) {
		if(time + p[i].use <= p[i].limit) {
			g.PB(i);
			time += p[i].use;
		}
		else {
			int id;
			LL max_used = 0;
			FORE(it, g, list<int>) {
				if(p[*it].use > max_used) {
					id = *it;
					max_used = p[*it].use;
				}
			}
			
			if(p[i].use < max_used) {
				g.remove(id);
				g.PB(i);
				time -= p[id].use;
				time += p[i].use;
			}
		}
	}
	
	cout <<g.size() <<endl;
	return 0;
}
