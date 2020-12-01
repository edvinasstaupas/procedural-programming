#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int a[array_size];
    char buffer[array_size];
    pradzia1:
    printf("Enter number n:\n");
    if (scanf("%d", &a) == 1) {
        gets(buffer);
        if(strlen(buffer) == 0) {
            printf("Enter n number of numbers:\n");
            for(int i = 0; i < n; ++i){
                if (scanf("%f", &a[i]) == 1) {
                    gets(buffer);
                    if(strlen(buffer) == 0) {
                        sum += a[i];
                    }
                }
            average = sum / n;
        } else {
            printf("Wrong input.\n");
            goto pradzia;
        }
    }
    else {
        printf("Wrong input.\n");
        gets(buffer);
        goto pradzia1;
    }
            }
        } else {
            printf("Wrong input.\n");
            goto pradzia;
        }
    }
    else {
        printf("Wrong input.\n");
        gets(buffer);
        goto pradzia1;
    }
    return 0;
}
