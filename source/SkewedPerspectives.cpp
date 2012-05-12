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

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

class SkewedPerspectives {
public:
    vector <string> areTheyPossible(vector <int> cubes, int B, int wi, VS views) {
        int n = SZ(views);
        vector <string> ret;
        
        FORI(i, n) {
            int cu[3], bl, w;
            string v;
            cu[0] = cubes[0];
            cu[1] = cubes[1];
            cu[2] = cubes[2];
            bl = B;
            w = wi - 1;
            v = views[i];
            
            if (SZ(v) == 1 and v[0] == 'b' or
                SZ(v) >= 2 and v[0] == 'b' and v[1] != 'b') {
                ret.PB("invalid");
                continue;
            }
            
            bool valid = true;
            VI hidden;
            FORI(j, SZ(v)) {
                char c = v[j];
                int num_c = c - '0';
                
                if(c != 'b') { //'0'-'2'
                    if (cu[num_c] > 0) { cu[num_c]--; }
                    else               { valid = false; break; }
                }
                
                else { //'b'
                    if (bl > 0) { bl--; }
                    else        { valid = false; break; }
                    
                    int num_b = 1;
                    while (j+num_b < SZ(v) && v[j+num_b] == 'b') { num_b++; }
                    
                    //if (j+1 < SZ(v) && v[j+1] == 'b') { // 'bb'
                    if (num_b % 2 == 0) { // 'b' continues even counts
                        j++;
                    }
                    
                    else if (j == 0) { // 'b' continues odd, but the base block
                        j++;
                    }
                    
                    //else { // not 'bb'
                    else { // 'b' continues odd counts
                        if (w > 0) { w--; }
                        else       { valid = false; break; }
                        hidden.PB(j-1);
                    }
                }
            }
            
            FORI(j, SZ(hidden)) {
                if (!valid) break;
                
                int hi = hidden[j];
                while(hi >= 2 && bl >= 1) { hi-=2; bl--; }
                FORI(k, 3)
                    while(hi >= 1 && cu[k] >= 1) { hi--; cu[k]--; }
                if (hi > 0) valid = false;
            }
            
            if (valid) { ret.PB("valid");   }
            else       { ret.PB("invalid"); }
        }
        
        return ret;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; string Arr3[] = { "012", "012bb", "bb0", "21bb", "21b", "1bb20" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; string Arr3[] = {"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" }; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {100,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 3; string Arr3[] = {"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000b00000000000000",
 "0000000000000000000000000000000000000000000000000b",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {5,6,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; string Arr3[] = {"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "invalid", "valid", "invalid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(3, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {100,100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 50; string Arr3[] = {"2",
 "bb1b012012012012012012012",
 "bb1b012012012012012012012b",
 "bb1b012012012b012b012b012012b",
 "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "bbb1b012012012012012012012"
}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(4, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; string Arr3[] = {"0", "bb"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "invalid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(5, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arr0[] = {3,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; string Arr3[] = {"00b0b", "bbbbbbbb", "000b"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); string Arr4[] = {"invalid", "valid", "valid" }; vector <string> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(6, Arg4, areTheyPossible(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    SkewedPerspectives ___test;
    ___test.run_test(-1);
}
// END CUT HERE
