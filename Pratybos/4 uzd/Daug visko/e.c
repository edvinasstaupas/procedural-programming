//Edvinas Staupas 5 grupe 4 uzd 1 uzd
//
#include <stdlib.h>
#include <stdio.h>


void printElem(int value, int *found);
int main () {
    int found = 0;
    printElem(5, &found);
    printf("%d %d", 5, found);
    return 0;
}

void printElem(int value, int *found) {
    /*if (*found != 5){
        printf("%d %d", value, found);
        ++(*found);
        printElem(value, &found);
    }*/
    ++(*found);
    printf("%d %d", value, *found);
    //printElem(value, &found);
}
