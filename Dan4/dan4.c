#include <stdio.h>
#include <stdlib.h>

const int bufferLength = 255;

int main() {

    FILE *file;

    file = fopen("input.txt", "r");
    char buffer[255];

    int stevec = 0;
    int stevec2 = 0;

    while(fgets(buffer, bufferLength, file)) {
        stevec += igra(buffer[0], buffer[2]);
        stevec2 += igra2(buffer[0], buffer[2]);
    }

    printf("Part 1 -> %d\n", stevec);
    printf("Part 2 -> %d\n", stevec2);

    return 0;
}