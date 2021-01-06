#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 30
#include "linkedList.h"
//n3. Sudaryti vienpusá sàraðà. Paraðyti procedûrà, kuri áterpia prieð numeriu nurodytà
//elementà naujà elementà. Jeigu tokio elemento nëra, turi bûti iðvestas atitinkamas praneðimas


void Print_list( node_s *head)
{
    printf("Spausdiname sarasa:\n");
    node_s *tmp = head;
    int i = 1;
    if(head != NULL)
        while( tmp != NULL)
        {
            printf("%d elemento reiksme: %d\n", i, tmp->value);
            i++;
            tmp = tmp->next;
        }
    else
        printf("Saraso nera\n");
    printf("\n");
}

void Create_new_node( int value, node_s **list)///paduodu reiksme ir pointeri i pointeri i tam tikra saraso elementa
{
    node_s *tmp = malloc(sizeof(node_s));///laikinas pointeris
    tmp->value = value;
    tmp->next = NULL;
    *list = tmp;// duota vieta yra pakeiciama
}

void Create_list( int n, node_s **head)
{
    if( n<1)//jei dydis 0 ar maziau, pasakom kad dydis permazas
    {
        printf("Saraso sukurti negalime, dydis pasirinktas permazas\n");
        return;
    }

    srand(time(NULL));//random number generator
    node_s *elem;//cia bus sukuriamos reiksmes
    node_s *tmp;// laikinas vienpusio saraso vieta
    Create_new_node( rand() % MAX, &tmp );///kuriame node, su random value ir siunciam adresa laikino node, t.y head
    *head = tmp;//issaugojam i head pradini tmp strukturos elementa t.y. saraso head
    if( n == 1)//jei sarasas buvo is 1 elemento - stabdom
        return;

    for( int i = 0; i < n-1; i++)//uzpildomas sarasas(n-1)nes nuo 0 pradedam
    {
        Create_new_node( rand() % MAX, &elem);//liekana, kad mazesnis ir nebaisus sk butu
        tmp->next = elem;
        tmp = tmp->next;
    }
}

void Insert_node( int pos, int value, node_s **head)//**nes reiksme noriu keist
{
    ///mano new_node  yra naujas, kuri terpsiu, tmp(turi visus kaip ir ir vaiksto)
    node_s *tmp = *head, *prev, *new_node;
    Create_new_node( value, &new_node);/// sukuria nauja saraso gabala?:D kuri iterps//

    if( *head != NULL) // tikrinam ar sarasas nera tuscias
    {
        int i = 1;
        while( tmp->next != NULL && i != pos)//sukam kol nera pabaigos ir nera reikiamo elemento
        {
            prev = tmp;
            tmp = tmp->next;
            i++;
        }
        if( i != pos)//pasibaige ciklas, - jei pabaiga, o ne pozicija
            printf("Elemento vietos sarase nera, iterpti negalime\n");

        else//vadinasi yra pozicija, tai iterpsime elementa
        {
            printf("Galima iterpti elementa\n");
            if( pos == 1)// jei pirmas, tai reik head pakeist
            {
               new_node->next = tmp;
               *head = new_node;
            }
            else//vidury- sujungiam pries elementa esanti nari su sekanciu
            {
                new_node->next = tmp;
                prev->next = new_node;
            }
        }
    }
    else
        printf("Sarasas yra tuscias\n");

}

void Delete_nodes( node_s **head)
{
    node_s *tmp = *head;//priskiriam saraso elemento head
    while ( *head != NULL)
    {
       *head = (*head)->next;//imam kita po jo elementa
       printf("Triname %d\n", tmp->value);
       free(tmp);//atlaisvinam pries tai buvusi
       tmp = *head;//priskiriam kito elemento reiksme
    }
}
