#include <iostream>
using namespace std;

main () {
    int mem = 0;
    int sum = 0;
    string s;

    while(getline(cin, s)){
//        cout <<"DEBUG::: " <<buf <<endl;
        if (s[0] == '+') mem++;
        else if (s[0] == '-') mem--;
        else {
//            cout <<"DEBUG:::  j-i-1=" <<j-i-1 <<endl;
//            cout <<"DEBUG:::  num  =" <<user.size() <<endl;
            sum += mem * (s.length() - s.find(":") - 1);
        }
    }

    cout <<sum <<endl;
    return 0;
}
