#include <stdio.h>
#include <stdlib.h>
//skaiciaus faktoriala suskaiciuoja
int main(){
    int a, f = 1;
    scanf("%d", &a);
    for(int i = 1; i <= a; ++i)
    {
        f = f * i;
    }
    printf("%d", f);
    return 0;
}
