#include <iostream>
#include <fstream>
#include <map>

using namespace std;

string h[100];
map<string, string> va;

int main () {
    ifstream  ifs("test.txt");
    int n, v; string name, val;
    ifs >> n >> v;
    ifs.ignore();
    cout <<"n="<<n<<" v="<<v<<endl;
    for (int l=0;l<n;++l) {
        getline(ifs, h[l]);
        cout << h[l] << endl;
    }
    for (int l=0;l<v;++l) {
        ifs >> name >> val;
        cout << name << "=" <<val<<endl;
        string t = "{{ "+name+" }}";
        int len = val.length();
        string value = val.substr(1, len-1);
        va[t] = value;
    }
//    for (map<string, string>::iterator it=va.begin();it != va.end();++it) cout << it->first<<"="<<it->second<<endl;
}