#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string text, line, result, temp;

void dealWithInline() {
	int start = -1, end = -1; string str;
	start = text.find('_');
	end = text.find('_', start+1);
	str = text.substr(start+1, end-start-1);
//	cout << "start = " << start << ", end=" << end << ", str=" << str << endl;
	while(start != string::npos) {
		text.replace(start, end-start+1, "<em>"+str+"</em>");
		start = text.find('_');
		end = text.find('_', start+1);
	}
}

void dealWithHyperLink() {
	string subtext, link; int init = -1, start=-1 ,end = -1;
	start = text.find('['); end = text.find(']'); init = start;
	while (start != string::npos && end != string::npos) {
		subtext = text.substr(start+1, end-start-1);
		start = text.find('('); end = text.find(')');
		link = text.substr(start+1, end-start-1);
		text.replace(init, end-init+1, "<a href=\""+link+"\">"+subtext+"</a>");
		start = text.find('['); end = text.find(']'); init = start;
	}
}

int findNoSpace(string *s) {
	int pos = (*s).find(' '), start = -1, len = (*s).length();
	for (int i=pos;i<len;++i) {
		if ((*s)[i] != ' ') {
			start = i;
			break;	
		}
	}
	return start;
}

void solve() {
	if (text[0] == '#') { // title
		int pos = text.find(' ');
		int start = findNoSpace(&text);
		text.erase(text.size()-1);
		result.append("<h"+to_string(pos)+">"+text.substr(start)+"</h"+to_string(pos)+">\n");
	}
	else if (text[0] == '*') { // unordered list
		temp = "<ul>\n"; int nspace, start= 0;
		start = text.find('*', start);
		while(start != string::npos) {
			for (int i=start+1;i<text.size();++i) {
				if (text[i] != ' ') {
					nspace = i;
					break;
				}
			}
			int end = text.find("\n", nspace);
			temp.append("<li>"+text.substr(nspace, end-nspace)+"</li>\n");
			start = text.find('*', end+1);	
		}
		temp.append("</ul>\n");
		result.append(temp);
	}
	else { // multipul-line text
		temp = "<p>";
		dealWithInline();
		dealWithHyperLink();
		text.erase(text.size()-1);
		temp.append(text+"</p>\n");
		result.append(temp);
	}
	text = "";
}

int main () {
	ifstream ifs("201703-3(input).txt");
	int pos, start;
	getline(ifs, line); bool flag = false;
	while(true) {
		if (line.length() == 0 && text.size() > 0) // solve stored text when encounter an empty line 
		{
//			cout << "solve: " << text << endl;
			solve();
		}
		else text += line+"\n";
		if (flag) break;
		if (!getline(ifs, line)) {
			flag = true;
			line = ""; // trigger solve process
		}
	}
	cout << result;
} 
