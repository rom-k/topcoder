#include <stdio.h>
#include <time.h>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <stack>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <utility>
#include <memory>
#include <functional>
#include <complex>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<LL> VL;

#define FORE(it, c, T) for(T::iterator it = c.begin(); it != c.end(); it++)
#define FORI(i, n) for(int i = 0; i < (n); i++)
#define FORIS(i, s, n) for(int i = (s); i < (n); i++)
#define CLEAR(a) memset(a, 0, sizeof(a))
#define SORT(a) sort(a.begin(), a.end())
#define PB(n) push_back(n)
#define PI M_PI
#define EPS 1e-13

#define DEBUG 0
#define DBG(a) if (DEBUG) cout <<"DEBUG::: " <<a <<endl;
#define DBG2(a, b) if (DEBUG) cout <<"DEBUG::: " <<a <<"=" <<b <<endl;

string swap12(string a){
	string b;
	b = a.substr(1);
	b.insert(1, a.substr(0,1));
	return b;
}

int main() {
	int T;
	cin >>T;
	cin.ignore();
	
	for(int t=1; t<=T; t++) {
		int C;
		cin >>C;
		vector<string> com;
		FORI(i, C) {
			string tmp;
			cin >>tmp;
			com.PB(tmp);
			if (tmp[0] != tmp[1]) com.PB(swap12(tmp));
		}
		
		int D;
		cin >>D;
		vector<string> opp;
		FORI(i, D) {
			string tmp;
			cin >>tmp;
			opp.PB(tmp);
			if (tmp[0] != tmp[1]) opp.PB(swap12(tmp));
		}
		
		int N;
		string input;
		cin >>N >>input;
		
		vector<char> list;
		FORI(i, N) {
			list.PB(input[i]);
			
			bool need_test = true;
			while (need_test) {
				need_test = false;
				if(list.size() < 2) break;
				
				if(DEBUG) FORI(i, list.size()) cout <<list[i];
				if(DEBUG) cout <<endl;
				
				//test combine
				FORI(i, com.size()) {
					if(DEBUG) cout <<" check for " <<com[i] <<endl;
					if( com[i][0] == list[list.size()-2]
					and com[i][1] == list[list.size()-1]) {
						list.pop_back();
						list.pop_back();
						list.PB(com[i][2]);
						if(DEBUG) cout <<" hit!" <<endl;
						
						need_test = true; break;
					}
				}
				if(need_test) continue;
				
				//test oppose
				FORI(i, opp.size()) {
					if(DEBUG) cout <<" check for " <<opp[i] <<endl;
					if(opp[i][1] == list[list.size()-1]) {
						for(int j=list.size()-2; j>=0; j--) {
							if(opp[i][0] == list[j]) {
								//int tmp = list.size()-j;
								int tmp = list.size();
								FORI(k, tmp) list.pop_back();
								if(DEBUG) cout <<" hit! (" <<j <<")" <<endl;
								
								need_test = true; break;
							}
						}
					}
					if(need_test) continue;
				}
			}
		}
		
		cout <<"Case #" <<t <<": [";
		FORI(i, list.size()) {
			if(i != 0) cout <<", ";
			cout <<list[i];
		}
		cout <<"]" <<endl;
	}
	
	return 0;
}
