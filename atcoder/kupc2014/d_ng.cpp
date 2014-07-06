#include <iostream>
#include <string>
using namespace std;
 
#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)
 
#define MOD 1000000007
typedef long long LL;
 
LL comb(LL n, LL r) {
     if(n==r) return 1;
     if(r==1) return n;
     return comb(n-1,r) + comb(n-1,r-1);
}
 
int main() {
	string s1, s2;
	LL d1, d2;
	cin >> s1;
	cin >> d1;
	cin >> s2;
	cin >> d2;
	
	LL total_count = s1.size();
	LL same_count = 0;
	REP(i, total_count) if (s1[i] == s2[i]) same_count++;
	LL diff_count = total_count - same_count;
	
	LL ans;
	LL total_d = d1 + d2;
	LL same_d1 = (total_d - diff_count) / 2;
	LL diff_d1 = d1 - same_d1;
	
	if (diff_count < total_d
	&& (total_d - diff_count) % 2 == 0
	&& diff_d1 <= diff_count
	&& same_d1 <= same_count) {
		ans = 1;
		ans *= comb(diff_count, diff_d1);
		ans %= MOD;
		ans *= comb(same_count, same_d1);
		ans %= MOD;
	}
	else {
		ans = 0;
	}
	
	cout <<ans <<endl;
	return 0;
}
