#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
typedef long long LL;

#define MAXN 10005

int main() {
    int T;
    cin >>T;
    cin.ignore();

    for(int t=1; t<=T; t++) {

		int	N, X;
		int S[MAXN];

		int ans = 0;

		cin >> N >> X	;
		//scanf("%d,%d", &P, &Q);
		REP(i, N) cin >> S[i];

		sort(S, S + N);

		int i = 0;
		int j = N - 1;
		while (i <= j) {
			if (i == j) {
				ans++;
				break;
			}
			else if(S[i] + S[j] <= X) {
				i++;
				j--;
				ans++;
			}
			else {
				j--;
				ans++;
			}
		}

		cout << "Case #" << t << ": " << ans << endl;
		//printf("Case #%d: %.07lf\n", t, ans);
	}
    return 0;
}
