#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct el {
	int duom;
	struct el *kitas;
};

void addElem(struct el **start, int value);
void printElem(struct el *elem, int value, int *found);
void printList(struct el *elem);

int main() {
	struct el *start = NULL, *elem;
	int upper = 10, lower = 0,
	value, found;
    srand(time(0));
	for (int i = 0; i < 10; ++i) {
		value = findValue(upper, lower);
		addElem(&start, value);
	}
	printList(start);
	printf("\n");
	value = 5;
	found = 0;
	printElem(start, value, &found);
	return 0;
}

int findValue(int upper, int lower) {
    int value = (rand() % (upper - lower + 1)) + lower;
    return value;
}

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

void printElem(struct el *elem, int value, int *found) {
	if (elem != NULL) {
		if (elem->duom == value) {
            ++(*found);
			printf("%d ", elem->duom);
		}
		printElem(elem->kitas, value, found);
	} else if (*found < 1)
		printf("There is no element with value %d in this linked list.", value);
}

void printList(struct el *elem) {
	if (elem != NULL) {
		printList(elem->kitas);
		printf("%d ", elem->duom);
	}
}
//the end
