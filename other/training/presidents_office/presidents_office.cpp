#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    char c;
    cin >>n >>m >>c;

    string map[n];
    for(int i=0; i<n; i++) cin >>map[i];
    //for(int i=0; i<n; i++) cout <<"DEBUG::: " <<map[i] <<endl;

    set<char> tonari;
    tonari.insert('.');
    tonari.insert(c);

    int dx[] = { 0,-1, 0, 1};
    int dy[] = {-1, 0, 1, 0};
    for(int y=0; y<n; y++) for(int x=0; x<m; x++) {
        if (map[y][x] != c) continue;
        for(int k=0; k<4; k++) {
            if(y+dy[k] < 0 or n-1 < y+dy[k]
            or x+dx[k] < 0 or m-1 < x+dx[k]) continue;
            tonari.insert(map[y+dy[k]][x+dx[k]]);
        }
    }

    cout <<tonari.size()-2 <<endl;
    return 0;
}
