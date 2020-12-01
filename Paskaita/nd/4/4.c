#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define array_size 256

int main(){
    int a, b, c;
    char buffer[array_size];
    pradzia:
    printf("Enter three positive integer numbers that are bigger than 1:\n");
    if (scanf("%d %d %d", &a, &b, &c) == 3 && a > 1 && b > 1 && c > 1) {
        gets(buffer);
        if(strlen(buffer) == 0) {
            //euklido algoritmas
            int a1 = a, b1 = b, c1 = c;
            while (abs(a) && abs(b)){
                if (abs(a) > abs(b))
                    a %= b;
                else b %= a;
            }
            int dbd = a + b;
            int dbd1 = dbd;
            while (abs(dbd) && abs(c)){
                if (abs(dbd) > abs(c))
                    dbd %= c;
                else c %= dbd;
            }
            int dbd2 = dbd + c;
            int mbk = (dbd1*c1) / dbd2;
            printf("GCD:%d \nLCM:%d\n", dbd2, mbk);
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
