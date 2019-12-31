#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 字符串由空格分隔， 第一个字符串忽略
// 选项：带参数或不带参数
// 不带参数： -a
// 带参数： -a a-1
vector<char> p;
vector<char> np;
vector<string> strs;
map<string, string> result;

int main() {
	string s;
	cin >> s;
	for(string::iterator it = s.begin(); it != s.end(); ++it) {
		if (*it != ':') np.push_back(*it);
		else if (*it == ':') {
			p.push_back(np.back());
			np.pop_back();
		}
	}
	// p中存储带参选项，np中存储不带参选项 
	int n, spos = -1;
	string temp;
	cin >> n;
	cin.ignore(); 
	for (int i=0;i<n;++i) {
		getline(cin, s);
		spos = s.find(' ');
		while(spos != string::npos) {
			temp = s.substr(0, spos);
			s = s.substr(spos+1);
			strs.push_back(temp);
			spos = s.find(' ');
		}
		if (s.length() > 0) strs.push_back(s);
		strs.erase(strs.begin());
		// 已经将输入分隔进strs中
		for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
			for (vector<char>::iterator cit = p.begin(); cit != p.end(); ++cit) {
				if ((*it)[1] == *cit) {
					result.
				}
			}
		}
	}
		
}
 
