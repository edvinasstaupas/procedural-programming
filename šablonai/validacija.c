#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    int isGood = 0;

    while(!isGood) {
        if((scanf("%9d", &x) == 1) && (getchar() == '\n')) {
            printf("Viskas ok.\n", x);
            isGood = 1;
        } else {
            printf("Wrong input. Try again.\n");
            scanf("%*[^\n]");
        }
    }
}