//Edvinas Staupas 5 grupe 3 uzd 14 uzd
//Įvesti sveiką skaičių N. Įvesti N sveikų skaičių. Rasti tarp įvestų skaičių dažniausiai pasikartojantį skaičių
#include <stdio.h>
#include <stdlib.h>

struct numbers {
   int num,
   counter;
};

int findNumber(int number, struct numbers n_array[], int n);

int main () {
    struct numbers *n_array;
    int n;
    printf("Please enter N:\n");
    scanf("%d", &n);
    if(n <= 0){
        printf("Wrong input. Program terminated.\n");
        return 0;
    }
    int *number = calloc(n, sizeof(int));
    printf("Please enter N numbers:\n");
    for(int i = 0; i < n; ++i){
        scanf("%d", &number[i]);
    }
    int l = 0;
    n_array = calloc(n, sizeof(int) * 2);
    for(int i = 0; i < n; ++i){
        int k = findNumber(number[i], n_array, l);
        if(k < 0){
            n_array[l].num = number[i];
            n_array[l].counter = 1;
            ++l;
        } else
            ++n_array[k].counter;
    }
    int most_occ = 0;
    for(int i = 0; i < l; ++i){
        if(n_array[most_occ].counter < n_array[i].counter){
            most_occ = i;
        }
    }
    printf("Number %d has the most occurences (%d).\n", n_array[most_occ].num, n_array[most_occ].counter);
    free(number);
    free(n_array);
    printf("Program ended succesfully.\n");
    return 0;
}
int findNumber (int number, struct numbers n_array[], int n){
    for(int i = 0; i < n; ++i)
        if(number == n_array[i].num)
            return i;
    return -1;
}
