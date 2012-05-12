#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
	
	int len = 10;
	int num = 1000000;
	num--;
	
	vector<int> num_permutation(len + 1, 0);
	num_permutation[0] = 1;
	num_permutation[1] = 1;
	for(int i=2; i<num_permutation.size(); i++) {
		num_permutation[i] = num_permutation[i-1] * i;
	}
	
	vector<string> rest(len);
	for(int i=0; i<rest.size(); i++) {
		//itoa (from int i to string rest[i])
		char c[2];
		sprintf(c, "%d", i);
		rest[i] = string(c);
	}
	
	for(int i=num_permutation.size()-1; i>0; i--) {
		int div = num / num_permutation[i-1];
		num %= num_permutation[i-1];
		
		cout <<rest[div];
		rest.erase(rest.begin() + div);
	}
	
	return 0;
}
