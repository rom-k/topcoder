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
bool valid(string p, string g) {
	FORI(i, 36) if(g[i] == '=' and p[i] != '=') return false;
	return true;
}

// Check for panel difference
bool same(string p, string g) {
	if(! valid(p, g)) return false;
	FORI(i, 36) if(p[i] != '=' and p[i] != g[i]
	            or p[i] == '=' and p[i] != l_itoa(i+1)) return false;
	return true;
}

// Manhattan Distance
int md(string p1, string p2) {
	//FORI(i, 6) cout <<p1.substr(i*6,6) <<"\t" <<p2.substr(i*6,6) <<endl;
	int ret = 0;
	map<char, int> m;
	FORI(i, SZ(p2)) m[p2[i]] = i;
	FORI(i, SZ(p1)) {
		if(p1[i] == '0'
		or p1[i] == '='
		or p2[m[p1[i]]] == '=') continue;
		//cout <<p1[i] <<"\t" <<p2[m[p1[i]]] <<"\t" <<(abs(m[p1[i]]/6 - i/6)+abs(m[p1[i]]%6 - i%6)) <<endl;
		ret += abs(m[p1[i]]/6 - i/6);
		ret += abs(m[p1[i]]%6 - i%6);
	}
	return ret;
}

// Global variables 1
string panel_goal;

// State class
struct cstate {
	string panel;
	string path;
//	double f;
	
	cstate() {
		cstate("", "");
	}
	
	cstate(string panel0, string path0) {
		panel = panel0;
		path = path0;
//		f = INF;
	}
	
	~cstate() {}
	
//	void calc_f(string panel_goal) {
//		f = SZ(path) + md(panel, panel_goal);
//	}
	
	inline bool operator < (const cstate a) const {
		return SZ(path) + md(panel, panel_goal) < SZ(a.path) + md(a.panel, panel_goal);
	}
};

// Global variables 2
set<cstate> open;
set<cstate> close;

