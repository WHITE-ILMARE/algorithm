#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << a[0] << ' ' << a[0] << ' ' << a[0] << endl;
	} else{
		if(a[0] > a[1]) cout << a[0] << " ";
		else cout << a[n-1] << ' ';
		if (n % 2 == 1) {
			cout << a[n/2] << " ";
		} else if((a[n/2-1]+a[n/2])%2==0) {
			cout << (a[n/2-1]+a[n/2])/2 << ' ';
		} else {
			cout << fixed << setprecision(1) << ((double)a[n/2-1]+a[n/2])/2 << ' ';
		}
		if (a[0] > a[1]) cout << a[n-1] << endl;
		else cout << a[0] << endl;
	} 
}
