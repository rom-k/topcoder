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
#define PI M_PI
#define EPS 1e-13

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

#define NVR 9999

struct point {
	int r;
	int c;
	int num; //0 for $
	
	point(int r0, int c0, int num0) {
		r=r0; c=c0; num=num0;
	}
};

int min_path_len (vector<point> p, vector<vector<int> > len, vector<int> path, int path_len) {
	list<int> rest;
	FORI(i, p.size()) rest.PB(i);
	FORI(i, path.size()) rest.remove(path[i]);
	
	DBG2("path_len",path_len);
	
	int min_len = NVR;
	if (rest.size() > 0) {
		
		path.PB(0);
		
		FORE(it, rest, list<int>) {
			int new_path_len = len[path[path.size()-2]][*it] + path_len;
			
			if(new_path_len <= p[*it].num) {
				path[path.size()-1] = *it;
				min_len = min(min_len, min_path_len(p, len, path, new_path_len));
			}
		}
		
		path.pop_back();
	}
	else {
		min_len = path_len;
//		min_len = 0;
//		for(int i = path.size()-2; i >= 0; i--) {
//			int from = path[i];
//			int to   = path[i+1];
//			
//			min_len += len[from][to];
//			if(p[from].num <= min_len and p[from].num != 0) {
//				if(DEBUG) cout <<"DEBUG::: ";
//				if(DEBUG) FORI(i, path.size()) cout <<path[i] <<",";
//				if(DEBUG) cout <<" => cannot";
//				if(DEBUG) cout <<endl;
//				return NVR;
//			}
//		}
		
		if(DEBUG) cout <<"DEBUG::: ";
		if(DEBUG) FORI(i, path.size()) cout <<path[i] <<",";
		if(DEBUG) cout <<" => " <<min_len;
		if(DEBUG) cout <<endl;
	}
	
	return min_len;
};

class SlimeXResidentSlime {
public:
	int exterminate(vector <string> f) {
		int R = f.size();
		int C = f[0].size();
		
		vector<point> p;
		FORI(r, R) {
			FORI(c, C) {
				if     (f[r][c] == '$') p.PB(point(r, c, 0));
				else if(f[r][c] == '1') p.PB(point(r, c, 1));
				else if(f[r][c] == '2') p.PB(point(r, c, 2));
				else if(f[r][c] == '3') p.PB(point(r, c, 3));
				else if(f[r][c] == '4') p.PB(point(r, c, 4));
				else if(f[r][c] == '5') p.PB(point(r, c, 5));
				else if(f[r][c] == '6') p.PB(point(r, c, 6));
				else if(f[r][c] == '7') p.PB(point(r, c, 7));
				else if(f[r][c] == '8') p.PB(point(r, c, 8));
				else if(f[r][c] == '9') p.PB(point(r, c, 9));
			}
			DBG(f[r]);
		}
		
		int P = p.size();
		
		// get path length from i to j in P
		vector<vector<int> > len(P, vector<int>(P, 0));
		
		FORI(i, P) {
			//DBG2("i",i);
			point pi = p[i];
			
			// create path length map from point i
			vector<vector<int> > pathmap(R, vector<int>(C, NVR));
			
			// initialize queue
			queue<pair<int, int> > qu;
			qu.push(pair<int, int>(pi.r, pi.c));
			
			// create path length map using queue
			while(qu.size() != 0) {
				pair<int, int> p = qu.front();
				qu.pop();
				
				int r, c;
				r = p.first;
				c = p.second;
				//DBG2("r",r);
				//DBG2("c",c);
				
				if(pathmap[r][c] != NVR) continue;
				
				// get minimum path length from around the point
				int min_path = NVR;
				if(0   < r) min_path = min(min_path, pathmap[r-1][c]);
				if(r < R-1) min_path = min(min_path, pathmap[r+1][c]);
				if(0   < c) min_path = min(min_path, pathmap[r][c-1]);
				if(c < C-1) min_path = min(min_path, pathmap[r][c+1]);
				
				// for initial point
				if(min_path == NVR) min_path = -1;
				
				// set path length
				pathmap[r][c] = min_path + 1;
				//DBG2("pathmap[r][c]",pathmap[r][c]);
				
				// push to queue
				if(0   < r and pathmap[r-1][c] == NVR and f[r-1][c] != '#') qu.push(pair<int, int>(r-1, c));
				if(r < R-1 and pathmap[r+1][c] == NVR and f[r+1][c] != '#') qu.push(pair<int, int>(r+1, c));
				if(0   < c and pathmap[r][c-1] == NVR and f[r][c-1] != '#') qu.push(pair<int, int>(r, c-1));
				if(c < C-1 and pathmap[r][c+1] == NVR and f[r][c+1] != '#') qu.push(pair<int, int>(r, c+1));
			}
			
			// set path length from i to j in P
			FORIS(j, i+1, P) {
				point pj = p[j];
				len[i][j] = pathmap[pj.r][pj.c];
				len[j][i] = pathmap[pj.r][pj.c];
				
				if(DEBUG) cout <<"DEBUG::: (" <<pi.r <<"," <<pi.c <<")-(" <<pj.r <<"," <<pj.c <<") = " <<len[j][i] <<endl;
			}
		}
		
		vector<int> path(1);
		int ret = NVR;
		FORI(i, P) {
			if(p[i].num == 0) continue;
			path[0] = i;
			ret = min(ret, min_path_len(p, len, path, 0));
		}
		
		if(ret == NVR) ret = -1;
		
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 39)) test_case_39(); if ((Case == -1) || (Case == 25)) test_case_25(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"#1$",
	                                      ".2."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, exterminate(Arg0)); }
	void test_case_1() { string Arr0[] = {"$",
	                                      "1",
	                                      "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, exterminate(Arg0)); }
	void test_case_2() { string Arr0[] = {"$124"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, exterminate(Arg0)); }
	void test_case_3() { string Arr0[] = {"$.#2",
	                                      "#..1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, exterminate(Arg0)); }
	void test_case_25() { string Arr0[] = {"..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "...........................898....................", "..........................19$7....................", "...........................987....................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", "..................................................", ".................................................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(25, Arg1, exterminate(Arg0)); }
	void test_case_39() { string Arr0[] = {"$.................................................", "#################################################.", "..................................................", ".#################################################", "..................................................", "#################################################.", "..................................................", ".#################################################", "..................................................", "#################################################.", "..................................................", ".#################################################", "..................................................", "#################################################.", "..................................................", ".#################################################", "..................................................", "#################################################.", "..................................................", ".#################################################", "..................................................", "#################################################.", "..................................................", ".#################################################", "..................................................", "#################################################.", "..................................................", ".#################################################", "..................................................", "#################################################.", "..................................................", ".#################################################", "..................................................", "#################################################.", "..................................................", ".#################################################", "..................................................", "#################################################.", "..................................................", ".#################################################", "..................................................", "#################################################.", "..................................................", ".#################################################", "..................................................", "#################################################.", "..................................................", ".#################################################", ".#...#...#...#...#...#...#...#...#...#...#...#...#", "...#...#...#...#...#...#...#...#...#...#...#...#.9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1298; verify_case(39, Arg1, exterminate(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SlimeXResidentSlime ___test;
	___test.run_test(-1);
}
// END CUT HERE
