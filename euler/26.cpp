/*
 * A unit fraction contains 1 in the numerator. The decimal representation of
 * the unit fractions with denominators 2 to 10 are given:
 * 
 * 1/2	= 	0.5
 * 1/3	= 	0.(3)
 * 1/4	= 	0.25
 * 1/5	= 	0.2
 * 1/6	= 	0.1(6)
 * 1/7	= 	0.(142857)
 * 1/8	= 	0.125
 * 1/9	= 	0.(1)
 * 1/10	= 	0.1
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can
 * be seen that 1/7 has a 6-digit recurring cycle.
 * 
 * Find the value of d < 1000 for which 1/d contains the longest recurring cycle
 * in its decimal fraction part.
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

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

int main() {
	vector<bool> sieve(1000);
	_is_prime2(sieve);
	
	int ret = 0;
	int maxj = 0;
	for(int i=1; i<1000; i++) {
		if(sieve[i] and i != 2 and i != 5) {
			
//			int j = 1;
//			long long num = 9;
//			while(num % i != 0) {
//				num = num * 10 + 9;
//				j++;
//			}
			
			int j = 0;
			int rem = 1;
			map<int, bool> m;
			while(m.find(rem) == m.end()) {
				m[rem] = true;
				rem *= 10;
				rem %= i;
				j++;
			}
			
			if(maxj < j) {
				ret = i;
				maxj = j;
			}
		}
	}
	
	cout <<ret <<endl;
	return 0;
}
