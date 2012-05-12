#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

class FoxProgression {
public:
	int theCount (vector <int> seq) {
		if (seq.size() <= 1) {
			return -1;
		}
		else if(seq.size() == 2) {
			if(seq[0] == seq[1])        { return 1; }
			else if(seq[1]%seq[0] == 0) { return 2; }
			else                        { return 1; }
		}
		else {
			int no_diff = 0;
			int diff  = seq[1]-seq[0];
			int ratio = seq[1]/seq[0];
			if(seq[1]%seq[0] != 0) { ratio = 0; }
			
			for(int i=2; i<seq.size(); i++) {
				int tmp_diff  = seq[i]-seq[i-1];
				int tmp_ratio = seq[i]/seq[i-1];
				if(seq[i]%seq[i-1] != 0) { tmp_ratio = 0; }
				
				if(tmp_diff  != diff)  { no_diff = 1; }
				if(tmp_ratio != ratio) { ratio   = 0; }
			}
			
			if(no_diff == 1 & ratio == 0)   { return 0; }
			else if(no_diff == 1)           { return 1; }
			else if(ratio   == 0)           { return 1; }
			else if(diff == 0 & ratio == 1) { return 1; }
			else if(diff    == ratio)       { return 1; }
			else                            { return 2; }
		}
	}
};