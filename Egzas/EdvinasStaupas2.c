#include <stdlib.h>

// external global variables
extern void * ptr1;
extern void * ptr2;

// BLOCK_SIZE to be left unchanged; otherwise, provide your reasoning here ("changed, because ... ")
#define BLOCK_SIZE 4

/********************************************************************************************* 
Funkcija imagine turi prieigą prie kitur apibrėžtų dviejų globalių kintamųjų ptr1 ir ptr2 (žr. paveiksliuką), ir naudodamasi jais sukuria pavaizduotą konstrukciją (trijų elementų dinaminį masyvą bei papildomą kintamąjį) dinaminėje atmintyje. Laikykite, kad kiekvienos "dėžutės" talpa yra lygiai 4 baitai. Užpildykite visas pavaizduotas šešias "dėžutes" nurodytomis reikšmėmis: įkelkite į jų vidų paveiksliuke nurodytas (int) konstantas, arba atitinkamų "dėžučių" adresus (žr. nupieštas rodykles). Funkcijai baigus darbą, paveiksliuke pavaizduota konstrukcija turi būti paruošta naudojimui. Jeigu konstrukcijos sukūrimas neįmanomas, nustatykite ptr1 ir ptr2 reikšmes lygias NULL. Jeigu dėl techninių priežasčių negalite išsaugoti adresų informacijos 4 baituose, LEIDŽIAMA pakeisti viršuje apibrėžtą makrosą BLOCK_SIZE į tokį, su kuriuo galite dirbti, tačiau tokiu atveju privalu komentare įvardinti tokio pakeitimo priežastį (žr. kodą aukščau).

*********************************************************************************************/

void imagine () {
    int *box1, //pointeris
    *box2;//masyvas

    ptr1 = malloc(BLOCK_SIZE * 1);
    ptr2 = malloc(BLOCK_SIZE * 1);
    box1 = malloc(BLOCK_SIZE * 1);
    box2 = malloc(BLOCK_SIZE * 3);

    if(ptr1 == NULL || ptr2 == NULL || box1 == NULL || box2 == NULL) {
        ptr1 = NULL;
        ptr2 = NULL;
        free(box1);
        free(box2);
    }

    ptr1 = box1;
    box1 = box2;
    box2[0] = 4831;
    box2[1] = -568;
    box2[2] = (int) box1;
    ptr2 = &box2[2];  
}