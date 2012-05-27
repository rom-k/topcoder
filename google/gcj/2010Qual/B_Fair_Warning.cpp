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

struct lllint {
	vector<int> num;
	
	lllint () { }
	
	lllint (string a) { init(a); }
	
	void init (string a) {
		DBG2("a",a);
		DBG2("num",num);
		if(!num.empty()) num.clear();
		DBG("A");
		for(int i = a.size()-1; i >= 0; i--) num.push_back((int) a[i]);
	}
	
	int cmp (lllint a) {
		if(num.size() > a.num.size()) return 1;
		if(num.size() < a.num.size()) return -1;
		for(int i = num.size(); i >= 0; i--) {
			if(num[i] > a.num[i]) return 1;
			if(num[i] < a.num[i]) return -1;
		}
		return 0;
	}
	
	lllint clone () {
		lllint a;
		for(int i=0; i<num.size(); i++) a.num.push_back(num[i]);
		return a;
	}
	
	lllint add (lllint a) {
		lllint b;
		int carry = 0;
		int size  = max(num.size(), a.num.size());
		for(int i=0; i<size; i++) {
			int sum = num[i] + a.num[i] + carry;
			carry = sum / 10;
			sum   = sum % 10;
			b.num.push_back(sum);
		}
		if (carry != 0) { b.num.push_back(carry); }
		return b;
	}
	
	lllint sub (lllint a) {
		lllint b;
		if (cmp(a) < 0) return b;
		int carry = 0;
		int size  = max(num.size(), a.num.size());
		for(int i=0; i<size; i++) {
			int sub = num[i] - a.num[i] + carry;
			if (sub < 0) { sub += 10; carry = -1; }
			b.num.push_back(sub);
		}
		return b;
	}
	
	string to_str () {
		string str;
		for(int i = num.size()-1; i >= 0; i--) str + (char)num[i];
	}
	
//	inline lllint operator = () {
//		lllint a;
//		a = clone();
//		return a;
//	}
	
//	inline lllint operator + (const lllint &a) {
//		lllint b;
//		b = clone();
//		//TODO
//	}
};

/*
double _gcd2(double a, double b) {
	if (a < b) { double c = a; a = b; b = c; }
    if (b == 0) return a;
    return _gcd2(b, fmod(a, b));
}

double _gcd(vector<double> a) {
	double ret = a[0];
	for(double i=1; i<a.size(); i++)
		ret = _gcd2(ret, a[i]);
	return ret;
}
*/

int main() {
	int C;
	cin >>C;
	cin.ignore();
	
	for(int c=1; c<=C; c++) {
		
		int N;
		cin >>N;
		
		vector<lllint> t;
		FORI(i, N) {
			string tmp;
			cin >>tmp;
			t[i].init(tmp);
			DBG2(tmp,t[i].to_str());
		}
		
//		SORT(t);
//		
//		vector<double> diff(N-1, 0);
//		FORI(i, N-1) {
//			diff[i] = t[i+1] - t[i];
//			DBG2("t[i+1] - t[i]",t[i+1] - t[i]);
//		}
//		
//		double T = _gcd(diff);
//		if(diff.size() <= 1) T = diff[0];
//		DBG2("diff[0]",diff[0]);
//		DBG2("T",T);
//		
//		double ret = -t[0];
//		while(ret < 0) { ret += T; }
//		//cout <<"Case #" <<c <<": " <<ret <<endl;
//		printf("Case #%d: %.0lf\n", c, ret);
	}
	
	return 0;
}
