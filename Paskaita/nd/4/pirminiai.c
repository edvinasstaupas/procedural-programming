#include <stdio.h>
#include <stdlib.h>

#define array_size 256

int main(){
    int prime[array_size], l = 0;
    for(int sk = 1; sk < array_size; ++sk)
    {
        int count = 0;
        for(int i = 1; i <= sk; ++i) {
            if(sk % i == 0)
                ++count;
        }
        if (count == 2)
            prime[l] = sk;
            ++l;
    }
    return 0;
}
