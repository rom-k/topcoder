#include <iostream>
#include <stdio.h>
using namespace std;

int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int uruu(int y) {
    if (y % 4 == 0 and y % 100 != 0
    or y % 400 == 0) {
        return true;
    }
    return false;
}

int main() {
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);

    while(y % m != 0 or (y / m) % d != 0) {
        if (y % m != 0) {
            m++;
            d = 1;
            if (12 < m) m = 1, y++;
        }
        else {
            int dnum = days[m];
            if (m == 2 and uruu(y)) dnum++;
            d++;
            if (dnum < d) d = 1, m++;
            if (12 < m) m = 1, y++;
        }
    }

    printf("%4d/%02d/%02d\n", y, m, d);
    return 0;
}
