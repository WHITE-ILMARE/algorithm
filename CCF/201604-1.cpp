#include <iostream>

using namespace std;

const int N = 1000;
int a[N];

int main() {
	int n;
	bool trend;
	int result = 0;
	cin >> n;
	if (n <= 2) {
		for (int i=0;i<n;i++) cin >> a[i];
		cout << 0;
		return 0;
	}
	for (int i=0;i<n;++i) {
		cin >> a[i];
		if (i==1) {
			trend = (a[i] - a[i-1] > 0);
		} else if (i > 1 && trend != (a[i] - a[i-1] > 0)) {
			++result;
			trend = (a[i] - a[i-1] > 0);
		}
	}
	cout << result;
	return 0;
}
