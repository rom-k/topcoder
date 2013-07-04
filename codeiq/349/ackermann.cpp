#include <string>
#include <sstream>
#include <iostream>

using namespace std;

typedef long long LL;

int _atoi(string str) {
    int n;
    istringstream istr(str);
    istr >>n;
    return n;
}

LL ack(LL m, LL n) {
    if (m == 0) {
        return n + 1;
    }
    else if (n == 0) {
        return ack(m - 1, 1);
    }
    else {
        return ack(m - 1, ack(m, n - 1));
    }
}

int main(int argc, char *argv[]) {
    LL m = (LL)_atoi(argv[1]);
    LL n = (LL)_atoi(argv[2]);
    cout <<ack(m, n) <<endl;
    return 0;
}
