#include <regex>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string str;
    while(true){
        cin >> str;
        regex e("([[:w:]]+)@([[:w:]]+)\\.com");
        smatch m;
        bool found = regex_search(str, m, e);
        if(found)
        {
            cout << "m.size() " << m.size() << endl;
            for(int i=0; i<m.size(); ++i){
                cout << "m.str(" << i << "): " << m.str(i) << endl;
            }
            cout << "m.prefix().str(): " << m.prefix().str() << endl;
            cout << "m.suffix().str(): " << m.suffix().str() << endl;
        }
        else cout << "Not Found" << endl;
        return 0;
        
        
    }
}
