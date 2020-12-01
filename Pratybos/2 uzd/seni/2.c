//Edvinas Staupas 5 grupe 2 uzd 2 uzd
//Parašyti funkciją, kuri atspausdina kiekvienos eilutės ilgiausią žodį.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_capacity 256
#define file_name 21
#define max_ignore 1024-256

void ilg(char buffer[], int d[]);

int main (int argc, char **argv ) {
    char data[file_name], rez[file_name];
    if (argc > 1){
            //txt tikrinimas
            /*int suc = 0;
            for(int i = 0; i < strlen(argv[1]); ++i){
                if(argv[1][i] == ".")
                {
                    if(argv[1][i+1] == "t" && argv[1][i+2] == "x" && argv[1][i+3] == "t"){
                        strcpy(data, argv[1]);
                        ++suc;
                        break;
                    }
                }
            }
            for(int i = 0; i < strlen(argv[2]); ++i){
                if(argv[2][i] == ".")
                {
                    if(argv[2][i+1] == "t" && argv[2][i+2] == "x" && argv[2][i+3] == "t"){
                        strcpy(rez, argv[2]);
                        ++suc;
                        break;
                    }
                }
            }
            if (suc == 2)
            else {
                printf("Error! Please specify .txt file.\n");
                return 0;
            }*/
            int len;
            const char txt[5] = ".txt";
            len = strspn(txt, argv[1]);
            len += strspn(txt, argv[2]);
            if(len == 8) {
                strcpy(data, argv[1]);
                strcpy(rez, argv[2]);
                printf("Succesfully scanned names of files: %s, %s.\n", data, rez);
            } else {
                printf("Error! Please specify .txt file.\nProgram terminated.\n");
                return 0;
            }
	} else {
		printf("Error! Please specify data and results file names.\nUsage: 2.exe file_name.txt file_name.txt (replace file_name with actual name).\nProgram terminated.\n");
		return 0;
	}
    int n, m, d[2], buf_ilg;
    char buffer[max_capacity], ignore[max_ignore];
    FILE *fd;
    FILE *fr;
    fd = fopen(data, "r");
    if(fd == NULL) {
        printf("Error! Could not find data file.\nProgram terminated.\n");
        return 0;
    }
    fr = fopen(rez, "w");
    if(fr == NULL) {
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
    fclose(fd);
    fclose(fr);
    printf("Program succesfully ended.\n");
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
