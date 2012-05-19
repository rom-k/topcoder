#include <iostream>
#include <string>
using namespace std;

int main()
{
    int member = 0;
    int ret = 0;
    string s;
    while (getline(cin, s))
    {
        if (s[0] == '+') member++;
        else if (s[0] == '-') member--;
        else
        {
            ret += member * (s.length() - s.find(":") - 1);
        }
        
    }
    cout << ret << endl;
    return 0;
}
