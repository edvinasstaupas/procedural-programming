#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//funkcija jai perduoda masyva, randa to masyvo didziausia elementa ir visiem masyvo elemenmtam

#define array_size 10

void max (int a[], int n);

int main(){
    int a[array_size],//masyvas
        b = 5, c = 25,//masyvo elementu intervalas
        big;//didziausias masyvo elementas
    srand(time(NULL));//seed generavimui
    //masyvo elementu generavimas
    for(int i = 0; i < array_size; ++i){
        a[i] = rand() % (c - b + 1) + b;
    }
    //funckija, skirta rasti didziausia masyvo elementa
    max(a, array_size);
    //isspausdinamas masyvas
    for(int i = 0; i < array_size; ++i){
        printf("%d ", a[i]);
    }
    return 0;
}

void max (int a[], int n){
    int big = a[0];
    for(int i = 1; i < n; ++i){
        if(big < a[i]){
            big = a[i];
        }
    }
    for(int i = 0; i < array_size; ++i){
        a[i] = big;
    }
}
