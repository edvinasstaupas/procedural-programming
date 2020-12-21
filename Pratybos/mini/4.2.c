#include <stdio.h>
#include <stdlib.h>

//apibrezti statini masyva 5 elementu ir apibrezti structura kuri tures masyva viduj, funckija gauna ir pakeicia.

#define array_size 5

struct struct_array {
    int number[array_size];
};

void changeValue(int *number_array, struct struct_array array);

int main () {
    int number_array[array_size] = {1, 2, 3, 4, 5};
    struct struct_array array;

    changeValue(number_array, array);

    for(int i = 0; i < array_size; ++i){
        printf("%d ", number_array[i]);
    }
    printf("\n");
    for(int i = 0; i < array_size; ++i){
        printf("%d ", array.number[i]);
    }
    return 0;
}
void changeValue(int *number_array, struct struct_array array){
    for(int i = 0; i < array_size; ++i){
        array.number[i] = 1;
        number_array[i] = 1;
    }
}
