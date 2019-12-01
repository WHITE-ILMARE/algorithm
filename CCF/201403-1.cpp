#include <iostream>
#include <map>

using namespace std;

int main() {
	int n, input;
	int result = 0;
	map<int,int> m;
	cin >> n;
	for (int i=0;i<n;i++) {
		cin >> input;
		if (m[-input] == 1) result++;
		else m[input] = 1;
	}
	cout << result << endl;
}
