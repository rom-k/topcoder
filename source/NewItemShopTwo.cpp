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
#define IPOW(a,b) ((long long) pow((double)(a),(double)(b)))
#define PI M_PI
#define EPS 1e-13
#define INF 0x7f7f7f7f

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

class NewItemShopTwo {
public:
	double getMaximum(vector <string> customers) {
		int w[24];
		double c[24];
		double p[24];
		
		FORI(i, 24) w[i]=0;
		
		// split /\s+/
		//  stringstream ss;
		//  string s;
		//  ss <<strHOGE;
		//  while (ss >> s) { ... }
		
		stringstream ss;
		string s;
		FORI(i, 2) {
			double yet = 1.0;
			
			ss.str(""); ss.clear(stringstream::goodbit);
			ss <<customers[i];
			while (ss >> s) {
				int c1 = s.find(",");
				int c2 = s.find(",", c1+1);
				
				// atoi
				//  stringstream ss;
				//  ss <<strHOGE;
				//  ss >>intHOGE;
				//  
				//  //clear
				//  ss.str("");
				//  ss.clear(stringstream::goodbit);
				
				stringstream ss2;
				int t;
				double p2;
				
				ss2 <<s.substr(   0,    c1); ss2 >>t;
				w[t] = i+1;
				ss2.str(""); ss2.clear(stringstream::goodbit);
				ss2 <<s.substr(c1+1, c2-c1); ss2 >>c[t];
				ss2.str(""); ss2.clear(stringstream::goodbit);
				ss2 <<s.substr(c2+1       ); ss2 >>p2;
				p2 /= 100.;
				p[t] = p2 / yet;
				yet -= p2;
				
				if(DEBUG) cout <<"DEBUG::: " <<s <<"\t" <<w[t] <<"\t" <<t <<"\t" <<c[t] <<"\t" <<p[t] <<endl;
			}
		}
		
		//dp[time][flag]
		// customer1 has already came if flag%2>0
		// customer2 has already came if flag>1
		
		double dp[25][4];
		FORI(i, 25) FORI(j, 4) dp[i][j]=0.;
		
		for(int t=23; t>=0; t--) {
			DBG2("t",t);
			FORI(f, 4) {
				DBG2(" f",f);
				if (w[t] == 0) {
					// no customer
					dp[t][f] = dp[t+1][f];
					DBG2(" A:",dp[t][f]);
				}
				else if (w[t] == 1 and f%2>0
				     or  w[t] == 2 and f>1) {
					// customer does not come (already came today)
					dp[t][f] = dp[t+1][f];
					DBG2(" B:",dp[t][f]);
				}
				else {
					// customer may come !
					dp[t][f] =      p[t]  * max(dp[t+1][f+w[t]], c[t])
					         + (1 - p[t]) *     dp[t+1][f     ];
					DBG2(" C:",dp[t][f]);
				}
			}
		}
		
		return dp[0][0];
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = { "8,1,80 16,100,11", "12,10,100" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 19.0; verify_case(0, Arg1, getMaximum(Arg0)); }
	void test_case_1() { string Arr0[] = { "8,1,80 16,100,11", "12,10,90 13,30,5" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 19.4; verify_case(1, Arg1, getMaximum(Arg0)); }
	void test_case_2() { string Arr0[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,80" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 90.0; verify_case(2, Arg1, getMaximum(Arg0)); }
	void test_case_3() { string Arr0[] = { "0,90,25 2,90,25 4,90,25 6,90,25", "7,100,95" }; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 95.0; verify_case(3, Arg1, getMaximum(Arg0)); }
	void test_case_4() { string Arr0[] = { "0,3,1 2,4,1 4,5,9 6,2,6 8,5,3 10,5,8 12,9,7 14,9,3", 
  "1,2,3 3,8,4 5,6,2 7,6,4 9,3,3 11,8,3 13,2,7 15,9,5" }
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 3.0692999999999997; verify_case(4, Arg1, getMaximum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	NewItemShopTwo ___test;
	___test.run_test(-1);
}
// END CUT HERE
