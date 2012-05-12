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

bool sym(char a, char b) {
	if     (a == 'i' and b == 'i') { return true; }
	else if(a == 'w' and b == 'w') { return true; }
	else if(a == '(' and b == ')') { return true; }
	else if(a == ')' and b == '(') { return true; }
	else                           { return false; }
}

int main() {
	string str;
	cin >>str;
	
	int count = 0;
	FORI(i, str.size() / 2 + (str.size() % 2 == 0 ? 0 : 1))
		if(! sym(str[i], str[str.size() - i - 1])) count++;;
	
	cout <<count <<endl;
	
	return 0;
}
