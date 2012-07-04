#include <iostream>
using namespace std;

int main() {
    int x, t, a, b, da, db;
    cin >>x >>t >>a >>b >>da >>db;
    bool yes = false;

    if (x == 0) yes = true;
    if ((a-x)%da == 0 and 0 <= (a-x)/da and (a-x)/da < t) yes = true;
    if ((b-x)%db == 0 and 0 <= (b-x)/db and (b-x)/db < t) yes = true;
    do {
        int c  = a + b - x;
        if (c < 0) break;
        int ta = c/da;
        int d  = c%da;
        while (0<=ta) {
            if (d%db==0 and 0<=d/db and d/db<t and ta<t) yes = true;
            ta--;
            d+=da;
        }
    } while (0);

    if (yes) cout <<"YES" <<endl;
    else     cout <<"NO"  <<endl;
    return 0;
}
