#include <stdio.h>
#include <stdlib.h>

#define VALUE_1 4
#define VALUE_2 7.5

#define pf printf

int main(int argc, char *argv[]){
    pf("Coordinates x = %d; y = %f; \nthe sum of it is %f\nthe sandauga of it is %f", VALUE_1, VALUE_2, VALUE_1+VALUE_2, VALUE_1*VALUE_2);
    return 0;
}
