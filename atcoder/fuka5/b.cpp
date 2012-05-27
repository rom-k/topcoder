#include <stdio.h>
#include <iostream>
using namespace std;

int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    while(1) {
        int y,  n,  d,  h,  m,  s;
        scanf("%d/%d/%d %d:%d:%d", &y, &n, &d, &h, &m, &s);
        if (y==0) break;
        string ti;
        cin >>ti;
        long long t = 0;
        for (int i=0;i<ti.size();i++) {
            t *= 2;
            t += 1;
        }

        t += (d-1)*24*60*60 + h*60*60 + m*60 + s;
        d = 1; h = m = s = 0;
        while (1) {
            int d1 = days[n];
            if (n==2 and (y%400==0 or (y%100!=0 and y%4==0))) d1++;
            long long s1 = d1*24*60*60;
            if (t < s1) break;

            t -= s1;
            if(++n > 12) { n=1; y++; }
        }
        d += t / (24*60*60);
        h += (t % (24*60*60)) / (60*60);
        m += (t % (60*60)) / 60;
        s += (t % 60);

        printf("%d/%02d/%02d %02d:%02d:%02d\n", y, n, d, h, m, s);
    }
    return 0;
}
