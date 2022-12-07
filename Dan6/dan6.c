#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int bufferLength = 5000;
const int del1 = 4;
const int del2_int = 14;

void polnjenjeVrstice(char* vrstica, char c) {
    for(int i = 1; i < 4; i++) {
        vrstica[i - 1] = vrstica[i];
    }
    vrstica[3] = c;
}

void polnjenjeVrstice2(char* vrstica, char c) {
    for(int i = 1; i < 14; i++) {
        vrstica[i - 1] = vrstica[i];
    }
    vrstica[13] = c;
}


int poisciZacetek(char* buffer, char* razlicneCrke) {
        
        for(int i = 0; i < 4; i++) {
            razlicneCrke[i] = buffer[i];
        }

        for(int i = 4; i < strlen(buffer); i++) {
            bool jeNasel = true;
            polnjenjeVrstice(razlicneCrke, buffer[i]);

            for(int j = 0; j < 4; j++) {
                for(int k = j + 1; k < 4; k++) {
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

int poisciSporocilo(char* buffer, char* razlicneCrke) {
        
        for(int i = 0; i < 14; i++) {
            razlicneCrke[i] = buffer[i];
        }

        for(int i = 14; i < strlen(buffer); i++) {
            bool jeNasel = true;
            polnjenjeVrstice2(razlicneCrke, buffer[i]);

            for(int j = 0; j < 14; j++) {
                for(int k = j + 1; k < 14; k++) {
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
    int stevec2 = 0;

    char* razlicneCrke = (char*)malloc(del1 * sizeof(char));
    char* del2 = (char*)malloc(14);

    while(fgets(buffer, bufferLength, file)) {
        stevec = poisciZacetek(buffer, razlicneCrke);
        stevec2 = poisciSporocilo(buffer, del2);
    }

    printf("Prvi del -> %d\n", stevec);
    printf("Drugi del -> %d\n", stevec2);

    free(razlicneCrke);
    free(del2);

    fclose(file);

    return 0;
}