#include <iostream>
using namespace std;

int main() {
    int a,b,c,n;
    cin >>a >>b >>c >>n;
    cout <<max(0,n-a) <<" " <<max(0,2*n-b) <<" " <<max(0,3*n-c) <<endl;
    return 0;
}
