#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int ret = 0;
	int max = 100;
	map<int, bool> m;
	
	for (int i=2; i<=max; i++) {
		if(m.find(i) == m.end()) {
			int j = 1;
			while (pow((double)i, (double)j) <= max) {
				m[(int) pow((double)i, (double)j)] = true;
				j++;
			}
			j--;
			
			map<int, bool> m2;
			for (int k=1; k<=j; k++) {
				for (int l=2; l<=max; l++) {
					if(m2.find(k * l) == m2.end()) {
						m2[k * l] = true;
						ret++;
					}
				}
			}
		}
	}
	
	cout <<ret <<endl;
	return 0;
}
