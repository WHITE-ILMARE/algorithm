#include <iostream>
#include <map>

using namespace std; // 0:��·��1:���, 2:�Ƶ�, 3:�̵� 

int main() {
	ios::sync_with_stdio(false);
	long long r, y, g, n, result, light, time, sum = 0;
	cin >> r >> y >> g;
	sum = r+y+g;
	cin >> n;
	while(n--) {
		cin >> light >> time;
		if (light == 0) {
			result += time;
		} else {
			time = ((time-result)%sum+sum)%sum;
			if (light == 1) {
				
			}
		}
	}
	cout << result;
}
