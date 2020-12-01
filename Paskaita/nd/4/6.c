#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    int a, b, c, count, big = -3, count_max = 0, i = 0;
    char buffer[256];
    printf("Enter positive integer numbers and when you want to stop inputing numbers, type negative integer:\n");
    while(1){
        pradzia:
        if(scanf("%d", &a) == 1) {
            if(a < 0)
                break;
            gets(buffer);
            if(strlen(buffer) == 0) {
                int count = 1;
                int a1 = a;
                while(a1 >= 10) {
                    a1 = a1 % 10;
                    ++count;
                }
                if(count > count_max || count == count_max && a > big){
                    big = a;
                    count_max = count;
                }
            }
        } else {
            printf("Wrong input.\n");
            gets(buffer);
            goto pradzia;
        }
        printf("%d%d\n", big, count_max);
    }
    printf("Number %d has the most digits in it\nProgram terminated.\n", big);
    return 0;
}
