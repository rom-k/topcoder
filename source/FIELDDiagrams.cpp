#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-5;
//typedef long long ll;

class FIELDDiagrams {
public:
	long long countDiagrams(int fieldOrder) {
		vector<long long> box(fieldOrder+1);
		long long ret = 0;
		
		box[0] = 1;
		for(int i=1; i<=fieldOrder; i++) {
//			printf("i=%d\n",i);
			box[i] = 0;
		}
		
		for(int i=1; i<=fieldOrder; i++) {
//			printf("i=%d\n",i);
			for(int j=i; j>=0; j--) {
//				printf("  j=%d\n",j);
				long long sum = 0;
				for(int k=0; k<=j; k++) {
//					printf("    k=%d\n",k);
					sum = sum + box[k];
				}
				box[j] = sum;
//				printf("  box(%d)=%lld\n",j,sum);
			}
		}
		
		for(int j=1; j<=fieldOrder; j++) {
			ret = ret + box[j];
		}
		
		return ret;
	}

	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
