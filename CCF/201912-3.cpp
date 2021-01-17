#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <unordered_map>

// 错了好多次的原因：判断是否为数字的函数写错了，以后直接用isdigit
using namespace std;

unordered_map<string, int > lstrmap, rstrmap;

bool isLow(char s) {
    return s >='a' && s<='z';
}

void classify(unordered_map<string, int> *m, string s) {
    vector<string> words;
    int p;
    while(s.length()>0) {
        p = s.find("+");
        if (p == -1) break;
        words.push_back(s.substr(0, p));
        s = s.substr(p+1);
    }
    words.push_back(s);
    // 因为带括号的系数出现在括号后，所以从后往前遍历
    for (auto word : words) {
        int index = 1; // 整体的系数
        int temp = 1; // 即将被使用的，不用存起来的系数
        int top = 1; // 在indexes栈空时做默认系数
        string item = ""; // 元素名
        stack<int> indexes; // 括号带来的需要存起来的系数
        if (isdigit(word[0])) {
            index = 0;
            while(isdigit(word[0])) {
                index = 10*index + (word[0] - '0');
                word = word.substr(1);
            }
        }
        for (int l=word.length(), i=l-1;i>=0;) {
            if (isdigit(word[i])) {
                temp = word[i] - '0'; int flag = 1; --i;
                while(isdigit(word[i])) {
                    flag *= 10;
                    temp = temp + flag * (word[i]-'0');
                    --i;
                }
            } else if (word[i] == ')') {
                indexes.push(top*temp);
                top = indexes.top();
                temp = 1; --i;
            } else if (word[i] == '(') {
                indexes.pop(); --i;
                top = indexes.empty() ? 1 : indexes.top();
            } else if (isLow(word[i])) {
                item = "";
                item.push_back(word[i-1]); item.push_back(word[i]);
                (*m)[item] += index*top*temp;
                temp = 1;
                --i; --i;
            }  else {
                string item; item.push_back(word[i]);
                (*m)[item] += index*top*temp;
                temp = 1; // temp代表单个元素系数，每次存储后应恢复1
                --i;
            }
        }
    }
//    cout << "-------------items in maps------------------" << endl;
//    for (auto k : (*m)) {
//        cout << k.first << ':' << k.second << endl;
//    }
//    cout << "-------------items in maps------------------" << endl;
}

bool check(string s) {
    int pos = s.find("=");
    string left = s.substr(0, pos);
    string right = s.substr(pos+1);
    classify(&lstrmap, left);
    classify(&rstrmap, right);
    for(auto k : lstrmap) {
        if (k.second != rstrmap[k.first]) return false;
    }
    return true;
}

int main() {
    int n;
//    fstream fs;
//    fs.open("2019-12-3.txt");
//    fs >> n;
    cin >> n;
    char result[n];
    for (int i=0;i<n;++i) {
        string s;
//        fs >> s;
        cin >> s;
        if (check(s)) {
            result[i] = 'Y';
        } else {
            result[i] = 'N';
        }
        lstrmap.clear(); rstrmap.clear();
    }
    for (auto k : result) {
        cout << k << endl;
    }
    return 0;
}