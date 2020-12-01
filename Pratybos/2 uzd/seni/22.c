//Edvinas Staupas 5 grupe 2 uzd 2 uzd
//Parašyti funkciją, kuri atspausdina kiekvienos eilutės ilgiausią žodį.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_capacity 256
#define file_name 256
#define max_ignore 1024-256

void ilg(char buffer[], int d[]);

int main (int argc, char **argv) {
    char data[file_name], rez[file_name];
    if (argc > 1){
        //if(strchr(argv[1], ".txt") && strchr(argv[2], ".txt")) {
        printf("%d, %d\n",strlen(argv[1]), strlen(argv[2]));
        if(strlen(argv[1]) > 20){
            printf("Error! Please specify the name of the data file that is less than 20 symbols long.\n");
            return 0;
        } else if(strlen(argv[2]) > 20){
            printf("Error! Please specify the name of the results file that is less than 20 symbols long.\n");
            return 0;
        } else {
            //printf("Error! Please specify .txt file.\n");
            strcpy(data, argv[1]);
            strcpy(rez, argv[2]);
            printf("Succesfully scanned names of files: %s, %s\n", data, rez);
        }
	} else {
		printf("Error! Please specify db file name.\n");
		printf("Usage: 2.exe file_name file_name (replace file_name with actual name)\n");
		return 0;
	}
    int n, m, d[2], buf_ilg;
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
    while(!feof(fd)) {
        fgets(buffer, max_capacity - 1, fd);
        if(buf_ilg = strlen(buffer) == 255) {
            fgets(ignore, max_ignore, fd);
        }
        ilg(buffer, d);
        for(int i = d[0]; i <= d[1] && i <= 255; ++i){
            fprintf(fr, "%c", buffer[i]);
        }
        fprintf(fr, "\n");
    }
    printf("Program succesfully ended.\n");
    fclose(fd);
    fclose(fr);
    return 0;
}

void ilg (char buffer[], int d[]){
    int i = 0, didziausias = 0, i1 = 0, i2 = 0, ilgis = 0;
    while(buffer[i] != '\n' && i < 256) {
        if(i >= strlen(buffer) - 2) {
            if(buffer[i] != ' ') {
                ++ilgis;
                i2 = i;
            }
            if(ilgis > didziausias) {
                didziausias = ilgis;
                d[0] = i1;
                d[1] = i2;
            }
        } else if(buffer[i] != ' ') {
            ++ilgis;
            i2 = i;
        } else {
            if(ilgis > didziausias) {
                didziausias = ilgis;
                d[0] = i1;
                d[1] = i2;
            }
            ilgis = 0;
            i1 = i + 1;
        }
        ++i;
    }
}

