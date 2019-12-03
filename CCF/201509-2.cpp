#include <iostream>

using namespace std;

int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool isRun(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
	int year, day;
	int month, d = 0;
	cin >> year >> day;
	if (isRun(year)) {
		months[1] = 29;
	}
	while(day > months[month])
	day -= months[month++];
	cout << month + 1 << endl << day;
}
