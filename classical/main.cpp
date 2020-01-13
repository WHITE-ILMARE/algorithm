#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

string h[100];
map<string, string> va;
vector<int> poses;

int main () {
    ifstream ifs("test.txt");
    int n, v; string name, val;
    ifs >> n >> v;
    ifs.ignore();
//    cout <<"n="<<n<<" v="<<v<<endl;
    regex reg("\\{\\{ (\\D\\w{0,15}) \\}\\}");
    for (int l=0;l<n;++l) {
        getline(ifs, h[l]);
    }
    for (int l=0;l<v;++l) {
        string nv;
        getline(ifs, nv);
        int pos = nv.find(" ");
        int len = nv.length();
        name = nv.substr(0, pos);
        val = nv.substr(pos+1, len - pos -2);
//        cout << name << "=" <<val<<endl;
        string t = "{{ "+name+" }}";
        len = val.length();
        string value = val.substr(1, len-1);
        va[t] = value;
    }
    for (int i=0;i<n;++i) {
        smatch m;
        regex_match(h[i], m, reg);
        cout << "h[" << i<<"]="<<h[i] <<endl;
        cout << "m.size()=" << m.size() <<endl;
        for (int l=0;l<m.size();++l) {
            cout << m.str(l) << endl;
        }
    }
//    for (int i=0;i<n;++i) {
//        cout << h[i] << endl;
//    }
}
