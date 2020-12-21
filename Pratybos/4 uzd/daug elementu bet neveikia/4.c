//#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int findValue(int upper, int lower);

int main() {
	struct el *start = NULL, *elem;
	int upper = 6, lower = 4,
	n = 10,
	value, found, c;
    srand(time(0));
	for (int i = 0; i < n; ++i) {
		value = findValue(upper, lower);
		addElem(&start, value);
	}
	printList(start);
	printf("\n");
	value = 5;
	found = 0;
	c = 0;
	deletElem(&start, start, value, &found, &start);
	printf("bbb");
	if (found == 0)
        printf("There is no element with value %d in this linked list.", value);
	printf("\n");
	printList(start);
	return 0;
}

int findValue(int upper, int lower) {
    int value = (rand() % (upper - lower + 1)) + lower;
    return value;
}
