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

#define MOD 1000000007

class AlgridTwo {
public:
	int makeProgram(vector <string> output) {
		int H = output.size();
		int W = output[0].size();
		bool repeating;
		
//		int num = 0;
		LL ret = 1;
		FORI(i, H-1) {
			repeating = false;
			FORI(j, W-1) {
				if (output[i].at(j) == 'W' and output[i].at(j+1) == 'W') {
					repeating = false;
				}
				else if (output[i].at(j) == 'B' and output[i].at(j+1) == 'W') {
//					num++;
//					if (! repeating) num++;
					ret *= 2; ret %= MOD;
					if (! repeating) { ret *= 2; ret %= MOD; }
					repeating = true;
					if (output[i+1].at(j) != 'B') return 0;
					if (j+2 <= W-1
					and output[i].at(j+2) == 'W'
					and output[i+1].at(j+1) != 'B') return 0;
				}
				else if (output[i].at(j) == 'W' and output[i].at(j+1) == 'B') {
//					num++;
//					if (! repeating) num++;
					ret *= 2; ret %= MOD;
					if (! repeating) { ret *= 2; ret %= MOD; }
					repeating = true;
					if (output[i+1].at(j) != 'W') return 0;
				}
				else {
//					repeating = false;
				}
			}
			
			if (output[i].at(W-2) == 'B' and output[i].at(W-1) == 'W') {
				if (output[i+1].at(W-1) != 'B') return 0;
			}
			else if (output[i].at(W-2) == 'W' and output[i].at(W-1) == 'B') {
				if (output[i+1].at(W-1) != 'W') return 0;
			}
		}
		
//		DBG2("num",num);
//		return (int) fmod((double) powf(2., num), MOD);
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 134)) test_case_134(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"BB",
                                          "WB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, makeProgram(Arg0)); }
	void test_case_1() { string Arr0[] = {"BBWBBB",
                                          "WBWBBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, makeProgram(Arg0)); }
	void test_case_2() { string Arr0[] = {"BWBWBW",
                                          "WWWWWW",
                                          "WBBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, makeProgram(Arg0)); }
	void test_case_3() { string Arr0[] = {"WWBWBWBWBWBWBWBW",
                                          "BWBWBWBWBWBWBWBB",
                                          "BWBWBWBWBWBWBWBW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 73741817; verify_case(3, Arg1, makeProgram(Arg0)); }
	void test_case_5() { string Arr0[] = {"WBWWBBBWBWBWBWWBBBWWBWBBWBWBBWWWWWBBWWBWWBBWBBWBBW",
                                          "WBBWBWBWBWBWBBWBBBBWBWWBWBWBBBBBBWWBBWBBWBBWWBWBBB",
                                          "WBBWBWBWBWBWWBWWBWBWBBWBWBWWWWBBBBWBBWBBWBBBWBWWWW",
                                          "WWBWBWBWBWBBWBBWBWBWBBWBWBBWBWBBWBWWBWBBWBBBWBBWBB",
                                          "BWBWBWBWBWWBWWBWBWBWBBWBWBBWBWBBWBBWBWBBWBWBWBBWWW",
                                          "BWBWBWBWBBWBBWBWBWBWWBWBWWBWBWWBWWBWBWBBWBWBWBBBWB",
                                          "BWBWBWBWWBWWBWBWBWBBWBWBBWBWBBWBBWBWBWWBWBWBWWWBWW",
                                          "BWBWBWBBWBBWBWBWBWBBWBWBBWBWWBWBBWBWBBWBWBWBBWWBBW",
                                          "BWBWBWBBWWBWBWBWBWWBWBWWBWBBWBWBBWBWWBWBWBWWBBWWBB",
                                          "BWBWBWBBBWBWBWBWBBWBWBBWBWWBWBWBBWBBWBWBWBBWWBBWBW",
                                          "BWBWBWBWBWBWBWBWBBWBWWBWBBWBWBWBBWWBWBWBWBBBWWBWBB",
                                          "BWBWBWBWBWBWBWBWWBWBBWBWWBWBWBWWBBWBWBWBWWWBBWBWBW",
                                          "BWBWBWBWBWBWBWBBWBWWBWBBWBWBWBBWWBWBWBWBBWWBBWBWBB",
                                          "BWBWBWBWBWBWBWBBWBBWBWBBWBWBWWBBWBWBWBWBBBWBBWBWBW",
                                          "BWBWBWBWBWBWBWBBWBBWBWWBWBWBBWWBWBWBWBWBWBWBBWBWBB",
                                          "BWBWBWBWBWBWBWWBWWBWBBWBWBWWBBWBWBWBWBWBWBWWBWBWBW",
                                          "BWBWBWBWBWBWBBWBBWBWWBWBWBBWWBWBWBWBWBWBWBBWBWBWBB",
                                          "BWBWBWBWBWBWWBWBBWBBWBWBWWBBWBWBWBWBWBWBWBBWBWBWWW",
                                          "BWBWBWBWBWBBWBWWBWWBWBWBBWBBWBWBWBWBWBWBWWBWBWBBWW",
                                          "BWBWBWBWBWWBWBBWBBWBWBWWBWWBWBWBWBWBWBWBBWBWBWWBBW",
                                          "BWBWBWBWBBWBWBBWBBWBWBBWBBWBWBWBWBWBWBWBBWBWBBWWBB",
                                          "BWBWBWBWWBWBWBBWWBWBWBBWWBWBWBWBWBWBWBWWBWBWBBBWWW",
                                          "BWBWBWBBWBWBWWBBWBWBWBBBWBWBWBWBWBWBWBBWBWBWWBBBWB",
                                          "BWBWBWBBWBWBBWWBWBWBWBWBWBWBWBWBWBWBWWBWBWBBWBWBWW",
                                          "BWBWBWBBWBWWBBWBWBWBWBWBWBWBWBWBWBWBBWBWBWBBWBWBBB",
                                          "BWBWBWWBWBBWWBWBWBWBWBWBWBWBWBWBWBWWBWBWBWBBWBWBBW",
                                          "BWBWBBWBWBBBWBWBWBWBWBWBWBWBWBWBWBBWBWBWBWWBWBWWBB",
                                          "BWBWBBWBWWBBWBWBWBWBWBWBWBWBWBWBWBBWBWBWBBWBWBBWBW",
                                          "BWBWWBWBBWBBWBWBWBWBWBWBWBWBWBWBWBBWBWBWWBWBWWBWBB",
                                          "BWBBWBWWBWBBWBWBWBWBWBWBWBWBWBWBWWBWBWBBWBWBBWBWWW",
                                          "BWBBWBBWBWWBWBWBWBWBWBWBWBWBWBWBBWBWBWBBWBWWBWBBWB",
                                          "BWWBWBBWBBWBWBWBWBWBWBWBWBWBWBWWBWBWBWBBWBBWBWBBWW",
                                          "BBWBWWBWBBWBWBWBWBWBWBWBWBWBWBBWBWBWBWBBWBBWBWBBBW",
                                          "BBWBBWBWWBWBWBWBWBWBWBWBWBWBWBBWBWBWBWBBWWBWBWBBBB",
                                          "BBWWBWBBWBWBWBWBWBWBWBWBWBWBWBBWBWBWBWWBBWBWBWWBBW",
                                          "WBBWBWBBWBWBWBWBWBWBWBWBWBWBWWBWBWBWBBWWBWBWBBWBBB",
                                          "WWBWBWBBWBWBWBWBWBWBWBWBWBWBBWBWBWBWWBBWBWBWWBWWWW",
                                          "BWBWBWWBWBWBWBWBWBWBWBWBWBWBBWBWBWBBWBBWBWBBWBBBBW",
                                          "BWBWBBWBWBWBWBWBWBWBWBWBWBWWBWBWBWBBWBBWBWWBWWBWBB",
                                          "BWBWBBWBWBWBWBWBWBWBWBWBWBBWBWBWBWWBWBBWBBWBBWBWWW",
                                          "BWBWWBWBWBWBWBWBWBWBWBWBWWBWBWBWBBWBWBBWBBWBBWBBWB",
                                          "BWBBWBWBWBWBWBWBWBWBWBWBBWBWBWBWBBWBWWBWBBWBBWWBWW",
                                          "BWWBWBWBWBWBWBWBWBWBWBWBBWBWBWBWWBWBBWBWBBWWBBWBBB",
                                          "BBWBWBWBWBWBWBWBWBWBWBWBBWBWBWBBWBWBBWBWBBBWWBWBWW",
                                          "BBWBWBWBWBWBWBWBWBWBWBWWBWBWBWWBWBWWBWBWBWBBWBWBBW",
                                          "BBWBWBWBWBWBWBWBWBWBWBBWBWBWBBWBWBBWBWBWBWBBWBWBBB",
                                          "BBWBWBWBWBWBWBWBWBWBWWBWBWBWWBWBWWBWBWBWBWWBWBWWBW",
                                          "BBWBWBWBWBWBWBWBWBWBBWBWBWBBWBWBBWBWBWBWBBWBWBBWBB",
                                          "WBWBWBWBWBWBWBWBWBWWBWBWBWWBWBWWBWBWBWBWBBWBWBBWBW",
                                          "WBWBWBWBWBWBWBWBWBBWBWBWBBWBWBBWBWBWBWBWWBWBWBBWBB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 708234174; verify_case(5, Arg1, makeProgram(Arg0)); }
	void test_case_6() { string Arr0[] = {"WBWB",
                                          "WBWB",
                                          "WBWB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, makeProgram(Arg0)); }
	void test_case_134() { string Arr0[] = {"BWW",
                                            "BWB"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(134, Arg1, makeProgram(Arg0)); }

// 

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AlgridTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
