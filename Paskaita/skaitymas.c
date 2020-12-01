#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    int a = 0; float b = 0;
    scanf("%d%f", &a, &b);
    printf("Coordinates x = %d; y = %f; \nthe sum of it is %f\nthe sandauga of it is %f\n", a, b, a+b, a*b);
    return 0;
}
