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

int num_day(int y, int m) {
	if(m == 9 or m == 4 or m == 6 or m == 11) {
		return 30;
	}
	else if(m != 2) {
		return 31;
	}
	else if(y % 4 != 0 or y % 400 != 0 and y % 100 == 0) {
		return 28;
	}
	else {
		return 29;
	}
}

int main() {
	
	int days = 1;
	int cnt = 0;
	FORIS(y, 1900, 2001) {
		FORIS(m, 1, 13) {
			days += num_day(y, m);
			days = days % 7;
			if(y > 1900 and days == 0) cnt++;
		}
	}
	
	cout <<cnt <<endl;
	return 0;
}
