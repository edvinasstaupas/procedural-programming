//little code for my buddy
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

void assign (int number, int *pos, int *neg, int *k, int *l);

int main() {
    int s, l = 0, k = 0, sum = 0;
    printf("Enter how many numbers there will be in the array:\n");
    scanf("%d", &s);
    int number;
    int *neg = calloc(s, sizeof(int));
    int *pos = calloc(s, sizeof(int));
    for (int i = 0; i < s; ++i){
        printf("Enter %d number of the array:\n", i);
        scanf("%d", &number);
        assign(number, pos, neg, &k, &l);
    }
    if(k == s || l == s){
        printf("All the numbers in the array are either negative or positive. Program terminated.\n");
        return 0;
    }
    for(int i = 0; i < k || i < l; ++i){
        sum += pos[i] * neg[i];
    }
    printf("Sum is %d\n", sum);
    free(pos);
    free(neg);
    return 0;
}

void assign (int number, int *pos, int *neg, int *k, int *l){
    if (number < 0){
        neg[*l] = number;
        ++(*l);
    } else if (number > 0){
        pos[*k] = number;
        ++(*k);
    }
}
