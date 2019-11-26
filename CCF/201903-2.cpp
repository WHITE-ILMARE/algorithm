#include <iostream>
#include <queue>
#include <map>
#include <stack>

using namespace std;

map<char, int> ope;
queue<int> nums;
stack<char> opes; 


int prio(char bef, char aft) {
	if (ope[bef] > ope[aft]) {
		return 1;
	}
	return -1;
}

int main() {
	ope['+'] = 1;
	ope['-'] = 1;
	ope['x'] = 2;
	ope['/'] = 2;
	int n, num,cr;
	char op, bef;
	string exp;
	cin >> n;
	for (int i=0;i<n;i++) {
		cin>>exp;
		nums.push(exp[0]-'0');
		opes.push(exp[1]);
		nums.push(exp[2]-'0');
		bef = opes.top();
		if (prio(exp[3],bef) == 1) {
			opes.push(exp[3]);
		} else {
			nums.push(bef);
			opes.pop();
			opes.push(exp[3]);
		}
		nums.push(exp[4]-'0');
		while(opes.size() > 0){
			bef=opes.top();
			if(prio(bef,exp[5]) == 1) {
				nums.push(bef);
				opes.pop();
			}
		}
		opes.push(exp[5]);
		nums.push(exp[6]-'0');
		nums.push(opes.top());
		opes.pop();
		while(nums.size() > 0) {
			cout << nums.front() << "->";
			nums.pop();
		}
	}
}
