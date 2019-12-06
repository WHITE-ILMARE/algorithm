#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1000;
int a[N];

int main() {
	int n,result=0;
	cin >> n;
	for (int i=0;i<n;++i) cin>>a[i];
	sort(a,a+n);
	result = a[1] - a[0];
	for (int i=2;i<n;++i) {
		if (a[i]-a[i-1]<result) result = a[i]-a[i-1];
	}
	cout << result;
	return 0;
}
