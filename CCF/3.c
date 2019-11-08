#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DEFAULT_COLOR "\033[0m"
#define COLOR "\033[38;2;"
#define BGCOLOR "\033[48;2;"

char* format(char* stand, char* input);
int htoi(char* hex);
int calOrder(int row, int col, int p, int q, int rowc);

int main() {
  int m,n,p,q,i=0,temp;
  char interVal[6];
  char *color = (char *)malloc(sizeof(char));
  char value[6];
  scanf("%d %d", &m, &n);
  scanf("%d %d", &p, &q);
  int square = p * q;
  int lineCount = m*n, blockCount = (m*n)/square;
  int blocks[blockCount];
  for(i;i<=lineCount;i++){
    scanf("%s", color);
    temp = htoi(format(interVal, strncpy(value, color+1, 6)));
    int row = i / m;
    int col = i % m;
    int blockorder = calOrder(row, col, p, q, m/p);
    // printf("%s is at row: %d, col: %d, blockorder: %d\n", color,row,col,blockorder);
    blocks[blockorder]+=temp;
  }
  for(i=0;i<blockCount;i++){
    blocks[i]/=square;
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

int htoi(char* hex){
  int result=0,i=0;
  for(i;i<6;i++){
    if(hex[i]>'9'){
      result = 16*result+10+(hex[i]-'a');
    }else{
      result=16*result+(hex[i]-'0');
    }
  }
  return result;
}

int calOrder(int row, int col, int p, int q, int rowc){
  int row2 = row / q;
  int col2 = col / p;
  return row2 * rowc + col2;
}