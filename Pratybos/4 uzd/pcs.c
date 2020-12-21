#include <stdlib.h>
#include <stdio.h>

#define STRUC_SIZE 50

struct structure {
	int data;
};

void doingSomething(int number, int *number_array);

int main() {
	struct structure structure_array[STRUC_SIZE];
	int number_that_will_be_used_now = 5,
	number_that_will_be_used_later;
	number_that_will_be_used_later = 10;

	while (variable != 0)
        ++variable;
	for (int i = 0; i < n; ++i) {
		doingSomething(&number, string);
        --variable;
	}

	if (number == number_array[0])
        printf("Numbers are equal\n");
    if (number < number_array[0]) {
        number_array[0] = number;
        number = 15;
    } else {
        number = 0;
        number_array[0] = 20;
    }

    //this is a one line comment
    /*this
    is multiple line
    comment*/

	return 0;
}

void doingSomething(int number, int *number_array);

void doingSomething(int number, int *number_array) {
    printf("Printing %d and %d\n", number, number_array[0]);
}



a = b;          a != b
a = a + b;      a[0] = 5;
int *a = &b;    ++a;
a->b            a[i].b
if (a < b)      a && b
