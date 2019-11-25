#include <iostream>
#include <map>


using namespace std;

int main() {
	int n, result, max;
	cin >> n;
	int a[n];
	map <int, int> m;
	for (int i=0;i<n;i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	map<int, int>::iterator iter;
	iter = m.begin();
	max = iter->second;
	result = iter->first;
	while(iter != m.end()) {
		if(iter->second > max) {
			result = iter->first;
			max = iter->second;
		}
		iter++;	
	}
	printf("%d\n", result);
}
