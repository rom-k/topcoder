#include "grader.h"
#include <iostream>
using namespace std;
#define MAX 1000005

void _send(int n) {
    while(n) {
        send(n%2);
        n/=2;
    }
}

void taro(int N) {
    int num = 0;
    int a[MAX];
    for(int i=0;i<MAX;i++) a[i]=0;
    for(int i=2;i<MAX;i++) {
        if (N <= i) return;
        if (a[i] != 0) continue;
        num++;
//        cout <<" (" <<num <<"," <<i <<")" <<endl;

        if (N%i == 0) {
//            cout <<"num=" <<num <<endl;
            _send(num);
            return;
        }

        int i2=i;
        while(i2 < MAX) {
            a[i2]=1;
            i2+=i;
        }
    }
}

int jiro(int S, int X[]) {
    if (S==0) return -1;

    int n = 0;
    int ni = 1;
    for(int i=0;i<S;i++) {
        n += X[i]*ni;
        ni *= 2;
    }
//    cout <<"n  =" <<n <<endl;

    int num = 0;
    int a[MAX];
    for(int i=0;i<MAX;i++) a[i]=0;
    for(int i=2;i<MAX;i++) {
        if (a[i] != 0) continue;
        num++;
//        cout <<" (" <<num <<"," <<i <<")" <<endl;

        if (num == n) {
            return i;
        }

        int i2=i;
        while(i2 < MAX) {
            a[i2]=1;
            i2+=i;
        }
    }
}

