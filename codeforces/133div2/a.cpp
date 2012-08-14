#include <iostream>
using namespace std;

#define REPS(i,s,n) for(int i=s;i<n;i++)
#define REP(i,n) REPS(i,0,n)

int main() {
    int a, b, c;
    cin >>a >>b >>c;
    cout <<a*b+b*c+c*a-a-b-c+1 <<endl;
    return 0;
}
