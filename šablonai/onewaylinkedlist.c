#include <stdlib.h>
#include <stdio.h>

struct el {
    int duom;
    struct el *kitas;
};

void PrintList( struct el *elem );
void PrintElem( struct el *elem );

int main () {
    int i, k;
    struct el *pradzia, *pabaiga, *elem, *elemk;
    pradzia = NULL;
    pabaiga = NULL;
    elem = (struct el *) malloc ( sizeof ( struct el ) );
    elem -> duom = 1;
    elem -> kitas  = NULL;
    pradzia = elem;
    pabaiga = elem;

    // naujas elementas pabaigoj
    int new_elem = 5;
    elem = (struct el *) malloc ( sizeof ( struct el ) );
    elem -> duom = new_elem;
    elem -> kitas = NULL;
    pabaiga -> kitas = elem;
    pabaiga = elem;

    //naujas elementas pradzioj
    elem = (struct el *) malloc( sizeof(struct el));
    elem->duom = 8;
    elem->kitas = pradzia;
    pradzia = elem;

    /*
    //Elemento įterpimas sąrašo viduje, po k-ojo elemento
    //NEVEIKIA
    elem = pradzia;
    elemk = (struct el *) malloc (sizeof(struct el));
    k = 3;
    elem = pradzia;
    i = 2;
    while ( i < k && elem != NULL)    {
        elemk = elemk->kitas;
        i++;
    }
    if( i == k )
        printf ("Rodykle nukreipta i %d-aji elementa.\n", k);
    else
        printf("Sarase yra maziau nei %d elementu.", k);
    elem = (struct el *) malloc (sizeof(struct el));
    elem -> duom = 7;
    elem -> kitas  = elemk -> kitas;
    elemk -> kitas = elem;
*/




    elem = pradzia;
    i = 2, k = 4;
    /*while ( i < k && elem != NULL){
        elem = elem->kitas;
        i++;
    }
    if( i == k )
        printf ("Rodykle nukreipta i %d-aji elementa.\n", k);
    else
        printf("Sarase yra maziau nei %d elementu.", k);
    */


    //spausdinimas nuo pradzios
    elem = pradzia;
    while ( elem != NULL )  {
        printf("%d", elem->duom);
        elem = elem -> kitas;
    }


    printf("\n");
    //spausdinimas nuo pabaigos
    PrintList(pradzia);
    printf("\n");
    PrintElem(pradzia);
    return 0;
}

void PrintList( struct el *elem ) {
    if (elem != NULL){
        PrintList( elem->kitas );
        printf( "%d", elem->duom );
    }
}

void PrintElem( struct el *elem ) {
    if (elem != NULL){
        PrintElem( elem->kitas );
        if(elem->duom == 5)
            printf( "a%d", elem->duom );
    }
}
