#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define array_size 256

int main(){
    int a, b, c;
    char buffer[array_size];
    pradzia:
    printf("Enter three integer numbers that are equation's variables:\n");
    if (scanf("%d %d %d", &a, &b, &c) == 3) {
        gets(buffer);
        if(strlen(buffer) == 0) {
            int d = b * b - 4 * a * c;
            if(d == 0){
                double x = ((-1) * b + sqrt(d))/(2 * a);
                printf("Equation %dx2 + %dx +%d has one answer: %f.\nProgram terminated.\n",a, b, c, x);
                return 0;
            } else if(d < 0) {
                printf("This equation does not exist.\nProgram terminated.\n");
                return 0;
            } else {
                double x1 = ((-1) * b + sqrt(d))/(2 * a);
                double x2 = ((-1) * b - sqrt(d))/(2 * a);
                printf("Equation %+dx2 %+dx %+d has two answers: %f and %f.\nProgram terminated.\n",a, b, c, x1, x2);
                return 0;
            }
        } else {
            printf("Wrong input.\n");
            goto pradzia;
        }
    }
    else {
        printf("Wrong input.\n");
        gets(buffer);
        goto pradzia;
    }
    return 0;
}
