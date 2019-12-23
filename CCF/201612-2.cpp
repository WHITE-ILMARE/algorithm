#include <iostream>
#include <map>

using namespace std;

map<int, int> taxes = {{0, 1455}, {1500, 4155}, {4500, 7755}, {9000, 27255}, {35000, 41255}, {55000, 57505}, {80000, 100001}};
const float rs[7] = {0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45};

int main() {
//	cout << 1500 * 0.97 + 3000 * 0.9 + 4500 * 0.8 + 26000 * 0.75 + 20000 * 0.7 + 25000 * 0.65 << endl;
//	cout << 3500 + 10.31 * (1 - 0.03);
	int t, ratio = 0, bf = 0;
	cin >> t;
	if (t <= 3500) {
		cout << t << endl; 
		return 0;	
	}
	t -= 3500;
	for (map<int, int>::iterator iter = taxes.begin(); iter != taxes.end(); ++iter) {
		if (iter->second <= t) {
			++ratio;
		}
		else {
			const int basis = iter->first;
//			(result - basis) * (1 - ratio) + be->second = t
			if (ratio == 0) {
				// result * (1 - ratio) = t
				cout << t / (1 - rs[ratio]) + 3500 << endl;
				return 0;
			} else {
				--iter;
//				cout << "ratio=" <<  rs[ratio] << ",iter->second=" << iter->second << ", basis=" << basis << endl;
				int result = (t - iter->second) / (1 - rs[ratio]) + basis;
				cout << result + 3500 << endl;
				return 0;
			}
			
		}
	}
}
