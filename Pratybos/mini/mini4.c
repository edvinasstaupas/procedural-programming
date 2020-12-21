//apibrezti statini masyva 5 elementu ir apibrezti structura kuri tures masyva viduj, funckija gauna ir pakeicia.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int arr[SIZE];
} arrayStruct;

void fillArrays (int *arr, arrayStruct sArr) {
    for (int i = 0; i < SIZE; ++i){
        arr[i] = 1;
        sArr.arr[i] = 2;
    }
}

void printArray (int *arr) {
    for(int i = 0; i < SIZE; ++i){
        printf("%d ", arr[i]);
    }
}

int main () {
    int arr[SIZE] = {1, 2, 3, 4, 5};
    arrayStruct sArr = {{1, 2, 3, 4, 5}};
    printArray(arr);
    printArray(sArr.arr);
    fillArrays(arr, sArr);
    printArray(arr);
    printArray(sArr.arr);
    return 0;
    }
