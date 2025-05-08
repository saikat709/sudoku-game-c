#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

int main() {
    printf("CONTENT");
    system(CLEAR);
    sleep(1);
    printf("Terminal cleared!\n");
    printf("Enter a number: ");
    int a;
    scanf("%d", &a);
    printf("You entered: %d\n", a);
    sleep(2);
    system(CLEAR);
    return 0;
}