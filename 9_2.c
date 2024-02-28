#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1001

void replaceLetters(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
        if (str[i] == 'a') {
            str[i] = 'b';
        } else if (str[i] == 'b') {
            str[i] = 'a';
        }
        } else if (isupper(str[i])) {
        if (str[i] == 'A') {
            str[i] = 'B';
        } else if (str[i] == 'B') {
            str[i] = 'A';
        }
        }
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Not opening inputfile.\n");
        return 1;
    }

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Not opening outputfile.\n");
        fclose(inputFile);
        return 1;
    }

    char str[MAX_LENGTH];
    fscanf(inputFile, "%1000[^\n]", str);

    replaceLetters(str);

    fprintf(outputFile, "%s\n", str);

    fclose(inputFile);
    fclose(outputFile);

    printf("Done.\n");

    return 0;
}