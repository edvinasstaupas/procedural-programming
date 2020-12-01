#include <stdio.h>
#include <stdlib.h>

int main(){
    int x[1000];
    int s, n;
    printf("Please enter s and n:\n");
    scanf("%d%d", &s, &n);
    printf("Please enter positive integers:\n");
    for(int i = 0; i < n; ++i){
        scanf("%d", &x[i]);
    }
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(x[i] * x[j] == s)
                printf("%d %d\n", x[i], x[j]);
        }
    }
    return 0;
}
