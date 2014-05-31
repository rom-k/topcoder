#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
typedef long long LL;

#define MAXN 1005

int main() {
    int T;
    cin >>T;
    cin.ignore();

    for(int t=1; t<=T; t++) {

		int	N;
		LL A[MAXN];

		int ans = 0;

		cin >> N;
		//scanf("%d,%d", &P, &Q);
		REP(i, N) cin >> A[i];

		map<LL, int> m;
		REP(i, N) m[A[i]] = i;

		//for (map<LL, int>::iterator it = m.begin(); it != m.end(); it++) {
		while (!m.empty()) {
			int n = m.size();
			map<LL, int>::iterator it = m.begin();
			LL val = (*it).first;
			int i = (*it).second;
			m.erase(it);
			
			for (map<LL, int>::iterator it2 = m.begin(); it2 != m.end(); it2++) {
				if (i < (*it2).second) {
					(*it2).second--;
				}
			}

			ans += min(i, n - 1 - i);
		}

		cout << "Case #" << t << ": " << ans << endl;
		//printf("Case #%d: %.07lf\n", t, ans);
	}
    return 0;
}
