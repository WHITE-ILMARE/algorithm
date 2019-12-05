#include <iostream>
#include <map>

using namespace std; // 0:µÀÂ·£¬1:ºìµÆ, 2:»ÆµÆ, 3:ÂÌµÆ 

int lights[4];

struct status {
	int light;
	int time;
};

struct status transfer(int light, int time, int accumulate) {
	time = accumulate - time;
	if (light == 1) light = 3;
	else if (light == 2) light = 1;
	else if (light == 3) light = 2;	
	while(time >= lights[light]) {
		time -= lights[light];
		if (light == 1) light = 3;
		else if (light == 2) light = 1;
		else if (light == 3) light = 2;	
	}
	time = lights[light] - time;
	struct status s = {light, time};
	return s;
}

int main() {
	cin >> lights[1] >> lights[2] >> lights[3];
	int n, result, light, time = 0;
	cin >> n;
	for (int i=0;i<n;++i) {
		cin >> light >> time;
//		cout << "light=" <<light << " time=" << time << endl;
		if (light == 0) {
			result += time;
		} else {
			struct status s = transfer(light, time, result);
//			cout << "---trans---light="<<s.light<<" time="<<s.time<<endl;
			if (s.light == 1) {
				result += s.time;
			} else if (s.light == 2) {
				result += (lights[1] + s.time);
			}
		}
//		cout << "result = " << result << endl;
	}
	cout << result;
}
