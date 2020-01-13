#include <regex>
#include <string>
#include <iostream>
using namespace std;

int main() {
//    regex reg("\\{\\{ (\\w{0,15}) \\}\\}");
    regex reg("([[:w:]]+)");
    cmatch sm;
    bool result = regex_match("<p>Email: <a href='mailto:{{ email }}''>{{ email }}</a></p>", sm, reg);
    cout << sm.size() << endl;
    cout << result << endl;
    cout << sm.str(0) << endl;
    return 0;
}
