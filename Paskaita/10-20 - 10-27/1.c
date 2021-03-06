#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_size 256

int find (char a, char b[], int m);
int main(int argc, char *argv[]){
    char a[max_size];
    char b[max_size];
    char enter;
    int i = 0;
    int m = 0;
    int count[max_size];
    for(i = 0; i < max_size; ++i) {
        count[i] = 0;
    }
    scanf("%255s", a);
    for(i = 0; i < strlen(a); ++i) {
        int k = find(a[i], b, m);
        if(k < 0){
            b[m] = a[i];
            ++count[m];
            ++m;
        } else {
            ++count[k];
        }
    }
    for(i = 0; i < m - 1; ++i) {
        for (int j = i + 1; j < m; ++j){
            if(count[i] < count[j]){
                int temp = count[i];
                count[i] = count[j];
                count[j] = temp;
                char one = b[i];
                b[i] = b[j];
                b[j] = one;
            }
        }
    }
    if(strlen(b) > 5){
        for(i = 0; i < 5; ++i) {
            printf("%c pasikartojo %d\n", b[i], count[i]);
        }
    } else {
        for(i = 0; i < strlen(b); ++i) {
            printf("%c pasikartojo %d\n", b[i], count[i]);
        }
    }
    return 0;
}
int find (char a, char b[], int m){
    for(int j = 0; j < m; ++j) {
            if(a == b[j]){
                return j;
            }
    }
    return -1;
}
