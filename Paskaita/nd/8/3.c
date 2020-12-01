#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define array_size 10

int calculate (char number[]);

int main(){
    FILE *fd;
    char data[array_size] = "in.txt";
    //char number[array_size] = "1000,001";
    char number[7][array_size] = {"14,999", "15,000", "152,8454", "999,999", "1000,000", "1000,001"};
    int after, integer;
    for(int e = 0; e < 7; ++e){
        assert(calculate(number[e]));
    return 0;
}

int calculate (char number[]){
    start:
    after = 0;
    /*if (fd = fopen (data, "r") == NULL){
        printf("Error! Could not open data file\n");
        return 0;
    }*/
    printf("%s\n", number);
    //int i = 0;
    //fgets(number, array_size - 1, fd);
    //printf("%s\n", number);
    integer = atoi(number);
    printf("%d\n\n", sizeof(integer)-1);
    printf("%d %s %d\n", integer, number, strlen(number));
    for(int i = 0; i < strlen(number); ++i){
        if(number[i] < '0' && number[i] != ',' || number[i] > '9' && number[i] != ','){
            printf("Wrong input (%c)! Please enter new data file name and the program will be reset.\n", number[i]);
            scanf("%s", data);
            number[array_size] = "0";
            goto start;
        } else if (number[i] == ','){
            after = strlen(number) - i - 1;
            break;
        }
    }
    printf("%d\n", after);
    if(after > 3){
        printf("Wrong input (Too many numbers after \",\")! Please enter new data file name and the program will be reset.\n");
        scanf("%s", data);
        number[array_size] = "0";
        goto start;
    } else if (integer < 15) {
        printf("Wrong input (Number is less than 15)! Please enter new data file name and the program will be reset.\n");
        scanf("%s", data);
        number[array_size] = "0";
        goto start;
    } else if(integer > 1000 || after + sizeof(integer) - 1 > 6){
        printf("%d + %d = %d\n", after, sizeof(integer) - 1, after+sizeof(integer)-1);
        printf("Wrong input (Number is bigger than 1000)! Please enter new data file name and the program will be reset.\n");
        scanf("%s", data);
        number[array_size] = "0";
        goto start;
    }
    if(after != 0)
        printf("Number is %d long\n", strlen(number) - 1);
    else
        printf("Number is %d long\n", strlen(number));
    }
}
