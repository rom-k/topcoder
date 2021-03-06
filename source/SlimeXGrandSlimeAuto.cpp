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
#define PI M_PI
#define EPS 1e-13

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

class SlimeXGrandSlimeAuto {
public:
	int travel(vector <int> cars, vector <int> districts, vector <string> roads, int inverseWalkSpeed, int inverseDriveSpeed) {
		int N = roads.size();
		int D = districts.size();
		
		map<char, int> m;
		m.insert(map<char, int>::value_type('.', 0));
		m.insert(map<char, int>::value_type('0', 1));
		m.insert(map<char, int>::value_type('1', 2));
		m.insert(map<char, int>::value_type('2', 3));
		m.insert(map<char, int>::value_type('3', 4));
		m.insert(map<char, int>::value_type('4', 5));
		m.insert(map<char, int>::value_type('5', 6));
		m.insert(map<char, int>::value_type('6', 7));
		m.insert(map<char, int>::value_type('7', 8));
		m.insert(map<char, int>::value_type('8', 9));
		m.insert(map<char, int>::value_type('9', 10));
		m.insert(map<char, int>::value_type('a', 11));
		m.insert(map<char, int>::value_type('b', 12));
		m.insert(map<char, int>::value_type('c', 13));
		m.insert(map<char, int>::value_type('d', 14));
		m.insert(map<char, int>::value_type('e', 15));
		m.insert(map<char, int>::value_type('f', 16));
		m.insert(map<char, int>::value_type('g', 17));
		m.insert(map<char, int>::value_type('h', 18));
		m.insert(map<char, int>::value_type('i', 19));
		m.insert(map<char, int>::value_type('j', 20));
		m.insert(map<char, int>::value_type('k', 21));
		m.insert(map<char, int>::value_type('l', 22));
		m.insert(map<char, int>::value_type('m', 23));
		m.insert(map<char, int>::value_type('n', 24));
		m.insert(map<char, int>::value_type('o', 25));
		m.insert(map<char, int>::value_type('p', 26));
		m.insert(map<char, int>::value_type('q', 27));
		m.insert(map<char, int>::value_type('r', 28));
		m.insert(map<char, int>::value_type('s', 29));
		m.insert(map<char, int>::value_type('t', 30));
		m.insert(map<char, int>::value_type('u', 31));
		m.insert(map<char, int>::value_type('v', 32));
		m.insert(map<char, int>::value_type('w', 33));
		m.insert(map<char, int>::value_type('x', 34));
		m.insert(map<char, int>::value_type('y', 35));
		m.insert(map<char, int>::value_type('z', 36));
		m.insert(map<char, int>::value_type('A', 37));
		m.insert(map<char, int>::value_type('B', 38));
		m.insert(map<char, int>::value_type('C', 39));
		m.insert(map<char, int>::value_type('D', 40));
		m.insert(map<char, int>::value_type('E', 41));
		m.insert(map<char, int>::value_type('F', 42));
		m.insert(map<char, int>::value_type('G', 43));
		m.insert(map<char, int>::value_type('H', 44));
		m.insert(map<char, int>::value_type('I', 45));
		m.insert(map<char, int>::value_type('J', 46));
		m.insert(map<char, int>::value_type('K', 47));
		m.insert(map<char, int>::value_type('L', 48));
		m.insert(map<char, int>::value_type('M', 49));
		m.insert(map<char, int>::value_type('N', 50));
		m.insert(map<char, int>::value_type('O', 51));
		m.insert(map<char, int>::value_type('P', 52));
		m.insert(map<char, int>::value_type('Q', 53));
		m.insert(map<char, int>::value_type('R', 54));
		m.insert(map<char, int>::value_type('S', 55));
		m.insert(map<char, int>::value_type('T', 56));
		m.insert(map<char, int>::value_type('U', 57));
		m.insert(map<char, int>::value_type('V', 58));
		m.insert(map<char, int>::value_type('W', 59));
		m.insert(map<char, int>::value_type('X', 60));
		m.insert(map<char, int>::value_type('Y', 61));
		m.insert(map<char, int>::value_type('Z', 62));
		
		vector<bool> car_exist(N, false);
		FORI(c, cars.size()) car_exist[cars[c]] = true;
		
		//2-dimensional vector filled with 0
		vector<vector<int> > bywalk(N, vector<int>(N, 0));
		vector<vector<int> > bycar(N, vector<int>(N, 0));
		FORI(i, cars.size()) bycar[i][0] = 1;
		FORI(i, N)
			FORI(j, N) {
				int road = m[roads[i][j]];
				
				bywalk[i][j] = road * inverseWalkSpeed;
				if(car_exist[i])
					bycar[i][j] = road * inverseDriveSpeed;
			}
		
		//connect
		FORI(i, N)
			FORI(j, N)
				FORI(k, N)
					if(bywalk[i][j] > 0 and bywalk[i][k] > 0
					and i != j and j != k and k != i) {
						if(bywalk[j][k] == 0) bywalk[j][k] = bywalk[i][j] + bywalk[i][k];
						else bywalk[j][k] = min(bywalk[j][k], bywalk[i][j] + bywalk[i][k]);
					}
		
		//walk all the way
		int ret = 0;
		FORI(d, D) {
			int from = d > 0 ? districts[d-1] : 0;
			int to = districts[d];
			
			ret += bywalk[from][to];
		}
		
		//calculate car time reduces
		vector<vector<int> > reduce(D, vector<int>(N, 0));
		FORI(d, D) {
			int from = d > 0 ? districts[d-1] : 0;
			int to = districts[d];
			int t_walk = bywalk[from][to];
			
			FORI(i, N) {
				if(! car_exist[i]) continue;
				
				int t_car_n = bywalk[from][i] + bycar[i][to];
				if (t_car_n < t_walk) reduce[d][i] = t_walk - t_car_n;
				
				if(DEBUG) cout <<"reduce[" <<d <<"][" <<i <<"] = " <<reduce[d][i] <<endl;
			}
		}
		
		//TODO
		
		return ret;
	}

	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
"..0.",
"...1",
"0..2",
".12."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; int Arg4 = 1; int Arg5 = 36; verify_case(0, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".A.",
"A.B",
".B."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 1; int Arg5 = 262; verify_case(1, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arr0[] = {2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".a4",
"a..",
"4.."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 1; int Arg5 = 95; verify_case(2, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".B.",
"B.A",
".A."}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 1; int Arg5 = 262; verify_case(3, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arr0[] = {2,5,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,5,1,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {
".12.4.",
"1....7",
"2..3..",
"..3..5",
"4.....",
".7.5.."}
; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 53; int Arg4 = 37; int Arg5 = 1259; verify_case(4, Arg5, travel(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SlimeXGrandSlimeAuto ___test;
	___test.run_test(-1);
}
// END CUT HERE
