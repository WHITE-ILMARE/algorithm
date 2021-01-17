#include <iostream>
#include <map>
using namespace std;

map<int,int> n1;
int main() {
    ios::sync_with_stdio(false);
    int n, a, b, ind, val;
    cin >> n >> a >> b;
    for (int i=0;i<a;++i) {
        cin >> ind >> val;
        n1.insert(pair<int,int>(ind, val));
    }
    long long result = 0;
    for (int i=0;i<b;++i) {
        cin >> ind >> val;
        result += n1[ind]*val;
    }
    cout << result << endl;
    return 0;
}
