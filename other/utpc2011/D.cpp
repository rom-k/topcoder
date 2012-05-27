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

int R, C;
vector<string> m(25, "");

struct state {
	int x;
	int y;
	int dir; //0=right, 1=left, 2=down, 3=up
	int mem;
	
	state () {
		x=0; y=0; dir=0; mem=0;
	}
	
	state (int x0, int y0, int dir0, int mem0) {
 		x=x0; y=y0; dir=dir0; mem=mem0;
	}
	
	char get_char () {
		return m[y][x];
	}
	
	void continu () {
		doit();
		go();
		int count = 0;
		while(get_char() != '?' and get_char() != '@' and count <= 10000) {
			doit();
			go();
			count++;
		}
	}
	
	void go () {
		if(dir==0) { x++; if(x > C-1) x=0; if(DEBUG) cout <<"go right" <<endl; }
		if(dir==1) { x--; if(x < 0) x=C-1; if(DEBUG) cout <<"go left" <<endl; }
		if(dir==2) { y++; if(y > R-1) y=0; if(DEBUG) cout <<"go down" <<endl; }
		if(dir==3) { y--; if(y < 0) y=R-1; if(DEBUG) cout <<"go up" <<endl; }
	}
	
	void doit () {
		if(DEBUG) cout <<"found '" <<m[y][x] <<"'" <<endl;
		if     (m[y][x] == '<') {dir=1;} // 実行の向きを左にする．
		else if(m[y][x] == '>') {dir=0;} // 実行の向きを右にする．
		else if(m[y][x] == '^') {dir=3;} // 実行の向きを上にする．
		else if(m[y][x] == 'v') {dir=2;} // 実行の向きを下にする．
		else if(m[y][x] == '_') {lr();} // メモリの値が 0 ならば実行の向きを右に，そうでなければ左にする．
		else if(m[y][x] == '|') {ud();} // メモリの値が 0 ならば実行の向きを下に，そうでなければ上にする．
		else if(m[y][x] == '?') {/*rand*/} // 実行の向きが上下左右のいずれかにランダムに等確率で変更される．
		else if(m[y][x] == '.') {} // 何もしない．
		else if(m[y][x] == '@') {/*stop*/} // プログラムの実行を停止する．
		else if(m[y][x] == '0') {mem=0;} // メモリの値を指定の数値にする．
		else if(m[y][x] == '1') {mem=1;} // メモリの値を指定の数値にする．
		else if(m[y][x] == '2') {mem=2;} // メモリの値を指定の数値にする．
		else if(m[y][x] == '3') {mem=3;} // メモリの値を指定の数値にする．
		else if(m[y][x] == '4') {mem=4;} // メモリの値を指定の数値にする．
		else if(m[y][x] == '5') {mem=5;} // メモリの値を指定の数値にする．
		else if(m[y][x] == '6') {mem=6;} // メモリの値を指定の数値にする．
		else if(m[y][x] == '7') {mem=7;} // メモリの値を指定の数値にする．
		else if(m[y][x] == '8') {mem=8;} // メモリの値を指定の数値にする．
		else if(m[y][x] == '9') {mem=9;} // メモリの値を指定の数値にする．
		else if(m[y][x] == '+') {add();} // メモリの値に 1 を加える，ただし値が 15 だった場合 0 にする．
		else if(m[y][x] == '-') {sub();} // メモリの値から 1 を引く，ただし値が 0 だった場合 15 にする．
	}
	
	void add () { mem++; if(mem > 15) mem=0; }
	void sub () { mem--; if(mem < 0) mem=15; }
	void lr ()  { dir = mem==0 ? 0 : 1; }
	void ud ()  { dir = mem==0 ? 2 : 3; }
};

int main() {
	cin >>R >>C;
	
	FORI(i, R) {
		cin >>m[i];
		if(DEBUG) cout <<"# " <<m[i] <<endl;
	}
	
	stack<state> st;
	map<LL, int> m;
	
	state a;
	st.push(a);
	
	while(! st.empty()) {
		state b = st.top();
		st.pop();
		if(DEBUG) cout <<"start from (" <<b.x <<"," <<b.y <<") " <<b.dir <<" " <<b.mem <<endl;
		
		b.continu();
		if(b.get_char() == '?') {
			FORI(i, 4) {
				b.dir = i;
				LL tmp = b.x*100000 + b.y*1000 + b.dir*100 + b.mem;
				if(m.find(tmp) == m.end()) {
					m.insert( map<LL, int>::value_type(tmp, 1) );
					st.push(b);
				}
			}
		}
		else if(b.get_char() == '@') {
			cout <<"YES" <<endl;
			return 0;
		}
		else {
			//seems inf-loop
		}
	}
	
	cout <<"NO" <<endl;
	return 0;
}
