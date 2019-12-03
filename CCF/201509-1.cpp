#include <iostream>

using namespace std;

const int N = 1000;
int a[N];

int main() {
	int n;
	int result = 0;
	int temp = -1;
	cin >> n;
	for (int i=0;i<n;++i) {
		cin >> a[i];
		if (a[i] != temp) {
			++result;
			temp = a[i];
		}
	}
	cout << result;
	return 0;
} 
