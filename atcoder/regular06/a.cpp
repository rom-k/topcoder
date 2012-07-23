#include <iostream>
using namespace std;

int main() {
    int e[6], b, l[6];
    for (int i=0;i<6;i++) cin >>e[i];
    cin >>b;
    for (int i=0;i<6;i++) cin >>l[i];

    bool atari[10];
    for (int i=0;i<10;i++) atari[i] = false;
    for (int i=0;i<6;i++) atari[e[i]] = true;

    int n_atari = 0;
    int n_bonus = 0;
    for (int i=0;i<6;i++) {
        if (atari[l[i]]) n_atari++;
        if (b == l[i]) n_bonus++;
    }

    int ret = 0;
    if      (n_atari == 6) ret = 1;
    else if (n_atari == 5 and n_bonus == 1) ret = 2;
    else if (n_atari == 5) ret = 3;
    else if (n_atari == 4) ret = 4;
    else if (n_atari == 3) ret = 5;
    cout <<ret <<endl;

    return 0;
}
