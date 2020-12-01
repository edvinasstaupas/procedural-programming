#include <stdio.h>
#include <stdlib.h>

typedef struct prime {
    int number;
    int used;
} prime;

prime prime_array[1000];
int find (int x, prime prime_array[], int l);

int main(){
    //struct prime prime_array[1000];
    int l = 0;
    for(int sk = 2; sk < 1000; ++sk){
        int count = 0;
        for(int i = 2; i <= sk; ++i) {
            if(sk % i == 0)
                ++count;
        }
        if (count == 1){
            prime_array[l].number = sk;
            prime_array[l].used = 0;
            ++l;
        }
    }
    int x[1000];
    printf("Please enter positive integers and when you want to finish your array, enter negative integer:\n");
    int j = 0;
    while(x[j-1]>=0){
        scanf("%d", &x[j]);
        ++j;
    }
    printf("\nYour array has these prime numbers:");
    for(int i = 0; i < j; ++i){
        int k = find(x[i], prime_array, l);
        if(k >= 0)
            printf(" %d", x[i]);
    }
    return 0;
}

int find (int x, prime prime_array[], int l){
    for(int i = 0; i < l; ++i){
        if(x == prime_array[i].number && prime_array[i].used == 0){
            ++prime_array[i].used;
            return i;
        }
    }
    return -1;
}
