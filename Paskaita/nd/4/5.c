#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define array_size 256

int main(){
    int n, i = 0;
    float a, sum = 0, average, big, small;
    char buffer[array_size];
    pradzia:
    printf("Enter number n:\n");
    if (scanf("%d", &n) == 1 && n > 0) {
        gets(buffer);
        if(strlen(buffer) == 0) {
            printf("Enter n number of numbers:\n");
            while(i < n){
                pradzia2:
                printf("Enter %d number of numbers:\n", i + 1);
                if (scanf("%f", &a) == 1) {
                    gets(buffer);
                    if(strlen(buffer) == 0) {
                        sum += a;
                        if(i == 0){
                            big = a;
                            small = a;
                        } else {
                            if(a > big)
                                big = a;
                            if(a < small)
                                small = a;
                        }
                    } else {
                        printf("Wrong input.\n");
                        goto pradzia2;
                    }
                } else {
                    printf("Wrong input.\n");
                    gets(buffer);
                    goto pradzia2;
                }
                ++i;
            }
            average = sum / n;
            printf("The sum of these numbers is %g\nThe average of these numbers is %g\nThe highest value of the numbers is %g\nThe lowest value of the numbers is %g\n", sum, average, big, small);
        } else {
            printf("Wrong input.\n");
            goto pradzia;
        }
    } else {
        printf("Wrong input.\n");
        gets(buffer);
        goto pradzia;
    }
    return 0;
}
