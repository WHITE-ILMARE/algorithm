#include <iostream>
#include <string>

using namespace std;

int trans(char c) {
	return c - '0';
}

int main() {
	string isbn;
	cin >> isbn;
	const int result = (trans(isbn[0]) + trans(isbn[2])*2+trans(isbn[3])*3+trans(isbn[4])*4+trans(isbn[6])*5+trans(isbn[7])*6+trans(isbn[8])*7+trans(isbn[9])*8+trans(isbn[10])*9)%11;
	if ( result == trans(isbn[12]) || (result == 10 && isbn[12] == 'X'))
	cout << "Right" << endl;
	else if (result != 10) {
		char st[2];
		sprintf(st, "%d", result);
		cout << isbn.replace(12,1,st) << endl;
	} else {
		cout << isbn.replace(12, 1 , "X") << endl;
	}
}


