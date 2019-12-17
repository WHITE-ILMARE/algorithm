#include <iostream>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> se;
	int a[n], s=0,b=0,flag=0;
	for (int i=0;i<n;++i) cin >> a[i];
	for (int i=0;i<n;++i) {
		for (int j=0;j<n;++j) {
			if (a[j]<a[i]) ++s;
			else if (a[j]>a[i]) ++b;
		}
		if (b==s) {
			se.insert(a[i]);
			flag = 1;
		}
		b= s=0;
	}
	if (flag==0) cout << -1;
	else
	for (set<int>::iterator iter = se.begin();iter!=se.end();++iter)
	cout << *iter << ' ';
	return 0;
}
