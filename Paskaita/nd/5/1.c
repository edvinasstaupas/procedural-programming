#include <stdio.h>
#include <stdlib.h>

#define array_size 10

void print_array (int a[], int n);

int main(){
    int n = 10;
    int a[array_size] = {0};
    int x, y;
    print_array(a, n);
    a[0] = 1;
    a[3] = 2;
    a[9] = 3;

    for(int i = 2; i < n-2; ++i){
        a[i] = a[i+1];
    }
    --n;

    for(int i = n-1; i > 5; --i){
        a[i] = a[i-1];
    }
    a[6] = 4;
    ++n;

    print_array(a, n);

    printf("Please enter x and y:\n");
    scanf("%d%d", &x, &y);
    a[x] = y;

    printf("Please enter x:\n");
    scanf("%d", &x);
    for(int i = x; i < n-x+1; ++i){
        a[i] = a[i+1];
    }
    --n;

    printf("Please enter x and y:\n");
    scanf("%d%d", &x, &y);
    for(int i = n-1; i > x-1; --i){
        a[i] = a[i-1];
    }
    a[x] = y;

    print_array(a, n);
    return 0;
}
void print_array (int a[], int n) {
    for(int i = 0; i < n; ++i){
        printf("%d %d\n",i, a[i]);
    }
}
