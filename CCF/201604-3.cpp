#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

stack<string> path_s;
queue<string> path_q;

vector<string> divide(string s) { // divide string with '/', return the result array
	int start = 0, end = s.find("/", start+1);
	vector<string> result; 
	while(start != string::npos) {
//		cout << "start = "<<start<<",end = "<<end<<endl;
		if (end == string::npos) { // at the end of process
			if (s[start] == '/')
				result.push_back(s.substr(start+1));
			else result.push_back(s.substr(start));
			break;
		} else {
			if (s[start] == '/') result.push_back(s.substr(start+1, end-start-1));
			else result.push_back(s.substr(start, end-start)); // include start, length+1
//			cout << "in else, start = " << start << endl;
		}
		start = end;
		end = s.find("/", start+1);
	}
	return result;
}

int main() {
	string pwd, i;
	cin >> pwd;
	vector<string> init = divide(pwd); // (.),(..),(),(dir/file)
	cin >> i;
	if (i[0] == '/') {
		
	}
	else flag = 0; // relative path
	for (vector<string>::iterator it=r.begin();it!=r.end();++it) {
		cout <<"deal with: " *it << endl;
		if (*it==".") {
			
		}
	}
	return 0;
} 
