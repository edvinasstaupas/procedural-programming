#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a, b, c, count = 0;
    char buffer[256];
    pradzia:
    printf("Enter three positive integer numbers:\n");
    if (scanf("%d %d %d", &a, &b, &c) == 3 && a >= 0 && b >= 0 && c >= 0) {
        gets(buffer);
        for(int i = a + 1; i <= b; ++i) {
            printf("Number %d divided by %d has a remainder of 1.\n", i, c);
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
    printf("Program terminated.\n");
    return 0;
}
