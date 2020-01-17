#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<string> result;

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
	if (i[0] != '/')
	    for (vector<string>::iterator it=init.begin();it!=init.end();++it)
	        result.push(*it);
	}
	for (vector<string>::iterator it=r.begin();it!=r.end();++it) {
		cout <<"deal with: " *it << endl;
		if ((*it).compare(".")==0||(*it).compare("")==0) {
			continue;
		} else if((*it).compare("..")==0) {
		    result.pop();
		} else result.push((*it));
	}
	string res;
	while(!result.empty()) {

	}
	return 0;
} 
