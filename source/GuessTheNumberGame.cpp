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

#define MOD 1000000007

int _is_prime1(int n) {
	if (n     <= 1) return false;
	if (n     == 2) return true;
	if (n % 2 == 0) return false;
	
	int m = (int) sqrt(n);
	for (int i=3; i<=m; i+=2) 
		if (n%i == 0) return false;
	
	return true;
}

void _is_prime2(vector<bool>& sieve) {
	int n = sieve.size() - 1;
	for (int i=0; i<n+1; i++)
		sieve[i] = true;
	
	sieve[0] = false;
	sieve[1] = false;
	
	int m = (int) sqrt(n);
	for (int i=2; i<=m; i++)
		if (sieve[i])
			for (int k=i*i; k<=n; k+=i)
				sieve[k] = false;
	
	return;
}

class GuessTheNumberGame {
public:
	int possibleClues(int n) {
		vector<bool> sieve(1000005);
		_is_prime2(sieve);
		
		LL ret = 1;
		for(int i = 2; i <= n; i++) {
			if(sieve[i]) {
				//LL logi_n = (LL)(log(n) / log(i));
				LL logi_n = 0; LL tmp = n;
				while(tmp >= i) { tmp /= i; logi_n++; }
				
				ret *= (logi_n + 1);
				ret %= MOD;
			}
		}
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 9)) test_case_9(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 12; verify_case(0, Arg1, possibleClues(Arg0)); }
	void test_case_1() { int Arg0 = 16; int Arg1 = 240; verify_case(1, Arg1, possibleClues(Arg0)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; verify_case(2, Arg1, possibleClues(Arg0)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 677298706; verify_case(3, Arg1, possibleClues(Arg0)); }
	void test_case_9() { int Arg0 = 8; int Arg1 = 32; verify_case(9, Arg1, possibleClues(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GuessTheNumberGame ___test;
	___test.run_test(9);
}
// END CUT HERE
