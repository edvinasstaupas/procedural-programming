#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a, b, c, count = 0;
    char buffer[256];
    pradzia:
    printf("Enter three integer numbers:\n");
    if (scanf("%d %d %d", &a, &b, &c) == 3) {
        gets(buffer);
        if(strlen(buffer) == 0) {
            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }
            for(int i = a + 1; i <= b; ++i) {
                if(i % c == 1){
                    printf("Number %d divided by %d has a remainder of 1.\n", i, c);
                    ++count;
                }
            }
            if(count == 0){
                printf("There are no such number in interval (%d, %d] that have a remainder of 1 when divided by %d.\n",a, b, c);
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
