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

struct _tree {
	string         w;
	vector<_tree*> c;
	
	_tree ()          { _tree(""); }
	_tree (string w0) { w = w0; }
//	~_tree
	
	void add (string word, int num, string letters) {
		if (w == word) { return; }
//		DBG2("w",w);
		
		string new_w = w;
		FORI(i, new_w.size()) if(word[i] == letters[num]) new_w[i] = word[i];
//		DBG2("new_w",new_w);
		
		// find child tree
		int i2 = -1;
		FORI(i, c.size())
			if(c[i]->w == new_w)
				i2 = i;
		
		// create new _tree if not exist
		if (i2 < 0) {
//			DBG(" create new child");
			_tree* new_t = new _tree(new_w);
			c.PB(new_t);
			i2 = c.size()-1;
		}
		
		// do it recursive
		c[i2]->add(word, num+1, letters);
	}
	
	int find_max_cost (string& word) {
		DBG2(" ::: w",w);
		
		if(c.size() <= 0) {
			word = w;
			return -1;
		}
		
		if(c.size() <= 1) {
			int tmp_num = c[0]->find_max_cost(word);
			//if(tmp_num >= 0) tmp_num++;
			return tmp_num;
		}
		
		int max_cost = -1;
		string max_word = "";
//		int max_i    = -1;
		FORI(i, c.size()) {
			string tmp_word;
			int tmp_num = c[i]->find_max_cost(tmp_word);
			if(tmp_num < 0) tmp_num=0;
			if(w == c[i]->w) tmp_num++;
			if(tmp_num > max_cost) {
				max_cost = tmp_num;
				max_word = tmp_word;
//				max_i    = i;
			}
		}
		word = max_word;
		return max_cost;
	}
	
	string first_word () {
		if(c.size() == 0) return w;
		return c[0]->first_word();
	}
};

int main() {
	int T;
	cin >>T;
	cin.ignore();
	
	for(int t=1; t<=T; t++) {
		
		int nD, nL;
		cin >>nD >>nL;
		
		vector<string> D(nD);
		vector<string> L(nL);
		FORI(i, nD) cin >>D[i];
		FORI(i, nL) cin >>L[i];
		
		int max_len = 0;
		FORI(i, nD) max_len = max(max_len, (int)D[i].size());
		
		DBG2("max_len",max_len);
		
		cout <<"Case #" <<t <<":";
		
		// loop for strategies
		FORI(i, nL) {
			string word = D[0];
			int    cost = 0;
			
			// use L[i]
			
			// loop for word length cases
			for(int j=1; j<=max_len; j++) {
				
				vector<string> wordlist;
				FORI(k, nD)
					if(j == (int)D[k].size()) wordlist.PB(D[k]);
				
				if(wordlist.size() <= 0) continue;
				
				if(DEBUG) cout <<"DEBUG:::     wordlist = ";
				FORI(k, wordlist.size()) if(DEBUG) cout <<" " <<wordlist[k];
				if(DEBUG) cout <<endl;
				
				// use wordlenght: j
				// use wordlist  : wordlist
				
				string start_word;
				FORI(k, j) start_word += "_";
				_tree t(start_word);
				
				FORI(k, wordlist.size()) {
					DBG2("----------", wordlist[k]);
					t.add(wordlist[k], 0, L[i]);
				}
				
				string max_first_word;
				int max_cost = t.find_max_cost(max_first_word);
				if(DEBUG) cout <<"DEBUG::: " <<max_first_word <<" is cost " <<max_cost <<endl;
				
				if(max_cost > cost) {
					cost = max_cost;
					word = max_first_word;
				}
			}
			
			cout <<" " <<word;
		}
		
		cout <<endl;
	}
	
	return 0;
}
