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

class DreamingAboutCarrots {
public:
	int carrotsBetweenCarrots(int x1, int y1, int x2, int y2) {
		int a = x2-x1;
		int b = y2-y1;
		if (a<0) a = -a;
		if (b<0) b = -b;
		return gcd(a, b) -1;
	}
	
	int gcd(int a, int b) {
		int c=0;
		while (b != 0) {
			c = a % b;
			a = b;
			b = c;
		}
		
		return a;
	}

	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
