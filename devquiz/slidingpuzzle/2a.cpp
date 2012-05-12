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

// Local atoi
int l_atoi(char a) {
	int i = a - '0';
	if(0 <= i && i <= 9) return i;
	i = a - 'A' + 10;
	return i;
}

// Local itoa
char l_itoa(int i) {
	return (i < 10) ? '0' + i
	     :            'A' + i - 10;
}

// Convert to equivalent 6*6 panel
string conv(int w, int h, string a) {
	string b = "====================================";
	FORI(i, 36) {
		if(6 <= h + i / 6 and 6 <= w + i % 6)
			b[i] = a[(i / 6 + h - 6) * w + (i % 6 + w - 6)];
		
		if(b[i] != '=' and b[i] != '0') {
			int n = l_atoi(b[i]) - 1;
			b[i] = l_itoa((n / w + 6 - h) * 6 + (n % w + 6 - w) + 1);
		}
	}
	return b;
}

// Check for valid mask
bool valid(string p, string mask) {
	FORI(i, SZ(mask)) if(mask[i] == '+' and p[i] == '=') return false;
	return true;
}

// Check for panel difference
bool diff(string p1, string p2) {
	FORI(i, SZ(p1)) if(p1[i] != '=' and p2[i] != '=' and p1[i] != p2[i]) return true;
	return false;
}

// Manhattan Distance
int md(string p1, string p2) {
	//FORI(i, 6) cout <<p1.substr(i*6,6) <<"\t" <<p2.substr(i*6,6) <<endl;
	int ret = 0;
	map<char, int> m;
	FORI(i, SZ(p2)) m[p2[i]] = i;
	FORI(i, SZ(p1)) {
		if(p1[i] == '0') continue;
		//cout <<p1[i] <<"\t" <<p2[m[p1[i]]] <<"\t" <<(abs(m[p1[i]]/6 - i/6)+abs(m[p1[i]]%6 - i%6)) <<endl;
		ret += abs(m[p1[i]]/6 - i/6);
		ret += abs(m[p1[i]]%6 - i%6);
	}
	return ret;
}

// State class
struct cstate {
	string panel;
	string path;
	string mask;
	double f;
	
	cstate() {
		cstate("", "", "");
	}
	
	cstate(string panel0, string path0, string mask0) {
		panel = panel0;
		path = path0;
		mask = mask0;
		f = INF;
	}
	
	~cstate() {}
	
	void calc_f(string panel_goal) {
		f = SZ(path) + md(panel, panel_goal);
	}
	
	inline bool operator < (const cstate a) const {
		return f < a.f;
	}
};

// Global variables
set<cstate> open;
set<cstate> close;

// A* Algorithm
string a_star(string panel_goal) {
	
//	cout <<"-----------------------" <<endl;
//	FORI(i, h) cout <<p0.substr(i*w, w) <<endl;
//	cout <<endl;
//	FORI(i, 6) cout <<p.substr(i*6, 6) <<endl;
//	cout <<endl;
	
	/* fの再計算 */
	
	string ret;
	while(true) {
		if(open.empty()) return -1;
		
		/*
		TODO: validなステータスのみ処理しなければならないので、
		priority_queueじゃダメだ。
		openはsetに変更。
		*/
		
//		cstate n = open.top();
//		open.pop();
		
//#define FORE(it, c, T) for(T::iterator it = c.begin(); it != c.end(); it++)
		cstate n;
		FORE(it, open, cstate) {
			if(valid((*it).panel, panel_goal)) {n = *it; break;}
			it++;
		}
		
		/* valid は消すこと */
		if (valid(panel_goal, n.mask) and ! diff(panel_goal, n.panel)) {
			close[n.panel] = n;
			ret = n.path;
			break;
		}
		
		
		
	}
	
	return ret;
}

// Main
int main() {
	
	cstate s0("123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0", "LU", "-----------------------------------+");
	open.insert(s0);
	
	LL LX, RX, UX, DX, T;
	cin >>LX >>RX >>UX >>DX >>T;
	cin.ignore();
	cout <<LX <<" " <<RX <<" " <<UX <<" " <<DX <<endl;
	
	for(int t=1; t<=T; t++) {
		int w, h;
		string a, b;
		cin >>a;
		w = a.at(0) - '0';
		h = a.at(2) - '0';
		b = a.substr(4);
		string g = conv(w, h, b);
		
		/*
		findするだけじゃmaskがあるのでダメ。
		maskをなくして、maskが-の箇所はpanelを=にしとけばいい。
		まぁ、ここはどうせ全部回して探す必要があるけど。
		*/
//#define FORE(it, c, T) for(T::iterator it = c.begin(); it != c.end(); it++)
		cstate s;
		FORE(it, open, cstate) {
			if(valid((*it).panel, g) and ! diff((*it).panel, g)
			and (s.panel == "" or SZ((*it).path) < SZ(s.path))) {
				s = *it;
			}
			it++;
		}
		
		int L = 0; int R = 0; int U = 0; int D = 0;
		FORI(i, SZ(s.path)) {
			if(s.path[i] == 'L') L++;
			if(s.path[i] == 'R') R++;
			if(s.path[i] == 'U') U++;
			if(s.path[i] == 'D') D++;
		}
		cout <<t <<": " <<L <<" " <<R <<" " <<U <<" " <<D <<" " <<s.path <<endl;
	}
	
	return 0;
}
