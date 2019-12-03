#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, ope, time, sum = 0;
	int lights[3] = {0};
	cin >> lights[0] >> lights[2] >> lights[1];
	cin >> n;
	for (int i=0;i<n;++i) {
		cin >> ope >> time;
		if (ope == 0)
		sum += time;
		else if (ope == 2)
		sum += (time+lights[0]);
		else if (ope == 1)
		sum += time;
	}
	cout << sum;
	return 0;
}
