#include <iostream>

using namespace std;

int main() {
	int n,result=0;
	cin >> n;
	int b = n / 10;
	result += (b/5)*7;
	b = b%5;
	result += (b/3)*4;
	b=b%3;
	result += b;
	cout << result;
}
