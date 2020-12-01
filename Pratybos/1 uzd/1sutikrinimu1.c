//Edvinas Staupas 5 grupe 1 uzd 5 uzd
//suskaiciuoti kiek lyginiu sekos nariu yra teigiami
#include<stdio.h>
#include<stdlib.h>
main ()
{
    int a, //skaicius
    n = 0, //sekos nariu skaicius
    sk = 0;//sekos lyginiu teigiamu nariu skaicius
    printf("Iveskite seka, kuri baigiasi 0:\n");
    while(1)
    {
        if(scanf("%d", &a) != 1)
        {
            printf("b\n");
        }
        else
        {
            if(a != 0)
            {
                n++;
                if(n % 2 == 0 && a > 0)
                {
                    sk++;//uzduoties skaiciavimas
                }
            }
            else
                break;
        }
    }

    /*while(1)//ciklas
    {
        /*if(scanf("%d", &a) != 1)
        {
            continue;
        }
        if(a == 0)
        {
            break;
        }
        n++;
        if(n % 2 == 0 && a > 0)
        {
			sk++;//uzduoties skaiciavimas
        }
        if(scanf("%d", &a) != 1)
            continue;
        printf("%d\n", a);
    }
    */
    printf("%d", sk);//isvedimas
    getchar();
}
