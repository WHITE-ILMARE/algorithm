#include <iostream>

using namespace std;

int main(){
	int n,count=0,bef=-1,result=0;
	while(cin >> n) {
		if(n==0){
			cout <<result<<endl;
			return 0;
		}
		if (count==0) {
			result+=n;	
			bef = n;
			cout << n << ' ' << bef << ' ' << result << endl;
		}
		else {
			if (n==2) {
				if (bef==1) {
					result+=2;	
					bef = 2;
					cout << n << ' ' << bef << ' ' << result << endl;
				}
				else {
					bef+=2;
					result+=bef;
					cout << n << ' ' << bef << ' ' << result << endl;
				}
			} else {
				bef = 1;
				result+=bef;
				cout << n << ' ' << bef << ' ' << result << endl;
			}
		}
		count++;
	}
}
