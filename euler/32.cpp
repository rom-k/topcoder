#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main() {
	set<int> s;
	vector<int> vi;
	for(int i=1; i<=9; i++) vi.push_back(i);
	
	// next_permutation
	//  do {
	//  } while(next_permutation(hoge.begin(), hoge.end()));
	
	do {
		for(int i=1; i<=7; i++) for(int j=i+1; j<=8; j++) {
			int a=0;
			int b=0;
			int c=0;
			
			for(int k=0; k<=8; k++) {
				if(k<i) {
					a += vi[k] * (int)pow(10.,i-1-k);
				}
				else if(k<j) {
					b += vi[k] * (int)pow(10.,j-1-k);
				}
				else {
					c += vi[k] * (int)pow(10.,8-k);
				}
			}
			
			if (a*b==c) {
				//cout <<"DEBUG::: (" <<i <<"," <<j <<") " <<a <<" * " <<b <<" == " <<c <<endl;
				s.insert(c);
			}
		}
	} while(next_permutation(vi.begin(), vi.end()));
	
	long long sum = 0;
	set<int>::iterator it = s.begin();
	while(it != s.end()) {
		sum += *it;
		++it;
	}
	
	cout <<"sum=" <<sum <<endl;
	
	return 0;
}
