#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2002;

struct Teacher { // 包含了教师与钥匙交互的所有信息，将所有操作放在一个数组中，按优先级排序 
	int key, time, op; // op: 1是还，2是取 
	bool operator<(const Teacher& t) {
		if (time == t.time) {
			if (op == t.op) {
				return key < t.key;
			}
			return op < t.op;
		}
		return time < t.time;
	}
}teachers[N];

int main () {
	ios::sync_with_stdio(false);
	int n,k,cost;
	cin >> n >> k;
	int keys[n];
	for (int i=0;i<n;++i) keys[i] = i + 1;
	for (int i=0;i<2*k;++i) {
		cin >> teachers[i].key >> teachers[i].time >> cost;
		teachers[i].op = 2;
		++i;
		teachers[i].key = teachers[i-1].key;
		teachers[i].time = teachers[i-1].time + cost;
		teachers[i].op = 1;
	}
	sort(teachers, teachers+2*k);
	for (int i=0;i<2*k;++i) {
//		cout << "No." << i << ": time= "<<teachers[i].time<<",op="<<teachers[i].op<<",key="<<teachers[i].key<<endl;
		if (teachers[i].op == 2) {
			for (int j=0;j<n;++j) {
				if (keys[j] == teachers[i].key)  {
					keys[j] = 0;
					break;	
				}
			}
		} else {
			for (int j=0;j<n;++j) {
				if (keys[j] == 0) {
					keys[j] = teachers[i].key;
					break;
				}
			}
		}
//		for (int j=0;j<n;++j) cout << keys[j] << ' ';
//		cout << endl;
	}
	for (int i=0;i<n;++i) cout << keys[i] << ' ';
	
}
