#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
	int a[3], b[3], ans;
	cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
	sort(a, a + 3);
	sort(b, b + 3);
	ans = 0;
	REP(i, 3) ans += abs(a[i] - b[i]);
    cout << ans << endl;
    return 0;
}
