#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	int result = 0;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++){
			if (a[i] - a[j] == 1 || a[i] - a[j] == -1) ++result;
		}
	}
	cout << result << endl;
} 
