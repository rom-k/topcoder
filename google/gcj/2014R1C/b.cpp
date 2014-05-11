#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

#define MAXN 105
#define MOD 1000000007
#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
typedef long long LL;

LL fact(LL n) {
	if (n == 0) return 1;
	return (n * fact(n - 1)) % MOD;
}

int main() {
    int T;
    cin >>T;
    cin.ignore();

    for(int t=1; t<=T; t++) {

		int	N;
		LL ans = 1;
		string in[MAXN];
		bool valid = true;

		cin >> N;
		REP(i, N) cin >> in[i];

		// Shorten
		REP(i, N) {
			string a;
			char c = ' ';
			REP(j, in[i].size()) {
				if (in[i].at(j) != c) {
					a += in[i].at(j);
					c = in[i].at(j);
				}
			}
			in[i] = a;
		}

		// Loop for char
		REP(i, 26) {
			char c = 'a' + i;

			int count_all = 0;
			int count_left = 0;
			int count_right = 0;
			int count_center = 0;

			int index_left = -1;
			int index_right = -1;
			int index_all[MAXN];
			REP(j, N) index_all[j] = -1;

			// Count cases
			REP(j, N) {
				int index = in[j].find(c);

				if (index == string::npos) {
					continue;
				}
				else if (index != in[j].rfind(c)) {
					valid = false;
				}
				else if (in[j].size() == 1) {
					count_all++;
					index_all[count_all - 1] = j;
				}
				else if (index == 0) {
					count_left++;
					index_left = j;
				}
				else if (index == in[j].size() - 1) {
					count_right++;
					index_right = j;
				}
				else {
					count_center++;
				}
				
			}

			// Validation check
			if (count_center == 0) {
				if (1 < count_left || 1 < count_right) {
					valid = false;
				}
			}
			else if (count_center == 1) {
				if (count_all != 0 || count_left != 0 || count_right != 0) {
					valid = false;
				}
			}
			else {
				valid = false;
			}

			// Concatination
			if (1 < count_all + count_left + count_right) {
				if (0 == count_left + count_right) {
					REPS(j, 1, count_all) {
						in[index_all[j]] = "";
					}
				}
				else {
					REPS(j, 0, count_all) {
						in[index_all[j]] = "";
					}
				}
				if (1 < count_left + count_right) {
					in[index_right] += in[index_left];
					in[index_left] = "";
				}

				ans *= fact(count_all);
				ans %= MOD;
			}
		}
		
		// Rest of strings
		int rest = 0;
		REP(i, N) {
			if (in[i] != "") rest++;
		}
		ans *= fact(rest);
		ans %= MOD;

		if (!valid) ans = 0;
		cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
