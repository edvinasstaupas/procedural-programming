#include <stdio.h>
#include <stdlib.h>

#define max_capacity 30
#define max_number 100

struct words {
    char *string;
    int length;
};

int main () {
    int n, m, i, j;
    struct words *word = malloc(sizeof(struct words) * max_number);
    char matrix[max_capacity][max_capacity];
    char *data = "data.txt", 
    *mat = "matrix.txt", 
    *results = "res.txt";
    FILE *fd;
    FILE *fm;
    FILE *fr;


    fm = fopen(mat, "r");
    if(NULL == fd) {
        printf("Error! Could not find data file.\nProgram terminated.\n");
        return 0;
    }

    i = 0;
    j = 0;
    //printf("%d", i);
    while(!feof(fm)) {
        //printf("%d", i);
        fgets(matrix[i], max_capacity, fm);
        printf("%s", matrix[i]);
        ++i;
    }
    fclose(fm);
    int rows = i;
    int collums = 0;
    for(int i = 0; i < max_capacity; ++i) {
        ++collums;
        if(matrix[0][i] == '\n')
            break;
    }
    printf("\n%d %d\n", rows, collums);
    fd = fopen(data, "r");
    if(NULL == fd) {
        printf("Error! Could not find data file.\nProgram terminated.\n");
        return 0;
    }
    i = 0;
    
    while(1) {
        fgets(word[i].string, max_capacity, fd);
        word[i].length = 0;
        j = 0;
        while(word[i].string[j] != '\n') {
            ++j;
        }
        word[i].length = j;
        word[i].string[word[i].length] = 0;
        printf("%s %d\n", word[i].string, word[i].length);
        //++i;
        
        printf("a");

        //if(feof(fd))
        //    break;
    }
    
    int word_count = i;
    fclose(fd);
    /*fm = fopen(data, "r");
    if(NULL == fm) {
        printf("Error! Could not find matrix file.\nProgram terminated.\n");
        return 0;
    }
    fr = fopen(rez, "w");
    if(NULL == fr) {
        printf("Error! Could not create results file.\nProgram terminated.\n");
        fclose(fd);
        return 0;
    }
    while(1) {
        fgets(buffer, max_capacity, fd);
        if(strlen(buffer) == 255) {
            fgets(ignore, max_ignore, fd);
        }
        if(feof(fd)){
            break;
        }
        char word[max_capacity];
        ilg(buffer, word);
        fprintf(fr, "%s\n", word);
    }
    printf("Program succesfully ended.\n");
    */
    return 0;
}