#include <iostream>
#include <cmath>

using namespace std;

int coin[8];

int func(int i, int m) {
	if (8 <= i) {
		if (m == 0) { return 1; }
		else        { return 0; }
	}
	
	int ret = 0;
	for (int j=0; j<=m/coin[i]; j++) {
		ret += func(i+1, m - j * coin[i]);
	}
	return ret;
}

int main() {
	int money = 200;
	coin[0] = 200;
	coin[1] = 100;
	coin[2] =  50;
	coin[3] =  20;
	coin[4] =  10;
	coin[5] =   5;
	coin[6] =   2;
	coin[7] =   1;
	
	cout <<func(0, money) <<endl;
	return 0;
}
