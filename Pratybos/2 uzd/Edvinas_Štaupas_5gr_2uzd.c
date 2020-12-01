//Edvinas Staupas 5 grupe 2 uzd 2 uzd
//Parašyti funkciją, kuri atspausdina kiekvienos eilutės ilgiausią žodį.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_capacity 256
#define file_name 256
#define max_ignore 1024-256

void ilg(char buffer[], char word[]);

int main (int argc, char *argv[]) {
    char data[file_name], rez[file_name];
    if (argc != 3){
		printf("Error! Please specify two file names where first one is data file and second one is results file.\n");
		printf("Usage: 2.exe file_name file_name (replace file_name with actual name)\n");
		return 0;
	}
    if(strlen(argv[1]) > 256){
        printf("Error! Please specify the name of the data file that is less than 256 symbols long.\n");
        return 0;
    }
    if(strlen(argv[2]) > 256){
        printf("Error! Please specify the name of the results file that is less than 256 symbols long.\n");
        return 0;
    }
    int len;
    const char txt[5] = ".txt";
    len = strspn(txt, argv[1]);
    len += strspn(txt, argv[2]);
    if(len != 8) {
        printf("Error! Please specify .txt file.\nProgram terminated.\n");
        return 0;
    }
    strcpy(data, argv[1]);
    strcpy(rez, argv[2]);
    int n, m, d[2];
    char buffer[max_capacity], ignore[max_ignore];
    FILE *fd;
    FILE *fr;
    fd = fopen(data, "r");
    if(NULL == fd) {
        printf("Error! Could not find data file.\nProgram terminated.\n");
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
    fclose(fd);
    fclose(fr);
    return 0;
}

void ilg (char buffer[], char word[]){
    int i = 0, didziausias = 0, i1 = 0, i2 = 0, ilgis = 0;
    int d[2]; d[0] = 0; d[1] = 0;
    while(buffer[i] != '\n' && i < 256) {
        if(i >= strlen(buffer) - 2) {//jeigu liko maziau nei 2 simboliai
            if(buffer[i] != ' ') {
                ++ilgis;
                i2 = i;
            }
            if(ilgis > didziausias) {
                didziausias = ilgis;
                d[0] = i1;
                d[1] = i2;
            }
        } else if(buffer[i] != ' ') {//jeigu liko daugiau nei du simboliai ir ne tarpas
            ++ilgis;
            i2 = i;
        } else {
            if(ilgis > didziausias) {//jeigu liko daugiau nei du simboliai ir tarpas
                didziausias = ilgis;
                d[0] = i1;
                d[1] = i2;
            }
            ilgis = 0;
            i1 = i + 1;
        }
        ++i;
    }
    int l = 0;
    for(int i = d[0]; i <= d[1] && i <= 254; ++i){
        word[l] = buffer[i];
        ++l;
    }
    word[l] = '\0';
}

