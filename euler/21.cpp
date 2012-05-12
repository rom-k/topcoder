/*
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 * which divide evenly into n).
 * If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and
 * each of a and b are called amicable numbers.
 * 
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 * 
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int sum = 0;
	vector<int> vi(10000, 1);
	
	for(int i=2; i<vi.size(); i++) {
		for(int j=i*2; j<vi.size(); j+=i) {
			vi[j] += i;
		}
		if(vi[i] < i and vi[vi[i]] == i) {
			sum += i + vi[i];
		}
	}
	
	cout <<sum <<endl;
	return 0;
}
