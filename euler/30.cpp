#include <iostream>
#include <cmath>

#define IPOW(a,b) ((int) pow((double)a,(double)b))

using namespace std;

int main() {
	int num = 5;
	
	int keta = 1;
	while (IPOW(9,num) * keta >= IPOW(10,keta)) {
		keta++;
	}
	
	int ret = 0;
	int max = IPOW(10, keta) - 1;
	for (int i=2; i<=max; i++) {
		int j = i;
		int sum = 0;
		while (j > 0) {
			sum += IPOW((j % 10), num);
			j /= 10;
		}
		if (sum == i) ret += i;
	}
	
	cout <<ret <<endl;
	return 0;
}
