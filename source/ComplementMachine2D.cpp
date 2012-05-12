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
#define SZ(a) int((a).size())
#define PI M_PI
#define EPS 1e-13

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;


#define INV(a) a = (a == '0') ? '1' : '0';
#define NUM(a) if(a == '0') ? 0 : 1;

class ComplementMachine2D {
public:
	int largestSubmatrix(vector <string> m) {
		int N = SZ(m);
		int M = SZ(m[0]);
		
		//2-dimensional vector filled with 0
		vector<vector<int> > dot(M, vector<int>(N, 0));
		
		FORI(i, N-1)
			FORI(j, M-1) {
				int num = 0;
				if(m[i][j] == '1') num++;
				if(m[i][j+1] == '1') num++;
				if(m[i+1][j] == '1') num++;
				if(m[i+1][j+1] == '1') num++;
				if(num % 2 != 0 ) dot[i][j] = 1;
			}
		
//		vector<vector<pair<int, int> > > rc(M, vector<pair<int, int> >(N));
		
		FORI(i, N-1)
			FORI(j, M-1)
				if(dot[i][j] == 1) {
					vector<pair<int, int> > r;
					vector<pair<int, int> > l;
					vector<pair<int, int> > u;
					vector<pair<int, int> > d;
					
//					pair<int, int> l = pair<int, int>(i, 0);
//					pair<int, int> r = pair<int, int>(i+1, 0);
					pair<int, int> r = pair<int, int>(i+1, j);
					FORI(p, M) {
						
					}
					
//					u.PB(pair<int, int>(j, 0));
//					d.PB(pair<int, int>(j+1, 0));
				}
		
		int ret;
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0011",
 "0011",
 "1100",
 "0111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(0, Arg1, largestSubmatrix(Arg0)); }
	void test_case_1() { string Arr0[] = {"0011",
 "1011",
 "0101",
 "1010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, largestSubmatrix(Arg0)); }
	void test_case_2() { string Arr0[] = {"1011",
 "0011",
 "0101",
 "1010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, largestSubmatrix(Arg0)); }
	void test_case_3() { string Arr0[] = {"0000110101010",
 "0111101010111",
 "1110110111011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, largestSubmatrix(Arg0)); }
	void test_case_4() { string Arr0[] = {"11000000000110101101",
 "00111111011101101101",
 "00110011110111100010",
 "10011110111110000111",
 "00111010000000110111",
 "00001101011011010110",
 "11010010100100101100",
 "11101101011011000001",
 "11000010100100111001",
 "11011010100100101010",
 "10110010100100110110",
 "01100010100100111001",
 "10110010100100110011",
 "01110101011011001010",
 "01111101011011001011",
 "00001000010010101011",
 "11100101100100110001",
 "10100100111001010101",
 "11111000001010011110",
 "01110100001110011111"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; verify_case(4, Arg1, largestSubmatrix(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ComplementMachine2D ___test;
	___test.run_test(-1);
}
// END CUT HERE
