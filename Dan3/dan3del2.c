#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int bufferLength = 255;

int main() {

    FILE *file;

    file = fopen("input.txt", "r");
    char buffer[255];
    char buffer2[255];
    char buffer3[255];

    int stevec = 0;

    while(fgets(buffer, bufferLength, file)) {

        fgets(buffer2, bufferLength, file);
        fgets(buffer3, bufferLength, file);

        int vmesniStevec = 0;

        bool jeNasel = true;


        for(int i = 0; i < strlen(buffer) && jeNasel; i++) {
            for(int j = 0; j < strlen(buffer2) && jeNasel; j++) {
                for(int k = 0; k < strlen(buffer3) && jeNasel; k++) {
                    if(buffer[i] == buffer2[j] && buffer2[j] == buffer3[k]) {

                        int vrednost = buffer3[k];
                        
                        if(isupper(buffer3[k])) {
                            stevec += (vrednost - 38);
                        } else {
                            stevec += (vrednost - 96);
                        }

                        jeNasel = false;
                    }
                }
            }
        }
    }

    printf("Prvi del -> %d\n", stevec);

    fclose(file);

    return 0;

}