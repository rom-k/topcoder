#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
#define REPS(i,s,n) for(LL i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

#define DEBUG 0
#define MAXW 105
#define MAXH 505

int main() {
    int T;
    cin >>T;
    cin.ignore();

    for(int t=1; t<=T; t++) {

		LL	W, H, B;
		int c[MAXW][MAXH];
		int ans = 0;

		cin >> W >> H >> B;
		REP(x, W)REP(y, H) c[x][y] = 0;
		REP(i, B) {
			LL x0, y0, x1, y1;
			cin >> x0 >> y0 >> x1 >> y1;
			REPS(x, x0, x1 + 1) REPS(y, y0, y1 + 1) {
				c[x][y] = 9;
			}
		}

		LL startx = 0;
		LL xdiff[] = { 1, 0, -1, 0 };
		LL ydiff[] = { 0, -1, 0, 1 };

		while (true) {
			while ((c[startx][0] > 0 || c[startx][1] > 0 ) && startx < W) startx++;
			if (W <= startx) break;

			LL x = startx;
			LL y = 0;
			int dir = 0;
			c[x][y] = 1;

			while (true) {
				if (DEBUG) {
					cout << "---" << endl;
					for (LL y = H - 1; y >= 0; y--) {
						REP(x, W) {
							if (c[x][y] == 0) cout << " ";
							else if (c[x][y] == 1) cout << "+";
							else                   cout << "#";
						}
						cout << "|" << endl;
					}
				}

				if (H - 1 <= y) {
					ans++;
					break;
				}
				if (x == startx && y == 0 && c[x][y + 1] > 0)
					break;
				
				dir = (dir + 3) % 4;
				REP(i, 4) {
					if (0 <= x + xdiff[dir] && x + xdiff[dir] < W
						&& 0 <= y + ydiff[dir] && y + ydiff[dir] < H
						&& c[x + xdiff[dir]][y + ydiff[dir]] <= 1)
						break;
					dir = (dir + 1) % 4;
				}
				
				x += xdiff[dir];
				y += ydiff[dir];
				c[x][y] = 1;
			}

			REP(x, W) REP(y, H) if (c[x][y] == 1) c[x][y] = 2;
			startx++;
		}

		cout << "Case #" << t << ": " << ans << endl;
	}
    return 0;
}
