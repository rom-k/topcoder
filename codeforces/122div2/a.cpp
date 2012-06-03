#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >>n >>k;
    cout <<max(0, n-(k-2*n)) <<endl;
    return 0;
}
