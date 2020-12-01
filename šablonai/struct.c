//Edvinas Staupas 5 grupe 3 uzd 14 uzd
//Įvesti sveiką skaičių N. Įvesti N sveikų skaičių. Rasti tarp įvestų skaičių dažniausiai pasikartojantį skaičių
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct numbers
{
   int num, counter;
};


int findNumber(int number, struct numbers n_array[], int n);
int main () {
    struct numbers *n_array;
    int n;
    printf("Please enter N:\n");
    scanf("%d", &n);
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
    for(int i = 0; i < l; ++i){
        //printf("%d", )
    }
    int most_occ = 0, most_occ_number = 0;
    for(int i = 0; i < l; ++i){
        if(n_array[i].counter > most_occ){
            most_occ = n_array[i].counter;
            most_occ_number = n_array[i].num;
        }
    }
    printf("Number %d has the most occurences (%d).\n", most_occ_number, most_occ);
    free(number);
    free(n_array);
    return 0;
}
int findNumber (int number, struct numbers n_array[], int n){
    for(int i = 0; i < n; ++i){
        if(number == n_array[i].num)
            return i;
    }
    return -1;
}
