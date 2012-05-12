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

double sum = 2 - 2 * pow((double) 2 / 3, 495);

class FractalPicture {
public:
	double _getlen(int count, double xs, double ys, double xe, double ye, double x1, double y1, double x2, double y2) {
		double len = 0.;
		
		if (count <= 5)
		{
			double xr = (2 * xe + xs) / 3;
			double yr = (2 * ye + ys) / 3;
			bool xs_in = (x1 <= xs and xs <= x2);
			bool ys_in = (y1 <= ys and ys <= y2);
			bool xr_in = (x1 <= xr and xr <= x2);
			bool yr_in = (y1 <= yr and yr <= y2);
			bool s_in = (xs_in and ys_in);
			bool r_in = (xr_in and yr_in);
			
			if      (s_in and r_in)    len += x2 - x1 + y2 - y1;
			else if (s_in and xs < xr) len += x2 - xs;
			else if (s_in and xs > xr) len += xs - x1;
			else if (s_in and ys < yr) len += y2 - ys;
			else if (s_in and ys > yr) len += ys - y1;
			else if (r_in and xr < xs) len += x2 - xr;
			else if (r_in and xr > xs) len += xr - x1;
			else if (r_in and yr < ys) len += y2 - yr;
			else if (r_in and yr > ys) len += yr - y1;
			else if (xs_in and xr_in and ys < y1 and y2 < yr) len += y2 - y1;
			else if (xs_in and xr_in and yr < y1 and y2 < ys) len += y2 - y1;
			else if (ys_in and yr_in and xs < x1 and x2 < xr) len += x2 - x1;
			else if (ys_in and yr_in and xr < x1 and x2 < xs) len += x2 - x1;
			
			double xv = (ys - ye) / 3;
			double yv = (xe - xs) / 3;
			
			len += _getlen(count + 1, xr, yr, xe, ye, x1, y1, x2, y2);
			len += _getlen(count + 1, xr, yr, xr + xv, yr + yv, x1, y1, x2, y2);
			len += _getlen(count + 1, xr, yr, xr - xv, yr - yv, x1, y1, x2, y2);
		}
		
		else
		{
			bool s_in = (x1 <= xs and xs <= x2 and y1 <= ys and ys <= y2);
			bool e_in = (x1 <= xe and xe <= x2 and y1 <= ye and ye <= y2);
			
			if (s_in and e_in) len += sum;
		}
		
		cout <<"DEBUG::: (" <<xs <<"," <<ys <<") -> (" <<xe <<"," <<ye <<")";
		cout <<" => len=" <<len <<endl;
		
		return len;
	}
	double getLength(int x1, int y1, int x2, int y2) {
		cout <<"DEBUG:::     (" <<x1 <<"," <<y2 <<")-(" <<x2 <<"," <<y2 <<")" <<endl;
		cout <<"DEBUG:::     (" <<x1 <<"," <<y1 <<")-(" <<x2 <<"," <<y1 <<")" <<endl;
		return _getlen(1, 0., 0., 0., 81., (double)x1, (double)y1, (double)x2, (double)y2);
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = -1; int Arg1 = 0; int Arg2 = 1; int Arg3 = 53; double Arg4 = 53.0; verify_case(0, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 10; double Arg4 = 0.0; verify_case(1, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = -10; int Arg1 = 54; int Arg2 = 10; int Arg3 = 55; double Arg4 = 21.0; verify_case(2, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 14; int Arg1 = 45; int Arg2 = 22; int Arg3 = 54; double Arg4 = 2999.0; verify_case(3, Arg4, getLength(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	FractalPicture ___test;
	___test.run_test(-1);
}
// END CUT HERE
