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
#define PB(n) push_back(n)
#define PI M_PI
#define EPS 1e-13

#define DEBUG 1
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

class ParticleCollision {
public:
	vector <double> collision(int vx, int vy, int vz, int x0, int y0, int z0) {
		VD result;
		
		if (vx == 0 and vy == 0) {
			if (vz == 0) {
				double x1 = cos(PI*z0);
				double y1 = sin(PI*z0);
				DBG2("x1",x1);
				DBG2("y1",y1);
				
				bool ok_x = fabs(x1-x0) < EPS;
				bool ok_y = fabs(y1-y0) < EPS;
				DBG2("ok_x",ok_x);
				DBG2("ok_y",ok_y);
				
				if (ok_x and ok_y) {
					result.PB(x0); result.PB(y0); result.PB(z0);
				}
			}
			else {
				if (x0*x0+y0*y0 == 1) {
					result.PB(0); result.PB(0); result.PB(0);
				}
			}
			return result;
		}
		
		double a = vx*vx+vy*vy;
		double b = vx*x0+vy*y0;
		double c = x0*x0+y0*y0-1;
		double D = b*b-a*c;
		DBG2("a",a);
		DBG2("b",b);
		DBG2("c",c);
		DBG2("D",D);
		
		if (D<0) return result;
		
		//double t1 = (-b-sqrt(D))/a;
		//double t2 = (-b+sqrt(D))/a;
		//DBG2("t1",t1);
		//DBG2("t2",t2);
		
		double x1 = vx*(-b-sqrt(D))/a+x0;
		double y1 = vy*(-b-sqrt(D))/a+y0;
		double z1 = vz*(-b-sqrt(D))/a+z0;
		double x2 = vx*(-b+sqrt(D))/a+x0;
		double y2 = vy*(-b+sqrt(D))/a+y0;
		double z2 = vz*(-b+sqrt(D))/a+z0;
		DBG2("x1",x1);
		DBG2("y1",y1);
		DBG2("z1",z1);
		DBG2("x2",x2);
		DBG2("y2",y2);
		DBG2("z2",z2);
		
		double th1 = atan2(y1, x1);
		double th2 = atan2(y2, x2);
		DBG2("th1",th1);
		DBG2("th2",th2);
		
		double z1_c = th1/PI;
		double z2_c = th2/PI;
		DBG2("z1_c",z1_c);
		DBG2("z2_c",z2_c);
		
		double diff_z1 = z1 - z1_c;
		double diff_z2 = z2 - z2_c;
		DBG2("diff_z1",diff_z1);
		DBG2("diff_z2",diff_z2);
		
		bool ok1 = fmod(fabs(diff_z1),2) < EPS;
		bool ok2 = fmod(fabs(diff_z2),2) < EPS;
		DBG2("ok1",ok1);
		DBG2("ok2",ok2);
		
		if (ok1 and ok2 and D!=0) {
			result.PB(0); result.PB(0); result.PB(0);
		}
		else if (ok1) {
			result.PB(x1); result.PB(y1); result.PB(z1);
		}
		else if (ok2) {
			result.PB(x2); result.PB(y2); result.PB(z2);
		}
		return result;
	}

	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
