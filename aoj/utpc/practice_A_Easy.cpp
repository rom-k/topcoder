#include <cstdio>
#include <cmath>

int main() {
    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    double s = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    printf("%.8f\n", s);
    return 0;
}
