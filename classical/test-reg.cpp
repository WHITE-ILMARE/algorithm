#include <regex>
#include <string>
#include <iostream>
using namespace std;

int main() {
//    regex reg("\\{\\{ (\\w{0,15}) \\}\\}");
    regex reg("{{ (.*) }}");
    cmatch sm;
    bool result = regex_match("<p>Email: <a href={{ email }}>{{ email }}</a></p>", sm, reg);
    cout << sm.size() << endl;
    cout << result << endl;
    cout << sm.str(0) << endl;
    cout << sm.str(1) << endl;
    return 0;
}
