#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >>a >>b >>c;

    double d = a * c;
    d /= b;
    d -= c;
    int e = (int)d;
    if (e < d) e++;

    cout <<e <<endl;
    return 0;
}
