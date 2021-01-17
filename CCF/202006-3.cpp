// 思路：将转化后的字符串按段落/列表存入vector中，再计算行数
/**
 * 遇到的问题：
 * 1. trim()没有考虑边界情况：str全为空格
 * 2. input的过程逻辑复杂，没有及时简化
 * 3. input过程未考虑边界情况：开头连续空行(受2的影响)
 * 4. input过程不完善，若不以空行结束，最后一段落不会被处理
 * 在解决了以上4个问题后，有40分了(仅段落的情况AC)，我giao，模拟题细心点分还是能拿
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<string> lines;

string trim(string str) { // 去掉str首尾空格
    int s = str.find_first_not_of(" "); int e = str.find_last_not_of(" ");
    if (s == string::npos) return ""; // 若字符串全是空格，返回空串
    return str.substr(s, (e-s+1));
}

int calculate(int w) { // 计算固定宽度渲染内容需要多少行
    int result = 0;
    for (auto str : lines) {
        if (str.length() <= w) {
//            cout << str << endl;
            ++result;
        }
        else {
            while(str.length() > w) {
                ++result; // 0->w-1一行
//                cout << str.substr(0, w) << endl;
                str = str.substr(w);
                // 去掉剩余部分的前后空格
                str = trim(str);
            }
//            cout << str << endl;
            ++result;
        }
    }
    return result;
}

int main() {
    int w = 0; string tw;
    ios::sync_with_stdio(false);
//    fstream fs("202006-3.txt");
//    getline(fs, tw); int len = tw.length();
//    for (int i =0;i<len;++i) w = 10 * w + (tw[i] - '0');
    cin >> w;
    getchar();
    int paragraph_num = 0;
    string line, para = "";
    while(getline(cin, line) && !cin.eof()) {
//        cout << "line:" <<line << endl;
//        cout << "eof: " << fs.eof() << endl;
        line = trim(line);
        if (line != ""){
            para += (" "+line); // 所有行加空格
        } else if (para.length() > 0) { // 输入了空行，para中若有内容，即存储了上一个段落
            lines.push_back(trim(para)); // trim去掉段落第一个空格
            ++paragraph_num; // 上传了一个段落，加一个段落数
            para = ""; // 重置para
        }
    }
    if (para.length() > 0) {
        lines.push_back(trim(para));
        ++paragraph_num;
        para = "";
    }
//    cout << calculate(w) << endl;
//    cout << paragraph_num << endl;
    cout << calculate(w) + (paragraph_num > 0 ? (paragraph_num -1) : 0) << endl;
    return 0;
}