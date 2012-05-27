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

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

int main() {
	int N;
	cin >>N;
	cin.ignore();
	
	for(int n=1; n<=N; n++) {
		int L, W;
		cin >>L >>W;
		
		DBG2("L",L);
		DBG2("W",W);
		
//		//”Ô•º - sentinel
//		vector<string> F(W+2, "");
//		for(int i=0; i<W; i++) {
//			cin >>F[i+1];
//			F[i+1] = "W"+F[i+1]+"W";
//		}
//		F[0].resize(L+2, 'W');
//		F[W+1].resize(L+2, 'W');
//		//for(int i=0; i<F.size(); i++) cout <<F[i] <<endl;
		
		//2-dimensional vector filled with 0
		vector<vector<int> > F(W, vector<int>(L, 0));
		FORI(i, W) {
			string tmp; cin >>tmp;
			FORI(j, L) {
				char w = tmp[j];
				if(w == 'R' or w == 'W' or w == 'T') { F[i][j] = 0; }
 				else if(i == 0)                      { F[i][j] = 1; }
				else                                 { F[i][j] = F[i-1][j] + 1; }
			}
		}
		if (DEBUG) FORI(i,W) {FORI(j,L) cout <<F[i][j]; cout <<endl;}
		
		int max_area = 0;
		FORI(i, W) {
			stack<int> st_num;
			stack<int> st_height;
			FORI(j, L) {
				if (st_num.empty() or st_height.top() < F[i][j]) {
					st_num.push(j);
					st_height.push(F[i][j]);
					DBG2("i",i);
					DBG2(" j",j);
					DBG2(" F[i][j]",F[i][j]);
					DBG2("  push",j);
				}
				
				if (!st_num.empty() and st_height.top() > F[i][j]) {
					int num;
					int height;
					while (!st_num.empty() and st_height.top() > F[i][j]) {
						num = st_num.top();
						height = st_height.top();
						st_num.pop();
						st_height.pop();
						max_area = max(max_area, height * (j - num));
						DBG2("i",i);
						DBG2(" j",j);
						DBG2(" F[i][j]",F[i][j]);
						DBG2("  pop",num);
						DBG2("  height",height);
						DBG2("  j - num",j - num);
						DBG2("   area",height * (j - num));
					}
					DBG2(" F[i][j]",F[i][j]);
					DBG2("  push",num);
					st_num.push(num);
					st_height.push(F[i][j]);
				}
			}
			while (!st_num.empty()) {
				int num = st_num.top();
				int height = st_height.top();
				st_num.pop();
				st_height.pop();
				max_area = max(max_area, height * (L - num));
			}
		}
		
		cout <<"Case #" <<n <<": " <<max_area <<endl;
	}
	
	return 0;
}
