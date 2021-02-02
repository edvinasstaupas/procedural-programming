#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, **intMatrix;
    printf("Type the matrix number:\t");
    scanf("%d", &n);

    intMatrix = (int **)malloc(n * sizeof(int *)); 
    
    for (i = 0; i < n; ++i)
        intMatrix[i] = (int *)malloc(n * sizeof(int)); 

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("Type a number for <line: %d, column: %d>\t", i+1, j+1);
            scanf("%d", &intMatrix[i][j]);
        }
    }
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d ", intMatrix[i][j]);
        }
        printf("\n");
    }
}