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

#define max_size 1016

typedef struct words {
	char word[max_size];
	int count;
} words;

int find (char b[], words c[], int m);

int main(){
    //data
    char a[max_size];
    words b[max_size], c[max_size];
    int i = 0, e = 0, j = 0, m = 0, l = 0, p, count_enter = 0;
    printf("Input your text and end it with three enters:\n");
    //read
    while(i < max_size) {
        scanf("%c", &a[i]);
        if(a[i] == '\n' && count_enter == 2) {
            break;
        } else if(a[i] == '\n' && count_enter == 1) {
            ++count_enter;
            printf("If you press enter one more time you will end input.\n");
        } else if(a[i] == '\n')
            ++count_enter;
        else
            count_enter = 0;
        ++i;
            if(i == max_size){
                printf("You reached maximum size which is %d.\n", max_size);
                break;
        }
    }
    //calculate
    //separate to words
    if (i == max_size)
        p = i;
    else if (i == max_size - 1)
        p = i - 1;
    else
        p = i - 2;
    for(l = 0; l < p; ++l) {//NEVEIKIA
        if(a[l] >= 'a' && a[l] <= 'z' || a[l] >= 'A' && a[l] <= 'Z' || a[l] >= '0' && a[l] <= '9') {
            b[j].word[e] = a[l];
            ++e;
        } else {
            if(a[l] >= 'a' && a[l] <= 'z' || a[l] >= 'A' && a[l] <= 'Z' || a[l] >= '0' && a[l] <= '9') {
                e = 0;
                ++j;
            }
        }
    }
    //calculate occurances and move to structures arrays
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
    //sort by occurances high to low and alphabetically a to z / 1 to 9 etc.
    for(i = 0; i < m + 1; ++i) {
        for (int g = i + 1; g < m + 1; ++g){
            if(c[i].count < c[g].count || c[i].count == c[g].count && c[i].word > c[g].word){
                words temp = c[i];
                c[i] = c[g];
                c[g] = temp;
            }
        }
    }
    //print out
    int lastcount;
    if(m > 5)
        lastcount = c[4].count;
    else
        lastcount = c[m-1].count;
    i = 0;
    while(c[i].count >= lastcount) {
        printf("%s was used %d times.\n", c[i].word, c[i].count);
        ++i;
    }
    return 0;
}
//function to find words that have already been used
int find (char b[], words c[], int m){
    for(int j = 0; j < m; ++j) {
            if(strcmp(b, c[j].word) == 0){
                return j;
            }
    }
    return -1;
}
