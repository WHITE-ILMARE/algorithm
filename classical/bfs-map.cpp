#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

class elements{
private:
    unordered_map<string, int> record;  // 记录元素个数
    vector<int> stack;  // 记录嵌套括号外的数字

    bool islower(char& c){
        return c >= 'a' && c <= 'z';
    }
    bool isdigit(char& c){
        return c >= '0' && c <= '9';
    }
public:
    elements(vector<string> words){
        stack.push_back(1);

        int times = 1;  // 记录当前的元素需要乘的倍数
        // int outsideNum = 1;  // 括号外的数字（现改为局部变量）
        int inside = 0;  // 记录括号嵌套的层次
        int totalNum = 0; // 化学式的系数
        for(auto word : words){
            for(int i = 0; i < word.size() && isdigit(word[i]); i++){  // 获取化学式的系数
                totalNum = totalNum * 10 + word[i] - '0';
            }
            if(totalNum == 0) // 没有系数则默认为1
                totalNum = 1;

            for(int i = word.size() - 1; i >= 0; i--){
                char curch = word[i];
                if(isdigit(curch)){
                    times = curch - '0';
                    if(word[i - 1] == ')'){ // 出现的数字属于括号内的元素
                        // outsideNum = times;

                        if(inside == 0){ // 如果还没有嵌套,目前仅出现了单层括号
                            stack.pop_back();
                        }
                        stack.push_back(times);

                        times = 1;
                    }
                } else if (curch == ')'){
                    inside++;
                } else if (curch == '('){
                    inside--;
                    // outsideNum = 1;

                    stack.pop_back();
                    if(inside == 0){
                        stack.push_back(1);
                    }
                } else if (islower(curch)){
                    string temp_ele;
                    temp_ele.push_back(word[i - 1]);
                    temp_ele.push_back(curch);

                    int outsideNum = 1;
                    for(auto n : stack){
                        outsideNum *= n;
                    }
                    record[temp_ele] += times * outsideNum * totalNum;
                    times = 1;
                    i--;
                } else {  // 单个的元素
                    string temp_ele;
                    temp_ele.push_back(curch);
                    int outsideNum = 1;
                    for(auto n : stack){
                        outsideNum *= n;
                    }
                    record[temp_ele] += times * outsideNum * totalNum;
                    times = 1;
                }
            }

            totalNum = 0;  // 记得清零，对下一个化学式判断
            times = 1;
        }

        for(const auto& r : record){
            cout << r.first << " : " << r.second << endl;
        }
    }
    int operator[](string elem){
        return record[elem];
    }
    bool operator==(elements& rightElement){
        for(const auto& r : record){
            if(r.second != rightElement[r.first])
                return false;
        }
        return true;
    }
};

bool isbalance(string input){
    vector<string> leftwords;
    vector<string> rightwords;
    std::stringstream ss(input);
    vector<string> line;
    string temp;
    while(getline(ss, temp, '=')){  // 把整个表达式分为左右两个部分
        line.push_back(temp);
    }
    ss = stringstream(line[0]);
    while(getline(ss, temp, '+')){
        leftwords.push_back(temp);
    }
    ss = stringstream(line[1]);
    while(getline(ss, temp, '+')){
        rightwords.push_back(temp);
    }
//    cout << "the left elements number:\n";
//    elements left(leftwords);
//    cout << "the right elements number:\n";
//    elements right(rightwords);
    return left == right;
}

int main()
{
    int equanum;
    cin >> equanum;
    string result;
    for(int i = 0; i < equanum; i++){
        string input;
        cin >> input;
        bool res = isbalance(input);
        result.push_back(res?'Y':'N');
    }
    for(auto c : result)
        cout << c << endl;
    return 0;
}