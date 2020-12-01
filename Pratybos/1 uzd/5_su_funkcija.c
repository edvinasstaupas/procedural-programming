//Edvinas Staupas 5 grupe 1 uzd 5 uzd

#include<stdio.h>
main ()
{
    int sk = skaiciavimas();
    printf("%d", sk);//isvedimas
    getchar();
}

int skaiciavimas ()
{
    int a, //skaicius
    n = 0, //sekos nariu skaicius
    sk = 0;//sekos lyginiu teigiamu nariu skaicius
    printf("Iveskite seka, kuri baigiasi 0:\n");
    scanf("%d", &a);//nuskaitymas
    while(a!=0)//ciklas
    {
        n++;
        if(n % 2 == 0 && a > 0)
        {
			sk++;//uzduoties skaiciavimas
        }
        scanf("%d", &a);
    }
    return sk;
}
