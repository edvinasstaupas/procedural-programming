//Įvesti sveikų skaičių seką, kurios pabaiga žymima skaičiumi 0. Išvesti lyginių narių
//(antro, ketvirto ir t.t.), kurie yra teigiami skaičiai, skaičių.

#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int a = 1, //skaicius
    n = 0, //sekos nariu skaicius
    sk = 0;//sekos lyginiu teigiamu nariu skaicius
    char buf[128] = {0};
    printf("Iveskite seka, kuri baigiasi 0:\n");
    while(a != 0)
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
