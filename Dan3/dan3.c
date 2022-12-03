#include <stdio.h>
#include <stdlib.h>

const int bufferLength = 255;

int main() {

    FILE *file;

    file = fopen("input3.txt", "r");
    char buffer[255];

    int stevec = 0;

    while(fgets(buffer, bufferLength, file)) {
        int i = 0;
        char c = buffer[i];

        while(c != '\n') {
            int steviloPojavitev = 0;
            int mesto = 0;

            int j = 0;
            char k = buffer[j];

            while(k != '\n') {
                if(c == k) {
                    steviloPojavitev++;
                    mesto = j;
                }

                j++;
                k = buffer[j];
            }

            int vrednost = buffer[mesto];

            printf("%d %d\n", vrednost, steviloPojavitev);

            if (steviloPojavitev > 1) {
                if('A' >= buffer[mesto] || buffer[mesto] <= 'Z') {
                    stevec += (vrednost - 38);
                } else {
                    stevec += (vrednost - 96);
                }
            }

            i++;
            c = buffer[i];
        }
    }

    printf("%s\n", "Zakaj mi ne pribntaš????");

    printf("Prvi del -> %d\n", stevec);

    fclose(file);

    return 0;

}