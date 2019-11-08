#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input;
  while(scanf("%c", input)!=EOF) {
    printf("%d\n", input);
  }
  return 0;
}