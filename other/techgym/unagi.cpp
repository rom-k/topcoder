#include <iostream>
#include <set>
using namespace std;
typedef pair<int,char> PIC;

int x[7];

bool dfs(int y) {
    if (7 <= y)    return true;
    if (0 <= x[y]) return dfs(y+1);

    for (int x1=0;x1<7;x1++) {

        bool valid = true;
        for (int y2=0;y2<7;y2++) {
            int x2 = x[y2];
            if (x2 < 0) continue;
            if (x1    == x2   or
                x1-x2 == y-y2 or
                x2-x1 == y-y2 ) valid = false;
        }

        if (valid) {
            x[y] = x1;
            if (dfs(y+1)) return true;
            x[y] = -1;
        }
    }
    return false;
}

int main() {
    string board[] = {
        "lhikoav",
        "rqsczlp",
        "uwalnfo",
        "tykajeh",
        "ahitsyd",
        "efoptxn",
        "ruzwyve"
    };

    for (int i=0;i<7;i++) x[i] = -1;
    x[2] = 2;
    x[4] = 3;

    if (!dfs(0)) {
        cout <<"no answer." <<endl;
        return 0;
    }

    set<PIC> ans;
    int sumprod = 0;
    for (int i=0;i<7;i++) {
        ans.insert(PIC((i+1)*(x[i]+1),board[i][x[i]]));
        sumprod += (i+1)*(x[i]+1);
    }
    for (set<PIC>::iterator it=ans.begin();it!=ans.end();it++) {
        cout <<(*it).second;
    }
    cout <<"-" <<sumprod <<endl;

    return 0;
}
