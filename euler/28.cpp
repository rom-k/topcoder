
#include <iostream>

using namespace std;

int main() {
	int len = 1001;
	int sum = 1;
	
	for (int i=3; i<=len; i+=2) {
		int sq = i * i;
		sum += sq;
		sum += sq - (i - 1);
		sum += sq - (i - 1) * 2;
		sum += sq - (i - 1) * 3;
	}
	
	cout <<sum <<endl;
	return 0;
}
