#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

void addElem(struct el **start, int value) {
	struct el *elem = (struct el *) malloc(sizeof(struct el));
	elem->duom = value;
	if (*start == NULL) {
		elem->kitas = NULL;
		*start = elem;
	} else {
		elem->kitas = *start;
		*start = elem;
	}
}

void deletElem(struct el **start, int value) {
	if ((*start) != NULL) {
        struct el *tempElem;

        if ((*start)->duom == value){
            tempElem = *start;
            (*start) = tempElem->kitas;
            free(tempElem);
            return;
        } else {
            struct el *elem = (*start);

            while (elem->kitas != NULL) {
                if (elem->kitas->duom == value){
                    tempElem = elem->kitas;
                    elem->kitas = tempElem->kitas;
                    free(tempElem);
                    return;
                }
                elem = elem->kitas;
            }
        }
	}
    printf("There is no element with value %d in the list.\n", value);
}

void printList(struct el **start, int value) {
    int i = 0;
    struct el *elem = (*start);
    while (elem->kitas != NULL) {
        printf("%d ", elem->duom);
        if(i == value){
            struct el *tempElem = (struct el *) malloc(sizeof(struct el));
            tempElem->kitas = elem->kitas;
            tempElem->duom = -1;
            elem->kitas = tempElem;
        }
        elem = elem->kitas;
        ++i;
    }
}
