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

struct cTask {
	int point;
	int loss;
	int time;
	
	inline bool operator < (const cTask a) const {
		return (double) loss * a.time < (double) a.loss * time;
	}
};

class TheProgrammingContestDivOne {
public:
	int find(int T,
		vector <int> maxPoints,
		vector <int> pointsPerMinute,
		vector <int> requiredTime) {
		
		int N = maxPoints.size();
		
		vector <cTask> tasks(N);
		FORI(i, N) {
			tasks[i].point = maxPoints[i];
			tasks[i].loss = pointsPerMinute[i];
			tasks[i].time = requiredTime[i];
		}
		
		SORT(tasks);
		
		VI dp(T+1, 0);
		FORI(i, N) {
			FORI(t, T+1 - tasks[i].time) {
				double p = dp[t + tasks[i].time] + tasks[i].point - (double) tasks[i].loss * (t + tasks[i].time);
				if (p < 0) p = 0;
				dp[t] = max(dp[t], (int)p);
			}
		}
		
		int result=0;
		FORI(t, T+1) {
			result = max(result, dp[t]);
		}
		
		return result;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 109)) test_case_109(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 74; int Arr1[] = {502}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {47}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 408; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 40000; int Arr1[] = {100000, 100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 100000}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {50000, 30000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 75; int Arr1[] = {250, 500, 1000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 4, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {25, 25, 25}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 1200; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 30; int Arr1[] = {100, 100, 100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 100}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {15, 15, 30}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 97000; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_109() { int Arg0 = 100000; int Arr1[] = {100000, 100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {90000, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1, 90000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 19999; verify_case(109, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheProgrammingContestDivOne ___test;
	___test.run_test(-1);
}
// END CUT HERE
