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

int main() {
	int C;
	cin >>C;
	cin.ignore();
	
	for(int c=1; c<=C; c++) {
		int N;
		cin >>N;
		
		vector<int> p(2, 1);
		vector<int> t(2, 0);
		int sum_time = 0;
		FORI(i, N) {
			char robot;
			int pos;
			cin >>robot >>pos;
			int r = (robot == 'B') ? 1 : 0;
			
			//move
			int can_move = sum_time - t[r];
			if(pos < p[r] - can_move) {
				sum_time += p[r] - can_move - pos;
			}
			else if(p[r] + can_move < pos) {
				sum_time += pos - p[r] - can_move;
			}
			p[r] = pos;
			
			//push
			sum_time++;
			t[r] = sum_time;
		}
		
		cout <<"Case #" <<c <<": " <<sum_time <<endl;
	}
	
	return 0;
}
