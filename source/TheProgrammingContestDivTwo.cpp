#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-5;
//typedef long long ll;

class TheProgrammingContestDivTwo {
public:
	vector <int> find(int T, vector <int> requiredTime) {
		
		sort(requiredTime.begin(), requiredTime.end());
		
		int N = requiredTime.size();
		
		//2-dimensional vector filled with 0
		vector<vector<int> > k(T+1, vector<int>(N+1, 0));
		
		//Knapsack
		for (int i=0; i<N; i++) {
			for (int t=0; t<=T; t++) {
				k[t][i+1] = max(k[t][i+1], k[t][i]  );
				if (t + requiredTime[i] <= T) {
					k[t+requiredTime[i]][i+1] = max(k[t+requiredTime[i]][i+1], k[t][i]+1);
				}
			}
		}
		
		int time=0;
		int sum=0;
		for (int t=0; t<T+1; t++) {
			if (sum < k[t][N]) {
				sum = k[t][N];
				time = t;
			}
		}
		vector<int> use;
		for (int i=N-1; i>=0; i--) {
			if (k[time][i+1] != k[time][i]) {
				time -= requiredTime[i];
				use.push_back(requiredTime[i]);
			}
		}
		
		sort(use.begin(), use.end());
		
		int loss=0;
		time=0;
		for (int u=0; u<use.size(); u++) {
			time += use[u];
			loss += time;
		}
		
		vector <int> result;
		result.push_back(sum);
		result.push_back(loss);
		return result;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 43)) test_case_43(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 74; int Arr1[] = {47}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 47 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 74; int Arr1[] = {4747}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 47; int Arr1[] = {8, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 18 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arr1[] = {12, 3, 21, 6, 4, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 86 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, find(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 58; int Arr1[] = {4, 5, 82, 3, 4, 65, 7, 6, 8, 7, 6, 4, 8, 7, 6, 37, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 249 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, find(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100000; int Arr1[] = {100000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 100000 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, find(Arg0, Arg1)); }
	void test_case_43() { int Arg0 = 10; int Arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 20}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(43, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheProgrammingContestDivTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
