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

struct cPos {
	double x;
	double y;
	bool flag;
	
	inline double dist2 (struct cPos a) {
		DBG2("     x",x);
		DBG2("     a.x",a.x);
		DBG2("     y",y);
		DBG2("     a.y",a.y);
		DBG2("     pow(x - a.x, 2) + pow(y - a.y, 2)",pow(x - a.x, 2) + pow(y - a.y, 2));
		return pow(x - a.x, 2) + pow(y - a.y, 2);
	}
};

class KingdomXCitiesandVillagesAnother {
public:
	double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY) {
		
		int N;
		vector<cPos> pos(cityX.size() + villageX.size());
		
		FORI(i, cityX.size()) {
			pos[i].x = (double)cityX[i];
			pos[i].y = (double)cityY[i];
			pos[i].flag = true;
		}
		N = cityX.size();
		
		FORI(i, villageX.size()) {
			pos[i + N].x = (double)villageX[i];
			pos[i + N].y = (double)villageY[i];
		}
		N += villageX.size();
		
		double result = 0.;
		
		FORI(i, N) {
			if (pos[i].flag) continue;
			DBG2("i",i);
			
			VD dist2(N, -1.);
			
			int index_new = i;
			while(1) {
				int j_nearest = -1;
				double d2_nearest = -1.;
				
				FORI(j, N) {
					double d2 = pos[index_new].dist2(pos[j]);
					if (dist2[j] < 0. or d2 < dist2[j]) {
						dist2[j] = d2;
					}
					if (d2_nearest < 0. or dist2[j] < d2_nearest and dist2[j] != 0.) {
						d2_nearest = dist2[j];
						j_nearest = j;
						DBG2("  j",j);
						DBG2("  dist2[j]",dist2[j]);
						DBG2("  d2_nearest",d2_nearest);
					}
				}
				DBG2(" index_new",index_new);
				DBG2(" j_nearest",j_nearest);
				DBG2(" d2_nearest",d2_nearest);
				
				if (pos[j_nearest].flag) {
					result += sqrt(d2_nearest);
					break;
				}
				else {
					result += sqrt(d2_nearest);
					pos[j_nearest].flag = true;
					index_new = j_nearest;
				}
			}
			
			pos[i].flag = true;
		}
		return result;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.0; verify_case(0, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2,2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.0; verify_case(1, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 2.8284271247461903; verify_case(2, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_8() { int Arr0[] = {299590}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {877251}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {481343, 726215, 152216, 471768}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1957, 659416, 729639, 83045}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 1399296.0268321058; verify_case(2, Arg4, determineLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	KingdomXCitiesandVillagesAnother ___test;
	___test.run_test(-1);
}
// END CUT HERE
