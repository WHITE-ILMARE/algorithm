#include <regex>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

string h[100];
map<string, string> va;

int main () {
//    ifstream ifs("test.txt");
    int n, v; string name, val;
//    ifs >> n >> v;
    cin >> n >> v;
//	ifs.ignore();
	cin.ignore();
//    cout <<"n="<<n<<" v="<<v<<endl;
    for (int l=0;l<n;++l) {
//        getline(ifs, h[l]);
    	getline(cin, h[l]);
	}
    for (int l=0;l<v;++l) {
        string nv;
//        getline(ifs, nv);
        getline(cin, nv);
        int pos = nv.find(" ");
        int len = nv.length();
        name = nv.substr(0, pos);
        val = nv.substr(pos+2, len - pos -3);
//        cout << name << "=" <<val<<endl;
        string t = "{{ "+name+" }}";
        va[t] = val;
    }
	for (int l=0;l<n;++l) { // replace per line
		int start = h[l].find("{{ ");
		while(start != string::npos) {
			int end = h[l].find(" }}");
			string key = h[l].substr(start, end-start+3);
			h[l].replace(start, end-start+3, va[key]);
			start = h[l].find("{{ ");
		}
	}
    for (int i=0;i<n;++i) {
        cout << h[i] << endl;
    }
}
