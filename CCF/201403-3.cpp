#include <iostream>
#include <string>
#include <vector>

using namespace std;
// �ַ����ɿո�ָ��� ��һ���ַ�������
// ѡ��������򲻴�����
// ���������� -a
// �������� -a a-1
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
	// p�д洢����ѡ�np�д洢������ѡ�� 
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
		// �Ѿ�������ָ���strs��
		for (vector<string>::iterator it = strs.begin(); it != strs.end(); ++it) {
			for (vector<char>::iterator cit = p.begin(); cit != p.end(); ++cit) {
				if ((*it)[1] == *cit) {
					result.
				}
			}
		}
	}
		
}
 
