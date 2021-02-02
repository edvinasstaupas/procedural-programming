//Sudaryti vienpusį sąrašą. Parašyti procedūrą, kuri išmeta reikšme nurodytą elementą. Jeigu tokio elemento nėra, turi būti išvestas atitinkamas pranešimas.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int findValue(int upper, int lower);

int main() {
	struct el *start = NULL;
	int upper = 6, lower = 4,
	n = 10,
	value;
    srand(time(0));
	for (int i = 0; i < n; ++i) {
		//value = findValue(upper, lower);
		value = i;
		addElem(&start, value);
	}
	printList(&start, 5);
	printf("\n");
	value = 4;
	deletElem(&start, value);
	printf("\n");
	printList(&start, n+2);
	return 0;
}

int findValue(int upper, int lower) {
    int value = (rand() % (upper - lower + 1)) + lower;
    return value;
}
