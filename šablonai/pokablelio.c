#include <stdio.h>
#include <string.h>
main (void) {
    char buffer[256];
    int ilgis = 0;
    scanf("%s", buffer);
    for(int i = 0; i < strlen(buffer); ++i){
        if(buffer[i] == '.' || buffer[i] == ',')
            ilgis = strlen(buffer) - i - 1;
    }
    printf("%d", ilgis);
    return 0; //
}
