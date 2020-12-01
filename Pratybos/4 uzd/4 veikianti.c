//Edvinas Staupas 5 grupe 4 uzd 1 uzd
//
#include <stdlib.h>
#include <stdio.h>

struct el {
    int duom;
    struct el *kitas;
};
void addElement(struct el *elem, struct el *end);
void printElem( struct el *elem, int value, int *found);
void PrintList(struct el *elem);
int main () {
    struct el *start, *end, *elem, *elemk;
    start = NULL;
    end = NULL;
    elem = (struct el *) malloc ( sizeof ( struct el ) );
    elem -> duom = 0;
    elem -> kitas  = NULL;
    start = elem;
    end = elem;
    srand(time(0));
    for(int i = 0; i < 10; ++i){
        int upper = 10, lower = 0;
        elem = (struct el *) malloc ( sizeof ( struct el ) );
        elem -> duom = (rand() % (upper - lower + 1) + lower);;
        elem -> kitas = NULL;
        end -> kitas = elem;
        end = elem;
        //elem = (struct el *) malloc ( sizeof ( struct el ) );
        //addElement(elem, end);
    }
    PrintList(start);
    printf("\n");
    int value = 5, found = 0;
    printElem(start, value, &found);
    return 0;
}

void addElement(struct el *elem, struct el *end) {
    /*int upper = 10, lower = 0;
    elem -> duom = (rand() % (upper - lower + 1) + lower);
    elem -> kitas = NULL;
    end -> kitas = elem;
    end = elem;
    printf("%d ", elem->duom);
    */
    int upper = 10, lower = 0;
    elem = (struct el *) malloc ( sizeof ( struct el ) );
    elem -> duom = (rand() % (upper - lower + 1) + lower);;
    elem -> kitas = NULL;
    end -> kitas = elem;
    end = elem;
    printf("%d ", elem->duom);
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
