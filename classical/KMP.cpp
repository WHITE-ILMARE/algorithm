#include <iostream>
#include <string>

using namespace std;

void getNext(int next[], string a) {
    const int len = a.length();
    next[0] = -1;
    int k = -1, j = 0;
    while(j < len - 1) {
//        cout << "k=" << k << " a[k]=" << a[k] << " a[j]=" << a[j] << endl;
        if (k == -1 || a[k] == a[j]) {
            ++k; ++j;
//            cout << "next[" << j << "]=" << k << endl;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int main() {
    string s, p;
    int n;
    cin >> p >> n;
    for (int i=0;i<n;++i) {
    	cin >> s;
    	int len = s.length();
    	int lenp = p.length();
    	int next[lenp];
    	getNext(next, p);
    	int k = 0, j=0;
    	while(j < len && k < lenp) {
    		if (k == -1 || s[j] == p[k]) {
    			++j; ++k;
			} else {
				k = next[k];
			}
		}
		if (k == lenp) {
			cout << "found at: " << j -k << endl;
		} else {
			cout << "not found" << endl;
		}
	}
    return 0;
}
