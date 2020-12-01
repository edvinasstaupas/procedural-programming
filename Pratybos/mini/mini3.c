#include <stdio.h>
#include <stdlib.h>

void changeValue(int array[], int array_size);
int main () {
    int n = 5;
    int *number = calloc(n, sizeof(int));
    changeValue(number, n);
    for(int i = 0; i < n; ++i){
        printf("%d ", number[i]);
    }
    free(number);
    return 0;
}
void changeValue(int array[], int array_size){
    for(int i = 0; i < array_size; ++i){
        array[i] = 5;
    }
}
