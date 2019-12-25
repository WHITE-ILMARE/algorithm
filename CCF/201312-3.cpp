#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, s;
	long long result = 0;
	long long temp = 0;
	cin >> n;
	int a[n];
	for (int i=0;i<n;++i) cin >> a[i];
	for (int i=0;i<n;++i) { // use a[i] as the start point
		s = a[i];
		for (int j=i;j<n;++j) {
//			for (int k=i+1;k<=j;++k) {
//				if (a[k] < s) s = a[k];
//			}
			// 优化一下，不用多遍历一次找最小值 
			if (a[j] < s) s = a[j];
			long long t = (j - i + 1) * s;
//			cout << "start_i = " << i << ", end_i = " << j << ", s = " << s << endl;
			if (result < t) {
				result = t;
//				cout << "start = " << a[i] << ", end = " << a[j] << ", result = " << result << endl;	
			}
		}
	}
	cout << result << endl;
}
