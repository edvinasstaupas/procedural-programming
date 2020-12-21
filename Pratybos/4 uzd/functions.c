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

void printList(struct el *elem) {
    while (elem->kitas != NULL) {
        printf("%d ", elem->duom);
        elem = elem->kitas;
    }
}
