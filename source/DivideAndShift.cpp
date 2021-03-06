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

class DivideAndShift {
public:
	int getLeast(int N, int M) {
		//vector<bool> prime(1000, true);
		vector<bool> prime(1000000, true);
		_is_prime2(prime);
		
		queue<pair<int, int> > qu;
		qu.push(pair<int, int>(N, M));
		
		map<int, int> mp;
		mp[N] = 0;
		
		int ret = 1000001;
		while(!qu.empty()) {
			pair<int, int> test = qu.front();
			qu.pop();
			
			int n = test.first;
			int m = test.second;
			int step = mp[n];
			
			ret = min(ret, step + m - 1);
			ret = min(ret, step + n - m + 1);
			if(_is_prime1(n)) ret = min(ret, step + 1);
			
			if(ret < step) break;
			
			//FORI(i, sqrt(n)+1) {
			FORI(i, n+1) {
				if(prime[i] and n % i == 0) {
					int new_n = n / i;
					int new_m = m % new_n; if(new_m == 0 ) new_m=new_n;
					mp[new_n] = step+1;
					qu.push(pair<int, int>(new_n, new_m));
				}
			}
		}
		
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 56; int Arg1 = 14; int Arg2 = 3; verify_case(0, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 49; int Arg1 = 5; int Arg2 = 2; verify_case(1, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 256; int Arg1 = 7; int Arg2 = 6; verify_case(2, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 0; verify_case(3, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 77777; int Arg1 = 11111; int Arg2 = 2; verify_case(4, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 93; int Arg1 = 13; int Arg2 = 1; verify_case(6, Arg2, getLeast(Arg0, Arg1)); }
	void test_case_8() { int Arg0 = 1000000; int Arg1 = 1234; int Arg2 = 9; verify_case(8, Arg2, getLeast(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DivideAndShift ___test;
	___test.run_test(8);
}
// END CUT HERE
