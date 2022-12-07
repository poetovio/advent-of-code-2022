#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int bufferLength = 5000;

void polnjenjeVrstice(char* vrstica, char c) {
    for(int i = 1; i < 4; i++) {
        vrstica[i - 1] = vrstica[i];
    }
    vrstica[3] = c;
}


int poisciZacetek(char* buffer) {
        char* razlicneCrke = (char*)malloc(4 * sizeof(char));
        
        for(int i = 0; i < 4; i++) {
            razlicneCrke[i] = buffer[i];
        }

        for(int i = 4; i < strlen(buffer); i++) {
            bool jeNasel = true;
            polnjenjeVrstice(razlicneCrke, buffer[i]);

            for(int j = 0; j < strlen(razlicneCrke); j++) {
                for(int k = j + 1; k < strlen(razlicneCrke); k++) {
                    if(razlicneCrke[j] == razlicneCrke[k]) {
                        jeNasel = false;
                    }
                }
            }

            if(jeNasel) {
                return i + 1;
            }
        }
        return -1;
}

int main() {

    FILE *file;

    file = fopen("input.txt", "r");
    char buffer[5000];

    int stevec = 0;

    while(fgets(buffer, bufferLength, file)) {
        stevec = poisciZacetek(buffer);
    }

    printf("Prvi del -> %d\n", stevec);

    return 0;
}