#include <stdlib.h>
#include <stdio.h>

struct el {
    int duom;
    struct el *kitas;
};

void addElement(struct el **start, int value);
void printElem( struct el *elem, int value, int *found);
void PrintList(struct el *elem);

int main () {
    struct el *start = NULL, *elem;
    srand(time(0));
    int upper = 10, lower = 0;
    for(int i = 0; i < 10; ++i){
        int value = (rand() % (upper - lower + 1) + lower);
        addElement(&start, value);
    }
    PrintList(start);
    printf("\n");
    int value = 5, found = 0;
    printElem(start, value, &found);
    return 0;
}

void addElement(struct el **start, int value) {
    struct el *elem = (struct el *) malloc ( sizeof ( struct el ) );
    elem -> duom = value;
    if(*start == NULL){
        elem -> kitas = NULL;
        *start = elem;
    } else {
        elem -> kitas = *start;
        *start = elem;
    }
}

void printElem( struct el *elem, int value, int *found) {
    if (elem != NULL){
        if(elem -> duom == value){
            ++(*found);
            printf("%d\n",elem -> duom);
        }
        printElem( elem->kitas , value, found);
    } else if (*found < 1)
        printf("There is no element with value %d in this linked list.", value);
}

void PrintList( struct el *elem ) {
    if (elem != NULL){
        PrintList( elem->kitas );
        printf( "%d ", elem->duom );
    }
}
