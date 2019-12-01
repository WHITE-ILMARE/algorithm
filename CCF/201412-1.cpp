#include <iostream>
#include <map>

using namespace std;

int main() {
	int n,val;
	cin >> n;
	int result[n];
	map<int,int> m;
	for (int i=0;i<n;i++) {
		cin >> val;
		if (m.count(val) == 0) 
		m[val] = 1;
		else m[val] += 1;
		result[i] = m[val];
	}
	for (int i=0;i<n;i++) cout << result[i] << ' ';
	cout << endl;
}
