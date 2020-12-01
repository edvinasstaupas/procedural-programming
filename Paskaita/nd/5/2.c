#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array (int a[], int n);

int main(){
    int array[1000];
    int a, b, c;
    printf("Please enter a, b, c:\n");
    scanf("%d%d%d", &a, &b, &c);
    if(a > b){
        int temp = b;
        b = a;
        a = temp;
    }
    srand(time(NULL));
    for(int i = 0; i < c; ++i){
        array[i] = rand() % (b - a + 1) + a;
    }
    print_array(array, c);
    return 0;
}
void print_array (int a[], int n) {
    for(int i = 0; i < n; ++i){
        printf("%d %d\n", i, a[i]);
    }
    printf("\n\n\n");
}
