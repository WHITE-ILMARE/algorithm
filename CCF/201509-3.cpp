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
	ios::sync_with_stdio(false); 
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
		int start = 0, end = 0;
		while((start = h[l].find("{{ ", start)) != string::npos) {
			if ((end = h[l].find(" }}", start+3)) == string::npos) break;
			string key = h[l].substr(start, end-start+3);
			h[l].replace(start, end-start+3, va[key]);
			start += va[key].length();
			start = h[l].find("{{ ", start); // this is the core to reduce time for finding(90->100)
		}
	}
    for (int i=0;i<n;++i) {
        cout << h[i] << endl;
    }
}
