#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int bufferLength = 255;

int prviDel(int prvo, int drugo, int tretje, int cetrte) {
    if(prvo >= tretje && drugo >= cetrte || prvo <= tretje && drugo <= cetrte) {
        return 1;
    } else {
        return 0;
    }
}

int drugiDel(int prvo, int drugo, int tretje, int cetrto) {
    if(drugo >= tretje && prvo <= cetrto) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    FILE *file;

    file = fopen("input2.txt", "r");
    char buffer[255];

    int stevec = 0;
    int stevec2 = 0;

    int* stevila = (int*)malloc(4 * sizeof(int));

    while(fgets(buffer, bufferLength, file)) {
        char* token = strtok(buffer, ",");

        while(token != NULL) {
            char* token2 = strtok(token, "-");

            while(token2 != NULL) {
                printf("%s\n", token2);

                token2 = strtok(NULL, "-");
            }
            token = strtok(NULL, ",");
        }
    }

    printf("Part 1 -> %d\n", stevec);
    printf("Part 2 -> %d\n", stevec2);

    return 0;
}