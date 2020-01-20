#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main () {
	ifstream ifs("201703-3(input).txt");
	string line, result; int in_list = 0, pos, start;
	while(getline(ifs, line)) {
		int len = line.length();
		if (len == 0) // empty line
			continue;
		if (line[0] == '#') { // title
			pos = line.find(' '); start = -1;
			for (int i=pos;i<len;++i)
				if (line[i] != ' ' && line[i] != '#') {
					start = i;
					break;
				}
			result.append("<h"+to_string(pos)+">"+line.substr(start)+"</h"+to_string(pos)+"/>\n");
		}
		else if (line[0] == '*') { // unordered list
			pos = line.find(' '); start = -1;
			for (int i=pos;i<len;++i)
				if (line[i] != ' ') {
					start = i;
					break;
				}
			if (in_list == 0) {
				in_list = 1;
				result.append("<ul><li>"+line.substr(start)+"</li></ul>\n");
			}
		}
		cout << result;
	}
} 
