#include <regex>
#include <string>
#include <iostream>
using namespace std;

int main() {
//    regex reg("\\{\\{ (\\w{0,15}) \\}\\}");
    regex reg("{{(.*)}}");
    cmatch sm;
    bool result = regex_match("<p>Email: <a href='mailto:{{ email }}''>{{ email }}</a></p>", sm, reg);
    cout << sm.size() << endl;
    cout << result << endl;
    for (int i=0;i<sm.size();++i) {
    	cout << sm.str(i) << endl;
	}
    return 0;
}
