#include <iostream>
#include <cmath>

using namespace std;

long long _fibonacci(int n) {
	long long a = 0.;
	long long b = 1.;
	for(int i=2; i<n+1; i++) {
		long long c = a + b;
		a = b;
		b = c;
	}
	return b;
}

#define PHI 1.618033988749895
long long _fibonacci2(int n) {
	return (long long) (pow(PHI, n) / sqrt(5.));
}

int _num_of_dig_fibonacci(int n) {
	double pp = 0.;
	double p = 1.;
	int ret = 0;
	
	for(int i=2; i<n+1; i++) {
		double c = pp + p;
		if(c >= 10) {
			pp *= .1;
			p *= .1;
			c *= .1;
			ret++;
		}
		
		pp = p;
		p = c;
	}
	
	return ret + 1;
}

int main() {
	int a = 1;
	int b = 10000;
	int len = 1000;
	
	// binary search
	while(a + 1 != b) {
		int c = (a + b) / 2;
		
		if(_num_of_dig_fibonacci(c) < len) { a = c; }
		else                               { b = c; }
	}
	
	cout <<b <<endl;
	return 0;
}
