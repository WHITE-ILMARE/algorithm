#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, result=0;
	cin >> n;
	int a[n];
	for (int i=0;i<n;++i) {
		cin >> a[i];
		if (i > 0) {
			result = fmax(result, abs(a[i] - a[i-1]));
		}	
	}
	cout << result << endl;
	return 0;
}
