//Edvinas Staupas 5 grupe 1 uzd 5 uzd
//isvesti sekos narius be pasikartojimu
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CAPACITY 10
#define WORD_CAPACITY 10

int ar (char a[], char b[], int m);

main ()
{
    // Lets say we have 3 words
    int n = 0;
    int m = 0;

    // Declaration of 2-D char array
    char a[50][20];
    char b[50][20];
    char temp[50];

    // Initialization of 2-D char array
    for(int i = 0; i < 5; ++i){ //|| n < 50
        scanf("%s", a[i]);
        ++n;
    }

    // print the words
    for(int i=0;i<=n;i++){
      for(int j=i+1;j<=n;j++){
         if(strcmp(a[i],a[j])>0){
            strcpy(temp,a[i]);
            strcpy(a[i],a[j]);
            strcpy(a[j],temp);
         }
      }
    }
    for(int i = 0; i < n; ++i){
        printf("%s\n", a[i]);
    }
/*
    for(int i = 0; i < n; ++i){
        printf("%s\n", a[i]);
        int k = ar (a[i], b, m);
        printf("%d\n", k);
        if (k < 0){
            strcpy (b[m], a[i]);
            ++m;
        }
    }*/
    return 0;
}
//15min
int ar (char a[], char b[], int m){
    for(int i = 0; i < m; ++i){
        if(strcmp(a, b[m]) == 0)
            return 1;
    }
    return -1;
}
