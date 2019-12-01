#include <iostream>
#include <map>

using namespace std;

int main() {
	map<int,int>m;
	m[1]=5;
	m[3]=2;
	int n;
	while(cin >> n) {
		cout << "m[" << n << "]=" << m[n] << endl;
	}
}
