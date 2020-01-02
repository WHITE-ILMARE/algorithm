#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
vector<char> p;
vector<char> np;
vector<string> strs;
map<string, string> result;

int main() {
	string s;
	cin >> s;
	// 区别带参选项和不带参选项
	for(string::iterator it = s.begin(); it != s.end(); ++it) {
		if (*it != ':') np.push_back(*it);
		else if (*it == ':') {
			p.push_back(np.back());
			np.pop_back();
		}
	} 
	int n, spos = -1;
	string temp;
	cin >> n;
	// 清除缓存区中的换行符
	cin.ignore(); 
	for (int i=0;i<n;++i) {
		// 清空上一次的结果
		result.clear();
		strs.clear();
		//cout << "---------result.clear()----------------" << endl;
		//for(map<string, string>::iterator it = result.begin(); it != result.end(); ++it) {
		//	cout << it->first << '=' << it->second << ";";
		//}
		//cout << "---------result.clear()----------------" << endl;
		getline(cin, s);
		//cout << "s=" << s <<endl;
		spos = s.find(' ');
		// 按空格分割字符串
		while(spos != string::npos) {
			temp = s.substr(0, spos);
			s = s.substr(spos+1);
			strs.push_back(temp);
			spos = s.find(' ');
		}
		if (s.length() > 0) strs.push_back(s);
		strs.erase(strs.begin());
		int flag = 0;
		// 匹配
		for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
			flag = 0;
			string s1 = *it;
			if (s1[0] != '-' || s1.length() != 2) break;
			for (vector<char>::iterator cit = p.begin(); cit != p.end(); ++cit) {
				if ((*it)[1] == *cit) {
					const string key = (*it);
					++it;
					if (it == strs.end()) break;
					// cout << "insert into result, key=" << key << ", value="<<*it<<endl;
					map<string, string>::iterator temp = result.find(key);
					if (temp != result.end())
						temp->second = *it;
					else
					result.insert(pair<string, string>(key, *it));
					flag = 1;
					break;	
				}
			}
			if (flag == 1) continue;
			for (vector<char>::iterator cit = np.begin(); cit != np.end(); ++cit) {
				if ((*it)[1] == *cit) {
					result.insert(pair<string, string>(*it, ""));
					flag = 1;
					break;	
				}
			}
			if (flag == 0) break;
		}
		cout << "Case " << i+1 << ": ";
		for(map<string, string>::iterator it = result.begin(); it != result.end(); ++it) {
			cout << it->first << " ";
			if (it->second != "")
			cout << it->second << " ";
		}
		cout << endl;
	}
		
}
 
