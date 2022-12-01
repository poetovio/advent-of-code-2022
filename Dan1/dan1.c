#include <stdio.h>
#include <stdlib.h>

const int bufferLength = 255;

int main() {

    FILE *file;

    file = fopen("input.txt", "r");
    char buffer[255];

    int* tabelaNajboljsih = (int*)calloc(3, sizeof(int));

    int stevec = 0;
    int vmesnaVrednost = 0;


    while(fgets(buffer, bufferLength, file)) {
        if (buffer[0] == '\n') {
            if(vmesnaVrednost > stevec) {
                stevec = vmesnaVrednost;
            }
        

            for(int i = 0; i < 3; i++) {
                if(vmesnaVrednost > tabelaNajboljsih[i]) {
                    if (i < 2) {
                        for(int j = i; j >= 0; j--) {
                            tabelaNajboljsih[j + 1] = tabelaNajboljsih[j];
                        }
                    }
                    tabelaNajboljsih[i] = vmesnaVrednost;
                    break;
                }
            }

            vmesnaVrednost = 0;
        } else {
            vmesnaVrednost += atoi(buffer);
        }
    }

     if(vmesnaVrednost > stevec) {
                stevec = vmesnaVrednost;
            }
        

            for(int i = 0; i < 3; i++) {
                if(vmesnaVrednost > tabelaNajboljsih[i]) {
                    if (i < 2) {
                        for(int j = i; j >= 0; j--) {
                            tabelaNajboljsih[j + 1] = tabelaNajboljsih[j];
                        }
                    }
                    tabelaNajboljsih[i] = vmesnaVrednost;
                    break;
                }
            }

    int top = 0;

    for(int i = 0; i < 3; i++) {
        top += tabelaNajboljsih[i];
    }

    printf("Del 1 -> %d\n", stevec);
    printf("Del 2 -> %d\n", top);


    free(tabelaNajboljsih);
    fclose(file);

    return 0;
}