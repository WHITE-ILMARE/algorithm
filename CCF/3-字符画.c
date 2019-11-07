#include <stdio.h>
#include <string.h>

#define DEFAULT_COLOR "\033[0m"
#define COLOR "\033[38;2;"
#define BGCOLOR "\033[48;2;"

char* format(char *input) {
  char stand[7];
  if (strlen(input) == 6) {
    return input;
  } else if (strlen(input) == 3) {
    int i=0;
    for(i;i<5;i+=2){
      stand[i]=input[i/2];
      stand[i+1]=input[i/2];
    }
  } else {
    int i=0;
    for(i;i<6;i++){
      stand[i]=input[0];
    }
  }
  return stand;
}

int main() {
  char *input;
  while(scanf("%s", input)){
    printf("%s\n", format(input));
  }  
  return 0;
}