//Edvinas Staupas 5 grupe 1 uzd 5 uzd
//suskaiciuoti kiek lyginiu sekos nariu yra teigiami
#include<stdio.h>
#include<stdlib.h>
main ()
{
    int a, //skaicius
    n = 0, //sekos nariu skaicius
    sk = 0;//sekos lyginiu teigiamu nariu skaicius
    char e;//enter ivedimas
    printf("Iveskite seka, kuri baigiasi 0:\n");
    /*while(a != 0)
    {
        if(scanf("%d%c", &a, &e) == 2 && e == '\n')
        {
            n++;
                if(n % 2 == 0 && a > 0)
                {
                    sk++;//uzduoties skaiciavimas
                }
        }
        else
        {
            printf("Neteisinga ivestis\n");
        }

    }*/
    char buf[128] = {0};
    while (a != 0)
    {
        //while(scanf("%d%c", &a, &e) != 2 || e != '\n')
        while(scanf("%d", &a) != 1)
        {
            scanf("%s", &buf);
            printf("%s yra netinkama ivestis, iveskite skaiciu:\n", &buf);
        }
        n++;
        if(n % 2 == 0 && a > 0)
        {
            sk++;//uzduoties skaiciavimas
        }
    }

    /*while(1)
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
*/
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
