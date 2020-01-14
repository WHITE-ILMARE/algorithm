#include <iostream>

using namespace std;

void modify(int a[][2]) {
	a[1][1] = 999;
}

int main () {
	int a[2][2] = {1,2,3,4};
	modify(a);
	cout << a[1][1] << endl;
} 