// A* Algorithm
string a_star() {
	
	if(DEBUG) cout <<"---- panel_goal" <<endl;
	if(DEBUG) FORI(i, 6) cout <<panel_goal.substr(i*6, 6) <<endl;
	if(DEBUG) cout <<endl;
	
//	FORE(it, open , set<cstate>) it->f = SZ(it->path) + md(it->panel, panel_goal);
//	FORE(it, close, set<cstate>) it->calc_f(panel_goal);
	
	string ret;
	while(true) {
		if(open.empty()) {
			if(DEBUG) cout <<"error." <<endl <<endl;
			break;
		}
		
		// remove n from open and insert to close
		cstate n;
		FORE(it, open, set<cstate>) {
			if(valid((*it).panel, panel_goal)) {
				n = *it;
				open.erase(it);
				break;
			}
		}
		close.insert(n);
		
		if(DEBUG) cout <<"-------- n" <<endl;
		if(DEBUG) FORI(i, 6) cout <<n.panel.substr(i*6, 6) <<endl;
		if(DEBUG) cout <<endl;
		
		// solved if n is goal.
		if (same(n.panel, panel_goal)) {
			if(DEBUG) cout <<"cleared." <<endl <<endl;
			ret = n.path;
			break;
		}
		
		// find '0'
		int pos0;
		FORI(i, 36) if(n.panel[i] == '0') pos0 = i;
		if(DEBUG) cout <<"pos0=" <<pos0 <<endl <<endl;
		
		FORI(i, 4) {
			// i=0 : L : swap pos0 <=> pos0+1
			// i=1 : R : swap pos0 <=> pos0-1
			// i=2 : U : swap pos0 <=> pos0+6
			// i=3 : D : swap pos0 <=> pos0-6
			
			if(i==0 and pos0%6==5) continue;
			if(i==1 and pos0%6==0) continue;
			if(i==2 and pos0/6==5) continue;
			if(i==3 and pos0/6==0) continue;
			
			string p = n.panel;
			string t;
			
			if(i==0) { p[pos0] = (p[pos0+1]!='=') ? p[pos0+1] : l_itoa(pos0+1+1) ; p[pos0+1] = '0'; t = "L"; }
			if(i==1) { p[pos0] = (p[pos0-1]!='=') ? p[pos0-1] : l_itoa(pos0-1+1) ; p[pos0-1] = '0'; t = "R"; }
			if(i==2) { p[pos0] = (p[pos0+6]!='=') ? p[pos0+6] : l_itoa(pos0+6+1) ; p[pos0+6] = '0'; t = "U"; }
			if(i==3) { p[pos0] = (p[pos0-6]!='=') ? p[pos0-6] : l_itoa(pos0-6+1) ; p[pos0-6] = '0'; t = "D"; }
			
			t += n.path;
			cstate m(p, t);
			
			if(DEBUG) cout <<"-------- m : " <<t <<endl;
			if(DEBUG) FORI(i, 6) cout <<m.panel.substr(i*6, 6) <<endl;
			if(DEBUG) cout <<endl;
			
			bool new_p = true;
			string old_t = "";
			
			FORE(it, open , set<cstate>) {
				bool match = true;
				FORI(j, 36) if(p[j] != it->panel[j]) { match = false; break; }
				
				if(match) {
					if (m < (*it)) {
						old_t = it->path;
						open.erase(it);
					}
					
					new_p = false;
					break;
				}
			}
			
			FORE(it, close , set<cstate>) {
				bool match = true;
				FORI(j, 36) if(p[j] != it->panel[j]) { match = false; break; }
				
				if(match) {
					if (m < (*it)) {
						old_t = it->path;
						close.erase(it);
					}
					
					new_p = false;
					break;
				}
			}
			
			if(DEBUG) cout <<"new_p=" <<new_p <<endl;
			if(DEBUG) cout <<"old_t=" <<old_t <<endl <<endl;
			
			if(new_p) {
				open.insert(m);
				if(DEBUG) cout <<"add new m to open" <<endl <<endl;
			}
			
			if(! new_p and old_t != "") {
				open.insert(m);
				if(DEBUG) cout <<"update m" <<endl <<endl;
				
				FORE(it, open , set<cstate>)
					if(it->path.substr(SZ(it->path)-SZ(old_t)) == old_t) {
						cstate l(p, it->path.substr(SZ(it->path)-SZ(old_t)) + t);
						open.insert(l);
						open.erase(it);
					}
				
				FORE(it, close , set<cstate>)
					if(it->path.substr(SZ(it->path)-SZ(old_t)) == old_t) {
						cstate l(p, it->path.substr(SZ(it->path)-SZ(old_t)) + t);
						close.insert(l);
						close.erase(it);
					}
			}
		}
	}
	
	return ret;
}

/****************************************************************************
 * Main
 ****************************************************************************/

int main() {
	
	cstate s0("===================================0", "");
	open.insert(s0);
	
	LL LX, RX, UX, DX, T;
	cin >>LX >>RX >>UX >>DX >>T;
	cout <<LX <<" " <<RX <<" " <<UX <<" " <<DX <<endl;
	
	for(int t=1; t<=T; t++) {
		int w, h;
		string a, b;
		cin >>a;
		w = a.at(0) - '0';
		h = a.at(2) - '0';
		b = a.substr(4);
		panel_goal = conv(w, h, b);
		
		string path = "";
		FORE(it, close, set<cstate>) {
			if(same((*it).panel, panel_goal)
				and (path == "" or SZ((*it).path) < SZ(path))
			) {
				path = (*it).path;
			}
			it++;
		}
		
		if(path == "") {
			path = a_star();
		}
		
		int L = 0; int R = 0; int U = 0; int D = 0;
		FORI(i, SZ(path)) {
			if(path[i] == 'L') L++;
			if(path[i] == 'R') R++;
			if(path[i] == 'U') U++;
			if(path[i] == 'D') D++;
		}
		cout <<t <<": " <<L <<" " <<R <<" " <<U <<" " <<D <<" " <<path <<endl;
	}
	
	return 0;
}
