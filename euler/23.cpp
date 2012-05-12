#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int max = 28123 + 5;
	vector<int> divsum(max, 1);
	vector<int> abun; //abundant
	
	for(int i=2; i<divsum.size(); i++) {
		for(int j=i*2; j<divsum.size(); j+=i) {
			divsum[j] += i;
		}
		if(i < divsum[i]) {
			abun.push_back(i);
		}
	}
	
	vector<bool> sumof_abun(max, false);
	
	for(int i=0; i<abun.size(); i++) {
		for(int j=i; j<abun.size(); j++) {
			if(abun[i] + abun[j] < max) {
				sumof_abun[abun[i] + abun[j]] = true;
			}
		}
	}
	
	int sum = 0;
	
	for(int i=0; i<max; i++) {
		if(!sumof_abun[i]) sum+=i;
	}
	
	cout <<sum <<endl;
	return 0;
}
