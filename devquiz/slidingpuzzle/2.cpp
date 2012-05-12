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
#define SZ(a) int((a).size())
#define IPOW(a,b) ((long long) pow((double)(a),(double)(b)))
#define PI M_PI
#define EPS 1e-13
#define INF 0x7f7f7f7f

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

struct cpanel {
	static string panel_g; //path_goal
	string panel;          //panel
	string path;           //path
	int f;    //f(n)
	int g[4]; //g(n)
	int h[4]; //h(n)
	
	cpanel(string panel0, string path0) {
		panel = panel0;
		path = path0;
	}
	
	void set_panel_g(string panel_g0) {
		panel_g = panel_g0;
	}
	
	int calc_h() {
		
	}
	
	int calc_f() {
		f = g[0]+g[1]+g[2]+g[3]+h[0]+h[1]+h[2]+h[3];
		return f;
	}
	
	inline bool operator < (const cpanel a) {
		return calc_f() < a.f;
	}
};

// Local atoi
int l_atoi(char a) {
	int i = a - '0';
	if(0 <= i && i <= 9) return i;
	i = a - 'A' + 10;
	return i;
}

// Manhattan Distance
int md(int w, int h, string p1, string p2) {
	//FORI(i, h) cout <<p1.substr(i*w,w) <<"\t" <<p2.substr(i*w,w) <<endl;
	int ret = 0;
	map<char, int> m;
	FORI(i, SZ(p2)) m[p2[i]] = i;
	FORI(i, SZ(p1)) {
		if(p1[i] == '0') continue;
		//cout <<p1[i] <<"\t" <<p2[m[p1[i]]] <<"\t" <<(abs(m[p1[i]]/w - i/w)+abs(m[p1[i]]%w - i%w)) <<endl;
		ret += abs(m[p1[i]]/w - i/w);
		ret += abs(m[p1[i]]%w - i%w);
	}
	return ret;
}

// A* Algorithm
string a_star(int w, int h, string p0) {
	string p_solved = p0;
	FORI(i, SZ(p_solved))
		p_solved[i] = (p_solved[i] == '=')  ? '='
		            : (i == SZ(p_solved)-1) ? '0'
		            : (i >= 9)              ? (i - 9 + 'A')
		            :                         (i + '1');
	
	//cout <<"\t" <<md(w,h,p0,p_solved) <<endl;
	
	return "LLUD";
}

// Main
int main() {
	LL LX, RX, UX, DX;
	cin >>LX >>RX >>UX >>DX;
	cout <<LX <<" " <<RX <<" "
		<<UX <<" " <<DX <<endl;
	
	LL T;
	cin >>T;
	cin.ignore();
	
	for(int t=1; t<=T; t++) {
		int w, h;
		string a, b;
		cin >>a;
		w = a.at(0) - '0';
		h = a.at(2) - '0';
		b = a.substr(4);
		
		string ret = a_star(w, h, b);
		
		int L = 0; int R = 0; int U = 0; int D = 0;
		FORI(i, SZ(ret)) {
			if(ret[i] == 'L') L++;
			if(ret[i] == 'R') R++;
			if(ret[i] == 'U') U++;
			if(ret[i] == 'D') D++;
		}
		cout <<t <<" " <<L <<" " <<R <<" "
			<<U <<" " <<D <<" " <<ret <<endl;
	}
	
	return 0;
}
