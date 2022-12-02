#include <stdio.h>
#include <stdlib.h>

const int bufferLength = 255;

int igra(char a, char b) {
    switch (a)
    {
    case 'A': // Rock
        switch (b)
        {
        case 'X': // Rock
            return 4;
            break;

        case 'Y':
            return 8;
            break;
        
        default:
            return 3;
            break;
        }
        break;

    case 'B': // Paper
        switch (b)
        {
        case 'X': // Rock
            return 1;
            break;

        case 'Y':
            return 5;
            break;
        
        default:
            return 9;
            break;
        }
        break;
    
    default:
        switch (b)
        {
        case 'X': // Rock
            return 7;
            break;

        case 'Y':
            return 2;
            break;
        
        default:
            return 6;
            break;
        }
        break;
    }
}

int igra2(char a, char b) {
        switch (a)
    {
    case 'A': // Rock
        switch (b)
        {
        case 'X': // Lose
            return 3;
            break;

        case 'Y':
            return 4;// Draw
            break;
        
        default:
            return 8; //Win
            break;
        }
        break;

    case 'B': // Paper
        switch (b)
        {
        case 'X': // Lose
            return 1;
            break;

        case 'Y':
            return 5;
            break;
        
        default:
            return 9;
            break;
        }
        break;
    
    default:
        switch (b)
        {
        case 'X': // Rock
            return 2;
            break;

        case 'Y':
            return 6;
            break;
        
        default:
            return 7;
            break;
        }
        break;
    }
}

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