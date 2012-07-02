#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define max_N 25
#define INF 0x7f7f7f7f

int _time2min(string t) {
    return (t[0]-'0') * 600
         + (t[1]-'0') * 60
         + (t[3]-'0') * 10
         + (t[4]-'0');
}

int main() {
    int N, nc;
    string cityA, cityB, timeB, hour[24];
    string city1[max_N], city2[max_N], time1[max_N], time2[max_N];
    int diff[max_N][max_N];

    /* init */
    for (int i=0;i<max_N;i++)
        for (int j=0;j<max_N;j++)
            diff[i][j] = INF;

    /* input */
    cin >>cityA;
    for (int i=0;i<24;i++) cin >>hour[i];
    cin >>N;
    for (int i=0;i<N;i++) cin >>city1[i] >>time1[i] >>city2[i] >>time2[i];
    cin >>cityB;
    cin >>timeB;

    /* create uniq sorted vector */
    vector<string> cities;
    cities.push_back(cityA);
    cities.push_back(cityB);
    for (int i=0;i<N;i++) {
        cities.push_back(city1[i]);
        cities.push_back(city2[i]);
    }
    sort(cities.begin(), cities.end());
    vector<string>::iterator it = unique(cities.begin(),cities.end());
    cities.erase(it, cities.end());

    /* num of cities */
    nc = cities.size();

    /* map from cityname to cityindex */
    map<string,int> mp;
    for (int i=0;i<nc;i++) mp[cities[i]] = i;

    /* timezone difference between two cities */
    for (int i=0;i<nc;i++)
        diff[i][i] = 0;
    for (int i=0;i<N;i++) {
        int t1 = _time2min(time1[i]);
        int t2 = _time2min(time2[i]);
        diff[mp[city1[i]]][mp[city2[i]]] = t1 - t2;
        diff[mp[city2[i]]][mp[city1[i]]] = t2 - t1;
    }

    /* warshall-floyd ? */
    for (int i=0;i<nc;i++)
        for (int j=0;j<nc;j++)
            for (int k=0;k<nc;k++)
                if (diff[j][i] != INF and diff[i][k] != INF)
                    diff[j][k] = diff[j][i] + diff[i][k];

    /* output */
    int t = _time2min(timeB) + diff[mp[cityA]][mp[cityB]];
    while (t < 0) t += 24 * 60;
    cout <<hour[t / 60 % 24] <<endl;

    return 0;
}
