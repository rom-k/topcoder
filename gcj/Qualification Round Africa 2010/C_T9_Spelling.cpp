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
	cin.ignore();
	
	map<char, string> m;
	m.insert(map<char, string>::value_type('a', "2"));
	m.insert(map<char, string>::value_type('b', "22"));
	m.insert(map<char, string>::value_type('c', "222"));
	m.insert(map<char, string>::value_type('d', "3"));
	m.insert(map<char, string>::value_type('e', "33"));
	m.insert(map<char, string>::value_type('f', "333"));
	m.insert(map<char, string>::value_type('g', "4"));
	m.insert(map<char, string>::value_type('h', "44"));
	m.insert(map<char, string>::value_type('i', "444"));
	m.insert(map<char, string>::value_type('j', "5"));
	m.insert(map<char, string>::value_type('k', "55"));
	m.insert(map<char, string>::value_type('l', "555"));
	m.insert(map<char, string>::value_type('m', "6"));
	m.insert(map<char, string>::value_type('n', "66"));
	m.insert(map<char, string>::value_type('o', "666"));
	m.insert(map<char, string>::value_type('p', "7"));
	m.insert(map<char, string>::value_type('q', "77"));
	m.insert(map<char, string>::value_type('r', "777"));
	m.insert(map<char, string>::value_type('s', "7777"));
	m.insert(map<char, string>::value_type('t', "8"));
	m.insert(map<char, string>::value_type('u', "88"));
	m.insert(map<char, string>::value_type('v', "888"));
	m.insert(map<char, string>::value_type('w', "9"));
	m.insert(map<char, string>::value_type('x', "99"));
	m.insert(map<char, string>::value_type('y', "999"));
	m.insert(map<char, string>::value_type('z', "9999"));
	m.insert(map<char, string>::value_type(' ', "0"));
	
	for(int n=1; n<=N; n++) {
		string str;
		//cin >>str;
		getline(cin, str);
		
		string ret;
		char last = ' ';
		for(int i=0; i<str.size(); i++) {
			string add = m[str[i]];
			if (last == add[0]) ret += " ";
			ret += add;
			last = add[add.size()-1];
		}
		
		cout <<"Case #" <<n <<": " <<ret <<endl;
		//printf("Case #%d: %.0lf\n", n, ret);
	}
	
	return 0;
}
