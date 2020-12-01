//Edvinas Staupas 5 grupe 1 uzd 5 uzd
//suskaiciuoti kiek lyginiu sekos nariu yra teigiami
//https://stackoverflow.com/questions/21401136/scanf-check-in-while-loop-to-restrict-integer-input
#include<stdio.h>
#include<stdlib.h>
main ()
{
    int a, //skaicius
    n = 0, //sekos nariu skaicius
    sk = 0;//sekos lyginiu teigiamu nariu skaicius
    char buf[128] = {0};
    printf("Iveskite seka, kuri baigiasi 0:\n");
    while (a != 0)
    {
        while(scanf("%d", &a) != 1)//ivestis ir tikrinimas
        {
            scanf("%s", &buf);
            printf("[%s] yra netinkama ivestis, iveskite skaiciu:\n", &buf);
        }
        n++;
        if(n % 2 == 0 && a > 0)
        {
            sk++;//uzduoties skaiciavimas
        }
    }
    printf("Atsakymas: %d", sk);//isvedimas
    return 0;
}
