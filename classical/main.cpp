#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>

#define DEFAULT_COLOR "\033[0m"
#define COLOR "\033[38;2;"
#define BGCOLOR "\033[48;2;"

char* format(char* stand, char* input); // 将色值格式化为6位
int sumhex(char bigger, char smaller); // 求16进制两个字符的十进制值
struct Colors htoi(char* hex); // 将16进制表示的色值转换为颜色结构体
int calOrder(int row, int col, int p, int q, int rowc); // 计算按块划分的行、高
struct Colors {
    double R;
    double G;
    double B;
} colors;

int main() {
    int m,n,p,q,i=0;
    struct Colors temp;
    char interVal[6];
    char *color = (char *)malloc(sizeof(char));
    char value[6];
    ifstream ifs;
    ifs.open("201909-3-1.txt", ifstream::in);
    ifs >> m >> n >> p >> q;
//  scanf("%d %d", &m, &n);
//  scanf("%d %d", &p, &q);
    int square = p * q;
    int inputCount = m*n, blockCount = (m*n)/square;
    struct Colors blocks[blockCount];
    for(i;i<=inputCount;i++){
        ifs >> color;
//    scanf("%s", color);
        temp = htoi(format(interVal, strncpy(value, color+1, 6)));
        int row = i / m;
        int col = i % m;
        int blockorder = calOrder(row, col, p, q, m/p);
        // printf("%s is at row: %d, col: %d, blockorder: %d\n", color,row,col,blockorder);
        blocks[blockorder].R+=temp.R/square;
        blocks[blockorder].G+=temp.G/square;
        blocks[blockorder].B+=temp.B/square;
    }
    for(i=0;i<blockCount;i++){ // 向0取整
        blocks[i].R=(int)blocks[i].R;
        blocks[i].G=(int)blocks[i].G;
        blocks[i].B=(int)blocks[i].B;
    }
    return 0;
}

char* format(char stand[], char *input) {
    if (strlen(input) == 6) {
        return input;
    } else if (strlen(input) == 3) {
        int i=0;
        for(i;i<3;i++){
            stand[2*i] = stand[2*i+1] = input[i];
        }
    } else {
        int i=0;
        for(i;i<6;i++){
            stand[i]=input[0];
        }
    }
    return stand;
}

struct Colors htoi(char* hex){
    int temp=0,i=0;
    struct Colors result;
    result.R = sumhex(hex[0], hex[1]);
    result.G = sumhex(hex[2], hex[3]);
    result.B = sumhex(hex[4], hex[5]);
    return result;
}

int sumhex(char bigger, char smaller){
    int result = 0;
    if (smaller >'9') result += 10+(smaller-'a');
    else result += smaller-'0';
    if (bigger>'9') result += 16*(10+(bigger-'a'));
    else result += 16*(bigger-'0');
    return result;
}

int calOrder(int row, int col, int p, int q, int rowc){
    int row2 = row / q;
    int col2 = col / p;
    return row2 * rowc + col2;
}