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

class _bigint {
public:
	vector<int> n;
	
	_bigint(int a) {
		while(a > 0) {
			n.push_back(a % 10);
			a = a / 10;
		}
	}
	
	inline bool operator *= (const int a) const {
		int carrer = 0;
		
		for(int i=0; i<n.size(); i++) {
			int b = n[i] * a + carrer;
			
			n[i] = b % 10;
			carrer = b / 10;
		}
		
		while(carrer > 0) {
			n.push_back(carrer % 10);
			carrer = carrer / 10;
		}
	}
};

int main() {
	int LEN = 10;
	
//	vector<vector<int> > dp(LEN+1, vector<int>(10, 0));
//	dp[0][0] = 1;
//	
//	for(int i=1; i<LEN+1; i++) {
//		for(int j=0; j<10; j++) {
//			int num = i * (j + 1);
//			while(num > 0) {
//				dp[i][num % 10 - 1] += dp[i - 1][j];
//				num = num / 10;
//			}
//		}
//	}
//	
//	int ret = 0;
//	for(int j=0; j<10; j++) {
//		ret += (j + 1) * dp[LEN][j];
//	}
//	
//	cout <<ret <<endl;
//	return 0;
	
	_bigint a(1);
	
	for(int i=1; i<LEN+1; i++) {
		a *= i;
	}
	
	int ret = 0;
	for(int i=0; i<a.n.size(); i++) {
		ret += a.n[i];
	}
	
	cout <<ret <<endl;
	return 0;
}
