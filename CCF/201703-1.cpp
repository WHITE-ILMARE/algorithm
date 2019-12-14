#include <iostream>

using namespace std;

int main() {
	int n, k, sum=0, result=0;
	cin >> n >> k;
	int a[n];
	for (int i=0;i<n;++i) {
		cin >> a[i];	
		sum += a[i];
		if (sum >=k) {
			++result;
			sum =0;
		}
	}
	if (sum > 0) ++result;
	cout << result;
	return 0;
}
