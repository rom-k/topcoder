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

class FoxPlayingGame {
public:
	double theMax(int nA, int nB, int paramA, int paramB) {
		double scoreA  = (double)paramA / 1000.0;
		double scoreB  = (double)paramB / 1000.0;
		double *score     = new double[nB+1];
		double *score_min = new double[nB+1];
		
		for(int a=1; a<=nA; a++) {
			score[0] = score[0] + scoreA;
			score_min[0] = score[0];
			for(int b=1; b<=nB; b++) {
				double tmp1 = score[b]     + scoreA;
				double tmp2 = score_min[b] + scoreA;
				double tmp3 = score[b-1]     * scoreB;
				double tmp4 = score_min[b-1] * scoreB;
				
				score[b]     = tmp1;
				score_min[b] = tmp1;
				if (tmp2 > score[b]    ) {score[b]     = tmp2;}
				if (tmp2 < score_min[b]) {score_min[b] = tmp2;}
				if (tmp3 > score[b]    ) {score[b]     = tmp3;}
				if (tmp3 < score_min[b]) {score_min[b] = tmp3;}
				if (tmp4 > score[b]    ) {score[b]     = tmp4;}
				if (tmp4 < score_min[b]) {score_min[b] = tmp4;}
			}
		}
		
		return score[nB];
	}

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 4; int Arg2 = 3000; int Arg3 = 2000; double Arg4 = 240.0; verify_case(0, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2000; int Arg3 = 100; double Arg4 = 6.0; verify_case(1, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = -2000; int Arg3 = 2000; double Arg4 = -8.0; verify_case(2, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 2000; int Arg3 = -2000; double Arg4 = 160.0; verify_case(3, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 50; int Arg2 = 10000; int Arg3 = 2000; double Arg4 = 5.62949953421312E17; verify_case(4, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 41; int Arg1 = 34; int Arg2 = 9876; int Arg3 = -1234; double Arg4 = 515323.9982341775; verify_case(5, Arg4, theMax(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  FoxPlayingGame ___test;
  ___test.run_test(-1);
}
// END CUT HERE
