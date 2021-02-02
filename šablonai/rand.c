#include <stdio.h>

int main()
{
    int lower = 5, upper = 7;

    // Use current time as
    // seed for random generator
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower;
    printf("%d ", num);
}
