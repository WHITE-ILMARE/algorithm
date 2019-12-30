#include <iostream>
using namespace std;

int main () {
	int i=12;
	int j = 0; 
	printf("0x%.6p\n", &i);
	printf("0x%.6p\n", &j);
	int arr[2] = {0};
	cout << &arr << " " <<  &arr[1] << " " << &arr[2] << " " << &arr[3] << endl;
//	for(;i<=3;++i) {
//		arr[i] = 0;
//		printf("hello world\n");
//	}
	return 0;
}
