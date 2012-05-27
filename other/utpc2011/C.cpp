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

bool sym(char a, char b) {
	if     (a == 'i' and b == 'i') { return true; }
	else if(a == 'w' and b == 'w') { return true; }
	else if(a == '(' and b == ')') { return true; }
	else if(a == ')' and b == '(') { return true; }
	else if(a == '{' and b == '}') { return true; }
	else if(a == '}' and b == '{') { return true; }
	else if(a == '[' and b == ']') { return true; }
	else if(a == ']' and b == '[') { return true; }
	else                           { return false; }
}

int max_len(string str, int left, int right, int len) {
	
	if(DEBUG) {
		cout <<str <<endl;
		FORI(i, str.size()) cout<<(i==left or i==right ? "|" : " ");
		cout <<endl;
	}
	
	if(left <= 0) {
		DBG("end");
		return len;
	}
	else if(right >= str.size()-1) {
		DBG("end");
		return len;
	}
	
	else if(sym(str[left-1], str[right+1])) {
		DBG("symmetry -> go next");
		return max_len(str, left-1, right+1, len+2);
	}
	else {
		DBG("asymmetry -> check 3 patterns.");
		DBG(" pattern.1 don't use left nor right.");
		int len2 = max_len(str, left-1, right+1, len);
		int right_n = -1;
		for(int i=right+2; i<str.size(); i++)
			if(sym(str[left-1], str[i])) {right_n = i; break;}
		if(right_n >= 0) {
			if(DEBUG) {
				cout <<str <<endl;
				FORI(i, str.size()) cout<<(i==left or i==right ? "|" : " ");
				cout <<endl;
			}
			DBG(" pattern.2 use left.");
			len2 = max(len2, max_len(str, left-1, right_n, len+2));
		}
		
		int left_n = -1;
		for(int i=left-2; i>=0; i--)
			if(sym(str[i], str[right+1])) {left_n = i; break;}
		if(left_n >= 0) {
			if(DEBUG) {
				cout <<str <<endl;
				FORI(i, str.size()) cout<<(i==left or i==right ? "|" : " ");
				cout <<endl;
			}
			DBG(" pattern.3 use right.");
			len2 = max(len2, max_len(str, left_n, right+1, len+2));
		}
		
		return len2;
	}
}

int main() {
	string str;
	cin >>str;
	
	int center = str.find("iwi") + 1;
	
	DBG2("center",center);
	
	cout <<max_len(str,center,center,1) <<endl;
	
	return 0;
}
