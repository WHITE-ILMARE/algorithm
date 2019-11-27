#include <iostream>
#include <queue>
#include <map>
#include <stack>

using namespace std;

map<char, int> ope{{'+', 1},{'-',1},{'x',2},{'/',2}}; // C++11
queue<char> nums;
stack<char> opes; 


int prio(char bef, char aft) {
	if (ope[bef] >= ope[aft]) { // >=符合从左至右运算
		return 1;
	}
	return -1;
}

int cal(queue<char> hou) {
	stack<int> t;
	int left, right, result;
	while(hou.size()>0){
		if (hou.front()>='0' && hou.front()<='9'){
			t.push(hou.front()-'0');
		} else {
			right = t.top();
			t.pop();
			left = t.top();
			t.pop();
			switch(hou.front()) {
				case '+':
					result = left+right;
					break;
				case '-':
					result = left-right;
					break;
				case 'x':
					result = left*right;
					break;
				case '/':
					result = left/right;
					break;
			}
			t.push(result);
		}
		hou.pop();
	}
	return t.top();
}

int main() {
	int n, num,cr;
	char op, bef;
	string exp;
	cin >> n;
	for (int i=0;i<n;i++) {
		cin>>exp;
		for(char i : exp) {
			if (i >='0' && i<='9'){ //数字直接入队 
				nums.push(i);
			} else { // 操作符需要根据优先级入队，使用栈来辅助 
				while(opes.size()>0){ // 将优先级更高的操作符入队 
					if(prio(opes.top(), i) == 1){
						nums.push(opes.top());
						opes.pop();
					} else break;
				}
				opes.push(i);
			}
		}
		while(opes.size()>0){ // 将剩下的操作符入队 
			nums.push(opes.top());
			opes.pop();
		}
		if(cal(nums)==24) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}