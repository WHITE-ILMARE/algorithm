#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s, in;
    vector<string> result;
    cin >> s;
    int i, n, flag = 1, len = s.length();
    cin >> i >> n;
    for (int j = 0; j<n;++j) {
        cin >> in;
        const int ilen = in.length();
        for (int k = 0;k<=ilen-len;++k) {
            flag = 1;
            for(int p=0;p<len;++p) {
                // cout << "k="<<k<<"in[k]="<<in[k]<<", p="<<p<<"s[p]="<<s[p]<<endl;
                if (i == 1 && in[k] != s[p]) {
                    flag = 0;
                    break;
                } else if (i == 0 && in[k] != s[p] && in[k] - s[p] != 32 && in[k]-s[p] != -32) {
                    flag = 0;
                    break;
                }
                ++k;
            }
            if (flag == 1) {
                // cout << "push" << endl;
                result.push_back(in);
                break;
            }
        }
    }
    for (vector<string>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}