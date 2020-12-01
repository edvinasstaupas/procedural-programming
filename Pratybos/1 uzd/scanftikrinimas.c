//Edvinas Staupas 5 grupe 1 uzd 5 uzd
//suskaiciuoti kiek lyginiu sekos nariu yra teigiami
#include<stdio.h>
#include<stdlib.h>
main ()
{
    int i = 0, number[10] = {0};
    char buf[128] = {0};

    for (i = 0; i < 10; i++)
    {
      printf("Please input number %d : ", i+1);

         while(scanf("%d", &number[i]) != 1)
      {
         scanf("%s", &buf);
         printf("Sorry, [%s] is not a number. Please input number %d : ", &buf, i);
      }
    }

    for (i = 0; i < 10; i++)
    {
    printf("\n Number %d is %d", (10-i), number[9-i]);
    }

    return EXIT_SUCCESS;
}
