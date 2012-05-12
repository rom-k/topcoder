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

class MathContest {
public:
//	int simOneTime(string stack, bool& inverted) {
	int simOneTime(string stack, bool inverted) {
		int ret = 0;
		int head = 0;
		int tail = stack.size()-1;
		bool reverse = false;
		
//		while(stack != "") {
		while(head <= tail) {
			bool black = false;
			if (!reverse) {
//				if(stack.at(0) == 'B') black = true;
//				stack.erase(0, 1);
				if(stack.at(head) == 'B') black = true;
				head++;
			}
			else {
//				if(stack.at(stack.size()-1) == 'B') black = true;
//				stack.erase(stack.size()-1, 1);
				if(stack.at(tail) == 'B') black = true;
				tail--;
			}
			
			if (black xor inverted) {
				ret++;
				inverted = !inverted;
			}
			else {
				reverse = !reverse;
			}
		}
		return ret;
	}
	
	int countBlack(string ballSequence, int repetitions) {
		
//		bool invert_normal = false;
//		bool invert_invert = true;
//		int num_normal    = simOneTime(stack, invert_normal);
//		int num_inverted  = simOneTime(stack, invert_invert);
//		int ret = 0;
//		
//		if (invert_normal and !invert_invert) {
//			ret += (repetitions / 2 + repetitions % 2) * num_normal;
//			ret += (repetitions / 2) * num_inverted;
//		}
//		else if (invert_normal) {
//			ret += num_normal;
//			ret += (repetitions - 1) * num_inverted;
//		}
//		else {
//			ret += repetitions * num_normal;
//		}
//		return ret;
		
		string stack;
		FORI(i, repetitions) stack += ballSequence;
		
		return simOneTime(stack, false);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BBWWB"; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BBB"; int Arg1 = 10; int Arg2 = 1; verify_case(1, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BW"; int Arg1 = 10; int Arg2 = 20; verify_case(2, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "WWWWWWWBWWWWWWWWWWWWWW"; int Arg1 = 1; int Arg2 = 2; verify_case(3, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "WWWWWWWBBWWBBWBWBBBBWWBBWBBB"; int Arg1 = 3500; int Arg2 = 48998; verify_case(4, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_8() { string Arg0 = "BWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBWBW"; int Arg1 = 2000; int Arg2 = 100000; verify_case(8, Arg2, countBlack(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	MathContest ___test;
	___test.run_test(-1);
}
// END CUT HERE
