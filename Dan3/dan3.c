#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int bufferLength = 255;

int main() {

    FILE *file;

    file = fopen("input.txt", "r");
    char buffer[255];

    int stevec = 0;

    while(fgets(buffer, bufferLength, file)) {

        int vmesniStevec = 0;
        char* prviDel = (char*)malloc(strlen(buffer) * sizeof(char));
        char* drugiDel = (char*)malloc(strlen(buffer) * sizeof(char));

        bool jeNasel = true;

        for(int i = 0; i < strlen(buffer) / 2; i++) {
            prviDel[i] = buffer[i];
            vmesniStevec++;
        }
        for(int j = 0; j < strlen(buffer); j++) {
            drugiDel[j] = buffer[vmesniStevec];
            vmesniStevec++;
        }

        for(int i = 0; i < strlen(prviDel) && jeNasel; i++) {
            for(int j = 0; j < strlen(drugiDel) && jeNasel; j++) {
                if(prviDel[i] == drugiDel[j]) {

                    int vrednost = drugiDel[j];
                    
                    if(isupper(drugiDel[j])) {
                        stevec += (vrednost - 38);
                    } else {
                        stevec += (vrednost - 96);
                    }

                    jeNasel = false;
                }
            }
        }

        free(prviDel);
        free(drugiDel);
    }

    printf("Prvi del -> %d\n", stevec);

    fclose(file);

    return 0;

}