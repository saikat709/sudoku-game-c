#include <stdio.h>
#include <string.h>

#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define DEFAULT "\033[0m"
#define BLACK   "\033[0;30m"
#define GREEN   "\033[0;32m"
#define BLUE    "\033[0;34m"
#define PURPLE  "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"


void setColor(char* colorCode) {
  printf("%s", colorCode);
}


int main () {
  setColor(RED);
  printf("Hello ");
  setColor(YELLOW);
  printf("world");
  setColor(CYAN);
  printf(" EVERYONE!\n");
  return 0;
}