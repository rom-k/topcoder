/*
 * n! means n  (n  1)  ...  3  2  1
 * 
 * For example, 10! = 10  9  ...  3  2  1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 * 
 * Find the sum of the digits in the number 100!
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int LEN = 100;
	
	vector<int> a;
	a.push_back(1);
	
	for(int i=1; i<LEN+1; i++) {
		int car = 0;
		for(int j=0; j<a.size(); j++) {
			int b = a[j] * i + car;
			a[j] = b % 10;
			car  = b / 10;
		}
		while(car > 0) {
			a.push_back(car % 10);
			car /= 10;
		}
	}
	
	int ret = 0;
	for(int i=0; i<a.size(); i++) {
		ret += a[i];
	}
	
	cout <<ret <<endl;
	return 0;
}
