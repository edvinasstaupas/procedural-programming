//n3. Sudaryti vienpusá sàraðà. Paraðyti procedûrà, kuri áterpia prieð numeriu nurodytà
//elementà naujà elementà. Jeigu tokio elemento nëra, turi bûti iðvestas atitinkamas praneðimas
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
