#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, r1, R1;
    double x2, y2, r2, R2;
    cin >>x1 >>y1 >>r1 >>R1;
    cin >>x2 >>y2 >>r2 >>R2;
    double l = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    int ret = 0;
    if (l<r1 and l+R2<=r1 or l>r1 and l-R2>=r1 or r1<=r2-l) ret++;
    if (l<R1 and l+R2<=R1 or l>R1 and l-R2>=R1 or R1<=r2-l) ret++;
    if (l<r2 and l+R1<=r2 or l>r2 and l-R1>=r2 or r2<=r1-l) ret++;
    if (l<R2 and l+R1<=R2 or l>R2 and l-R1>=R2 or R2<=r1-l) ret++;
    cout <<ret <<endl;
    return 0;
}
