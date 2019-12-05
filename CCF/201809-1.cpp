#include <iostream>

using namespace std;
const int N = 1000;
int a[N];

int main() {
	int n;
	cin >> n;
	for (int i=0;i<n;++i) cin >> a[i];
	cout << (a[0]+a[1])/2 << ' ';
	for (int i=1;i<n-1;++i) cout << (a[i-1]+a[i]+a[i+1])/3 << ' ';
	cout << (a[n-2]+a[n-1])/2 << endl;
}
