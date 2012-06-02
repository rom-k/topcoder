#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    cin >>n;
    vector<string> vs(n,"");
    for (int i=0;i<n;i++) cin >>vs[i];

    set<string> ss;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i != j)
                ss.insert(vs[i] + vs[j]);

    set<string>::iterator it = ss.begin();
    cout <<*it <<endl;
    return 0;
}
