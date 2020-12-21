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

void deletElem(struct el **start, struct el *elem, int value, int *found, struct el **latest) {
	if (elem->kitas->kitas != NULL) {
        if (elem->duom == value) {
            if (elem == *start) {
                ++(*found);
                printf("s%d ", elem->duom);
                *start = elem->kitas;
                //free(elem);
                deletElem(start, *start, value, found, start);
            } else {
                ++(*found);
                printf("b%d ", elem->duom);
                elem->kitas = elem->kitas;
			//free(elem);
            }
        }
        if (elem->kitas->duom == value) {
            ++(*found);
			printf("k%d ", elem->kitas->duom);
			elem->kitas = elem->kitas->kitas;
			//free(elem->kitas->kitas);
			deletElem(start, elem, value, found, &elem);
		}
		deletElem(start, elem->kitas, value, found, &elem);
	} else {
        if(elem->kitas->duom == value){
            ++(*found);
			printf("a%d ", elem->kitas->duom);
			elem->kitas = NULL;
			printf("aaaa");
			//free(elem);
        }
	}
}

void printList(struct el *elem) {
    while (elem->kitas != NULL) {
        printf("%d ", elem->duom);
        elem = elem->kitas;
    }
    /*
	if (elem != NULL) {
		printf("%d ", elem->duom);
		printList(elem->kitas);
	}*/
}
