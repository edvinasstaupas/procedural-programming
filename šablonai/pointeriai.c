#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int a = 10;
    int *b = &a;
    printf("%d, %d, %d, %d\n", a, *b, b, &a);
    return 0;
}
b = &a;
a = *b;
a yra kintamasis (a)
b yra adresas (&a)
b yra a adresas
a yra tai, kas yra b adrese
