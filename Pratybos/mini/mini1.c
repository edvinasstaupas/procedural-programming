#include<stdio.h>
main ()
{
    int a, max;
    printf("Iveskite skaiciu seka, besibaigiancia 0:\n");
    scanf("%d", &a);
    max = a;
    while(a!=0)
    {
        if(a>max)
        {
            max = a;
        }
        scanf("%d", &a);

        printf("%d", &a);
    }
    printf("didziausias %d", max);
    getchar();
}
