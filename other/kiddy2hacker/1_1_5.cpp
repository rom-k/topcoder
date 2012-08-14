#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define REP(i,n) for(int i=0;i<n;i++)
#define REPS(i,s,n) for(int i=s;i<n;i++)
using namespace std;

string code = "ukd odx zvad sa ukd wssemktmh vo f gnsismfuvid qtdouvsr asn csou idnudbnfud lsszspy cfjsno";
int nw;
vector<string> sp;
map<int,vector<string> > miss;

class gsize {
public:
    bool operator()(const string& l, const string& r) const {
        return l.size() > r.size();
    }
};

vector<string> split(const string &str, char delim) {
    istringstream iss(str);
    string tmp;
    vector<string> res;
    while (getline(iss, tmp, delim)) res.push_back(tmp);
    return res;
}

bool assumption(int k, map<char,char> mp) {
    if (nw<=k) {
        REP(i,code.size())
            cout <<(mp[code[i]]!=0 ? mp[code[i]] : code[i]);
        return true;
    }

    map<char,char> cpmp;
    string w = sp[k];
    int n = w.size();
    REP(i,miss[n].size()) {
        string tryw = miss[n][i];

        cpmp.clear();
        for(map<char,char>::iterator it=mp.begin();it!=mp.end();it++)
            cpmp[(*it).first]=(*it).second;

        bool valid = true;
        REP(j,n) {
            if (cpmp.find(   w[j]) == cpmp.end() and
                cpmp.find(tryw[j]) == cpmp.end()) {
                cpmp[   w[j]] = tryw[j];
                cpmp[tryw[j]] =    w[j];
            }
            else if (cpmp[   w[j]] != tryw[j] or
                     cpmp[tryw[j]] !=    w[j]) {
                valid = false;
            }
        }
        if (valid) {
//            cout <<"DEBUG::: [" <<k <<"] (" <<i <<"/"
//                 <<miss[n].size() <<") " <<tryw <<endl;
            if (assumption(k+1, cpmp)) return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    sp = split(code, ' ');
    nw = sp.size();
    sort(sp.begin(), sp.end(), gsize());

    ifstream ifs(argv[1]);
    bool b;
    string s;
    while(ifs >>s) {
        b = true;
        REP(i,s.size()) if(s[i]<'a' or 'z'<s[i]) b = false;
        if (b) miss[s.size()].push_back(s);
    }

    map<char,char> mp;
    if(! assumption(0, mp)) {
        cout <<"error." <<endl;
        return(1);
    }

    cout <<endl;
}
