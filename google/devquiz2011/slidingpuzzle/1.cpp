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

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

int _atoi(char a) {
	int i = a - '0';
	if(0 <= i && i <= 9) return i;
	i = a - 'A' + 10;
	return i;
}

void bfs(int w, int h, string b, VS *r) {
	map <string, string> m;
	queue <string> q;
	q.push(b);
	
	if(DEBUG) cout <<"w=" <<w <<endl;
	if(DEBUG) cout <<"h=" <<h <<endl;
	
	while(! q.empty()) {
		string panel = q.front();
		string step = m[panel];
		q.pop();
		
		if(DEBUG) cout <<"panel=" <<panel <<endl;
		if(DEBUG) cout <<"step=" <<step <<endl;
		
		// clear check
		bool c = true;
		FORI(i, w*h-1)
			if(panel[i] == '=' || _atoi(panel[i]) == i+1)
				c = false;
		
		// clear
		if(c) {
			if(DEBUG) cout <<" => clear" <<endl;
			(*r).PB(step);
			break;
		}
		
		// find '0'
		int pos0;
		FORI(i, w*h) if(panel[i] == '0') pos0 = i;
		if(DEBUG) cout <<"pos0=" <<pos0 <<endl;
		
		// L
		if(pos0 % w != 0) {
			string n = panel;
			n[pos0] = panel[pos0-1];
			n[pos0-1] = panel[pos0];
			
			if(m.find(n) == m.end()) {
				if(DEBUG) cout <<"(L)panel_n=" <<n <<endl;
				m[n] = step + 'L';
				q.push(n);
			}
		}
		
		// R
		if(pos0 % w != w - 1) {
			string n = panel;
			n[pos0] = panel[pos0+1];
			n[pos0+1] = panel[pos0];
			
			if(m.find(n) == m.end()) {
				if(DEBUG) cout <<"(R)panel_n=" <<n <<endl;
				m[n] = step + 'R';
				q.push(n);
			}
		}
		
		// U
		if(pos0 / w != 0) {
			string n = panel;
			n[pos0] = panel[pos0-w];
			n[pos0-w] = panel[pos0];
			
			if(m.find(n) == m.end()) {
				if(DEBUG) cout <<"(U)panel_n=" <<n <<endl;
				m[n] = step + 'U';
				q.push(n);
			}
		}
		
		// D
		if(pos0 / w != h - 1) {
			string n = panel;
			n[pos0] = panel[pos0+w];
			n[pos0+w] = panel[pos0];
			
			if(m.find(n) == m.end()) {
				if(DEBUG) cout <<"(D)panel_n=" <<n <<endl;
				m[n] = step + 'D';
				q.push(n);
			}
		}
	}
}

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
		
		//cout <<w <<" " <<h <<" " <<b <<endl;
		
		VS r;
		bfs(w, h, b, &r);
		
		FORI(i, SZ(r)) {
			int L = 0; int R = 0;
			int U = 0; int D = 0;
			FORI(j, SZ(r[i])) {
				if(r[i][j] == 'L') L++;
				if(r[i][j] == 'R') R++;
				if(r[i][j] == 'U') U++;
				if(r[i][j] == 'D') D++;
			}
			cout <<t <<" " <<L <<" " <<R <<" "
				<<U <<" " <<D <<" " <<r[i] <<endl;
		}
		
		//int ret = 0;
		//cout <<"Case #" <<t <<": " <<ret <<endl;
		//printf("Case #%d: %.0lf\n", t, ret);
	}
	
	return 0;
}
