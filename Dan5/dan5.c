#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int bufferLength = 255;

int main() {

    FILE *file;

    file = fopen("input2.txt", "r");
    char buffer[255];

    int stevec = 0;
    int stevec2 = 0;

    int* stevila = (int*)malloc(4 * sizeof(int));

    while(fgets(buffer, bufferLength, file)) {
        
        

    }

    printf("Part 1 -> %d\n", stevec);
    printf("Part 2 -> %d\n", stevec2);

    return 0;
}