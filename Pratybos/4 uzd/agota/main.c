//n3. Sudaryti vienpus� s�ra��. Para�yti proced�r�, kuri �terpia prie� numeriu nurodyt�
//element� nauj� element�. Jeigu tokio elemento n�ra, turi b�ti i�vestas atitinkamas prane�imas
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
    node_s *head = NULL;
    int n, value, pos;

    printf("Si programa iterpia pries nurodyta numeri nauja elementa \n");
    printf("Prasome nurodyti sveika skaiciu, kokio dydzio saraso noresite \n");
    scanf("%d", &n);
    Create_list( n, &head);
    Print_list( head);

    printf("Iveskite pozicija, i kuria norite iterpti elementa, ir reiksme\n");
    scanf("%d %d",&pos,&value);
    Insert_node( pos, value, &head);

    printf("Spausdiname sarasa iterpus reiksme\n");
    Print_list( head);

    printf("Triname vienpusi sarasa\n");
    Delete_nodes( &head);

    printf("\n");
    Print_list( head);

    return 0;
}
