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
		if     (m[y][x] == '<') {dir=1;} // ���s�̌��������ɂ���D
		else if(m[y][x] == '>') {dir=0;} // ���s�̌������E�ɂ���D
		else if(m[y][x] == '^') {dir=3;} // ���s�̌�������ɂ���D
		else if(m[y][x] == 'v') {dir=2;} // ���s�̌��������ɂ���D
		else if(m[y][x] == '_') {lr();} // �������̒l�� 0 �Ȃ�Ύ��s�̌������E�ɁC�����łȂ���΍��ɂ���D
		else if(m[y][x] == '|') {ud();} // �������̒l�� 0 �Ȃ�Ύ��s�̌��������ɁC�����łȂ���Ώ�ɂ���D
		else if(m[y][x] == '?') {/*rand*/} // ���s�̌������㉺���E�̂����ꂩ�Ƀ����_���ɓ��m���ŕύX�����D
		else if(m[y][x] == '.') {} // �������Ȃ��D
		else if(m[y][x] == '@') {/*stop*/} // �v���O�����̎��s���~����D
		else if(m[y][x] == '0') {mem=0;} // �������̒l���w��̐��l�ɂ���D
		else if(m[y][x] == '1') {mem=1;} // �������̒l���w��̐��l�ɂ���D
		else if(m[y][x] == '2') {mem=2;} // �������̒l���w��̐��l�ɂ���D
		else if(m[y][x] == '3') {mem=3;} // �������̒l���w��̐��l�ɂ���D
		else if(m[y][x] == '4') {mem=4;} // �������̒l���w��̐��l�ɂ���D
		else if(m[y][x] == '5') {mem=5;} // �������̒l���w��̐��l�ɂ���D
		else if(m[y][x] == '6') {mem=6;} // �������̒l���w��̐��l�ɂ���D
		else if(m[y][x] == '7') {mem=7;} // �������̒l���w��̐��l�ɂ���D
		else if(m[y][x] == '8') {mem=8;} // �������̒l���w��̐��l�ɂ���D
		else if(m[y][x] == '9') {mem=9;} // �������̒l���w��̐��l�ɂ���D
		else if(m[y][x] == '+') {add();} // �������̒l�� 1 ��������C�������l�� 15 �������ꍇ 0 �ɂ���D
		else if(m[y][x] == '-') {sub();} // �������̒l���� 1 �������C�������l�� 0 �������ꍇ 15 �ɂ���D
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
