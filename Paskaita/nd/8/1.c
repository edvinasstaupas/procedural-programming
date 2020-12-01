#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int create_Array(size_t size, int lower, int upper);

int main(){
    int *array;
    size_t size = 5;
    int lower = 5, upper = 15;
    int pointer = create_Array(size, lower, upper);
    printf("%d ", pointer);
    for(int i = 0; i < size; ++i){
        //printf("%d ", array[i]);
    }
    return 0;
}
int create_Array(size_t size, int lower, int upper){
    int *array = calloc(size, sizeof(int));
    return &array;
}
