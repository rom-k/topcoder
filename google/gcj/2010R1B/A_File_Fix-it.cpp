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

struct dir {
	string name;
	vector<dir*> c;
	
	dir () {
		dir("");
	}
	dir (string name0) {
		name = name0;
	}
	
//	~dir () {
//		FORI(i, c.size()) {
//			c[i]->~dir();
//			delete c[i];
//		}
//	}
	
	void add (string path) {
		string path_dir    = path;
		string path_remain = "";
		
		// sprit with the first "/"
		if(path.find("/") != string::npos) {
			path_dir    = path.substr(0, path.find("/"));
			path_remain = path.substr(path.find("/")+1);
		}
		
		DBG2("path_dir",path_dir);
		DBG2("path_remain",path_remain);
		
		// find path from existing children dir
		int i2 = -1;
		FORI(i, c.size()) {
			if(c[i]->name == path_dir) {
				i2 = i;
			}
		}
		
		// create new dir if not exist
		if (i2 < 0) {
			DBG(" -> create new dir.");
			dir* c1 = new dir(path_dir);
			c.PB(c1);
			i2 = c.size()-1;
		}
		
		// do it recursive
		if(path_remain != "") {
			DBG(" -> next.");
			c[i2]->add(path_remain);
		}
	}
	
	int count () {
		int num = 1;
		FORI(i, c.size()) num += c[i]->count();
		return num;
	}
};

int main() {
	int T;
	cin >>T;
	cin.ignore();
	
	for(int t=1; t<=T; t++) {
		int N, M;
		cin >>N >>M;
		
		dir root;
		
		FORI(i, N) {
			string a; cin >>a;
			root.add(a.substr(1));
		}
		int num_N = root.count();
		
		FORI(i, M) {
			string a; cin >>a;
			root.add(a.substr(1));
		}
		int num_M = root.count();
		
		cout <<"Case #" <<t <<": " <<num_M - num_N <<endl;
	}
	
	return 0;
}
