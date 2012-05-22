#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >>T;
    cin.ignore();
    for (int t=1;t<=T;t++) {
        int N;
        cin >>N;
        vector<int> m(N,0);
        for (int i=0;i<N;i++) cin >>m[i];

        int total = 0;
        for (int i=0;i<N;i++) total += m[i];

        vector<int> m2(N,0);
        copy(m.begin(),m.end(),m2.begin());
        sort(m2.begin(),m2.end());

        int sum = total;
        double threshold = 2 * (double)sum / N;
        for (int i=0;i<N;i++) {
            if (0 < i and sum < m2[i] * i) {
                threshold = (double)sum / i;
                break;
            }
            sum += m2[i];
        }

//        cout <<"DEBUG::: " <<threshold <<endl;
        cout <<"Case #" <<t <<":";
        for (int i=0;i<N;i++)
            printf(" %0.9lf",
                (m[i] < threshold) ? (threshold - m[i]) / total * 100 : 0
            );
        cout <<endl;
    }
    return 0;
} 
