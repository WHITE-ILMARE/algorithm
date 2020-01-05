#include <iostream>

using namespace std;

void getNext(int next[], string a) {
    const int len = a.length();
    next[0] = -1;
    int k = -1, j = 0;
    while(j < len) {
        cout << "k=" << k << " a[k]=" << a[k] << " a[j]=" << a[j] << endl;
        if (k == -1 || a[k] == a[j]) {
            ++k; ++j;
            cout << "next[" << j << "]=" << k << endl;
            next[j] = k;
        } else {
            k = next[k];
        }
    }
}

int main() {
    int next[10];
    getNext(next, "ABCIJABABC");
    for (int i=0;i<10;++i) cout <<  next[i] << ' ';
    return 0;
}