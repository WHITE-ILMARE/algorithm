#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct auth {
    string name;
    int level;
};
struct role {
    string name;
    vector<auth> auths;
};
struct user {
    string name;
    map<string, int> auths;
};
//int stoi(string n) {
//    int len = n.length(); int result =0;
//    for (int i=0;i<len;++i) result = 10*result+n[i];
//    return result;
//}

int main() {
    int p, r, u, l, q;
//    cintream cin("test.txt");
    string name, a;
    cin >> p;
    for (int i = 0; i < p; ++i) cin >> name;
    cin >> r;
    role roles[r];
    for (int i = 0; i < r; ++i) {
        cin >> name;
        roles[i].name = name;
        cin >> l;
        for (int j = 0; j < l; ++j) {
            cin >> a;
            int pos = a.find(":");
            string ta;
            int level;
            if (pos != string::npos) {
                ta = a.substr(0, pos);
                level = stoi(a.substr(pos + 1));
            } else {
                ta = a;
                level = -1;
            }
            auth tt{ta, level};
            roles[i].auths.push_back(tt);
        }
    }
    cin >> u;
    user users[u];
    for (int i = 0; i < u; ++i) {
        cin >> name;
        users[i].name = name;
        cin >> l;
        for (int j = 0; j < l; ++j) {
            cin >> a;
            for (int k = 0; k < r; ++k) {
                if (roles[k].name == a) {
                    vector<auth> tt = roles[k].auths;
                    for (vector<auth>::iterator it = tt.begin(); it != tt.end(); ++it) {
                        if (users[i].auths[(*it).name] == 0 || users[i].auths[(*it).name] < (*it).level+1) {
                            if ((*it).level != -1) users[i].auths[(*it).name] = (*it).level+1;
                            else users[i].auths[(*it).name] = (*it).level;
                        }
                    }
                    break;
                }
            }
        }
    }
//    for (int i = 0; i < u; ++i) {
//        cout << users[i].name << "|";
//        for (map<string, int>::iterator it = users[i].auths.begin(); it != users[i].auths.end(); ++it) {
//            cout << it->first << "(" << it->second << ")";
//        }
//        cout << endl;
//    }
    cin >> q;
    for(int i=0;i<q;++i) {
        cin >> name >> a;
        user us; map<string, int>au = us.auths;
        for (int k=0;k<u;++k) {
            if (users[k].name == name) {
                us = users[k];
                break;
            }
        }
        int pos = a.find(":");
        if (pos == string::npos) {
//            cout << "pos="<<pos <<",us.auths["<<a<<"]="<<us.auths[a]<<endl;
            if (us.auths[a]==-1) cout << "true" << endl;
            else if (us.auths[a]>0) cout << us.auths[a]-1 << endl;
            else cout << "false" << endl;
        } else {
            string qname=a.substr(0,pos);
            int ql = stoi(a.substr(pos+1));
            if (us.auths[qname]>0 && us.auths[qname]>ql) cout << "true" << endl;
            else cout << "false" << endl;
        }
    }
    return 0;
}