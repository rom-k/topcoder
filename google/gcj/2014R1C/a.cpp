#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int T;
    cin >>T;
    cin.ignore();

    for(int t=1; t<=T; t++) {

		int	P, Q;
		int ans = 0;
		bool impossible = false;

		scanf("%d/%d", &P, &Q);

		for (int i = Q; 1 < i; i /= 2) {
			if (i % 2 != 0) {
				if (P % i == 0) {
					P /= i;
					Q /= i;
				}
				else {
					impossible = true;
				}
				break;
			}
		}

		if (! impossible) {
			while (Q > 1) {
				Q /= 2;
				ans++;
				if (Q <= P) {
					break;
				}
			}
		}

		if (impossible) {
			cout << "Case #" << t << ": impossible" << endl;
		}
		else {
			cout << "Case #" << t << ": " << ans << endl;
		}
    }
    return 0;
}
