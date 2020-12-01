#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 1016

typedef struct words {
	char word[1016];
	int count;
} words;

int find (char b[], words c[], int m);

int main(){
    //data
    char a[max_size], data[max_size], results[max_size];
    words b[max_size], c[max_size];
    int i = 0, e = 0, j = 0, m = 0, l = 0;
    pradzia:
    printf("Input your data and results file names:\n");
    scanf("%s", data);
    scanf("%s", results);
    if(strlen(data) > 20){
            printf("Error! Please specify the name of the data file that is less than 20 symbols long.\n\n");
            goto pradzia;
    } else if(strlen(results) > 20){
            printf("Error! Please specify the name of the results file that is less than 20 symbols long.\n\n");
            goto pradzia;
    }
    int len = 0;
    const char txt[5] = ".txt";
    len += strspn(txt, data);
    len += strspn(txt, results);
    if(len == 8) {
        printf("Succesfully scanned names of files: %s, %s.\n", data, results);
    } else {
        printf("Error! Please specify .txt file.\n\n");
        goto pradzia;
    }
    FILE *fd;
    FILE *fr;
    fd = fopen(data, "r");
    if(fd == NULL){
        printf("Error, could not find data file.\n\n");
        return 0;
    }
    fr = fopen(results, "w");
    if(fr == NULL){
        printf("Error, could not create results file.\nProgram terminated.\n");
        return 0;
    }
    //read
    while(!feof(fd)) {
        a[i] = fgetc(fd);
        ++i;
    }
    fclose(fd);
    //calculate
    //separate to words
    for(l = 0; l < i; ++l) {
        if(a[l] >= 'a' && a[l] <= 'z' || a[l] >= 'A' && a[l] <= 'Z' || a[l] >= '0' && a[l] <= '9') {
            b[j].word[e] = a[l];
            ++e;
        } else {
            if(a[l-1] >= 'a' && a[l-1] <= 'z' || a[l-1] >= 'A' && a[l-1] <= 'Z' || a[l-1] >= '0' && a[l-1] <= '9') {
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
        fprintf(fr, "%s pasikartojo %d\n", c[i].word, c[i].count);
        ++i;
    }
    fclose(fr);
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
