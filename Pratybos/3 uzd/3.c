//Edvinas Staupas 5 grupe 3 uzd 14 uzd
//Įvesti sveiką skaičių N. Įvesti N sveikų skaičių. Rasti tarp įvestų skaičių dažniausiai pasikartojantį skaičių
#include <stdio.h>
#include <stdlib.h>

struct numbers {
   int num,
   counter;
};

void read (int n, int **number);

void findNumber(int number, struct numbers n_array[], int n, int *k);

int main () {
    struct numbers *n_array;
    int n;
    printf("Please enter N:\n");
    scanf("%d", &n);
    if(n <= 0){
        printf("Wrong input. Program terminated.\n");
        return 0;
    }
    int *number = NULL;
    read(n, &number);
    int l = 0;
    n_array = malloc(n * sizeof(struct numbers));
    for(int i = 0; i < n; ++i){
        int k = -1;
        findNumber(number[i], n_array, l, &k);
        if(k < 0){
            n_array[l].num = number[i];
            n_array[l].counter = 1;
            ++l;
        } else
            ++n_array[k].counter;
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
    printf("Program ended succesfully.");
    return 0;
}
void read (int n, int **number){
    *number = malloc(n * sizeof(int));
    printf("Enter number:\n");
    for(int i = 0; i < n; ++i){
        scanf("%d", &(*number)[i]);
    }
}
void findNumber (int number, struct numbers *n_array, int n, int *k){
    for(int i = 0; i < n; ++i){
        if(number == n_array[i].num){
            *k = i;
            return;
        }
    }
    *k = -1;
}
