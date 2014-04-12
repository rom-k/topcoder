#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int T;
    cin >>T;
    cin.ignore();

    for(int t=1; t<=T; t++) {
        int flag[16];
        for (int i=0;i<16;i++) flag[i] = 1;
        int r, a, b, c, d;

        cin >>r;
        for (int i=1;i<=4;i++) {
            cin >>a >>b >>c >>d;
            if (i != r) {
                flag[a-1] = 0;
                flag[b-1] = 0;
                flag[c-1] = 0;
                flag[d-1] = 0;
            }
        }

        cin >>r;
        for (int i=1;i<=4;i++) {
            cin >>a >>b >>c >>d;
            if (i != r) {
                flag[a-1] = 0;
                flag[b-1] = 0;
                flag[c-1] = 0;
                flag[d-1] = 0;
            }
        }

        int sum = 0;
        int ans = 0;
        for (int i=0;i<16;i++) {
            sum += flag[i];
            if (flag[i] == 1) {
                ans = i+1;
            }
        }
        if (sum == 0) {
            cout <<"Case #" <<t <<": " <<"Volunteer cheated!" <<endl;
        }
        else if (sum == 1) {
            cout <<"Case #" <<t <<": " <<ans <<endl;
        }
        else {
            cout <<"Case #" <<t <<": " <<"Bad magician!" <<endl;
        }

    }
    return 0;
}
