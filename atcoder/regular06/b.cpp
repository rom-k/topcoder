#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, L;
    cin >>N >>L;
    cin.ignore();

    string l[L+1];
    for (int i=0;i<L+1;i++) getline(cin, l[i]);
    for (int i=0;i<L+1;i++) l[i] = ' '+l[i]+' ';

    int s;
    for (int i=0;i<N;i++) if (l[L][i*2+1] == 'o') s = i;

    for (int i=L-1;i>=0;i--) {
        if      (l[i][s*2]   == '-') s--;
        else if (l[i][s*2+2] == '-') s++;
    }

    cout <<s+1 <<endl;

    return 0;
}
