//2. vartotojas įveda tekstą (laikome, kad gali būti kelios pastraipos, ir teksto pabaigą žymi TRYS '\n' simboliai
//einantys iš eilės; po antrojo reikia atspausdinti klausimą/perspėjimą, ar/jog baigsis programa;
//vartotojas tuomet gali kažką parašyti - programa tęsiasi - arba paspausti ENTER - programa baigiasi).
//Reikia atspausdinti PENKIS dažniausiai pasikartojančius žodžius, laikant, kad žodžius sudaro raidės ir skaitmenys, o kiti
//simboliai yra skirtukai tarp žodžių;
//jeigu keli žodžiai turi vienodą dažnį ir pretenduoja į penktą vietą, spausdiname juos visus, kitaip tariant, atspausdiname
//NE MAŽIAU nei penkis žodžius (su sąlyga, kad bent tiek skirtingų buvo
//įvesta), ir NE DAUGIAU žodžių, nei tų, kurie kartojasi bent tiek kartų, kiek kartojasi penktas pagal dažnį žodis

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 500

typedef struct words {
	char word[max_size];
	int count;
} words;

int find (char b[], words c[], int m);

int main(){
    char a[max_size];
    words b[max_size], c[max_size];
    int i = 0, e = 0, j = 0, m = 0;
    printf("Input your text and end it with three enters:\n");
    while(i < max_size) {
        scanf("%c", &a[i]);
        if(i >= 2){
            if(a[i] == '\n' && a[i-1] == '\n' && a[i-2] == '\n') {
                break;
            } else if(a[i] == '\n' && a[i-1] == '\n' && a[i-2] != '\n') {
                printf("If you press enter one more time you will end input\n");
            }
        } else if (i < 2){
            if(a[i] == '\n') {
                --i;
            }
        }
        ++i;
    }

    for(i = 0; i < strlen(a) - 3; ++i) {
        if(a[i] != ' ' && a[i] != '\n') {
            b[j].word[e] = a[i];
            ++e;
        } else if(a[i] != ' ' || a[i] != '\n') {
            e = 0;
            ++j;
        }
    }


    for(i = 0; i < j + 1; ++i) {
        int k = find(b[i].word, c, m);
        if(k < 0){
            c[m] = b[i];
            ++c[m].count;
            ++m;
        } else {
            ++c[k].count;
        }
    }

        for(i = 0; i < m + 1; ++i) {
        for (int g = i + 1; g < m + 1; ++g){
            if(c[i].count < c[g].count){
                words temp = c[i];
                c[i] = c[g];
                c[g] = temp;
            }
        }
    }


    if(m > 5){
        for(i = 0; i < 5; ++i) {
            printf("%s pasikartojo %d\n", c[i].word, c[i].count);
        }
    } else {
        for(i = 0; i < m; ++i) {
            printf("%s pasikartojo %d\n", c[i].word, c[i].count);
        }
    }
    return 0;
}


int find (char b[], words c[], int m){
    for(int j = 0; j < m; ++j) {
            if(strcmp(b, c[j].word) == 0){
                return j;
            }
    }
    return -1;
}
