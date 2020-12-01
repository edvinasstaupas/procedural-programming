#include <stdio.h>
#include <stdlib.h>
int main(){
    unsigned long long a, b;
    int f = 1;
    printf("Iveskite du naturaliuosius skaicius atskirtus vienu tarpo zenklu: ");
    scanf("%llu %llu", &a, &b);
    for(int j = 0; j <= a || j <= b; ++j)
    {
        f = 1;
        for(int i = 1; i <= j; ++i) {
            f *= i;
        }
        if(f >= a && f <= b || f >= b && f <= a) {
            printf("%llu(%d!) ", f, j);
        }
    }
    return 0;
}
