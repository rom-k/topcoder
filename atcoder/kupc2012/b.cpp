#include <iostream>
using namespace std;

int main() {
    string a;
    cin >>a;
    char ret = 'o';
    if (a[0] == a[a.size()-1] and a[0] == 'x') ret = 'x';
    cout <<ret <<endl;
    return 0;
}
