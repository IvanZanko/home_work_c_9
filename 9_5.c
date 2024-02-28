#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

void findLongestWord(const char* string, char* longestWord) {
    char word[MAX_STRING_LENGTH];
    char* token;
    int maxLength = 0;

    char* copy = strdup(string);

     token = strtok(copy, " ");

    while (token != NULL) {

        if (strlen(token) > maxLength) {
            maxLength = strlen(token);
            strcpy(longestWord, token);
        }

        token = strtok(NULL, " ");
    }

    free(copy);
}

int main(void) {
    char string[MAX_STRING_LENGTH];
    char longestWord[MAX_STRING_LENGTH];

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Not opening file.\n");
        return 1;
    }
    fgets(string, MAX_STRING_LENGTH, file);
    fclose(file);

    findLongestWord(string, longestWord);

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Failed to create file.\n");
        return 1;
    }
    fprintf(file, "%s", longestWord);
    fclose(file);

    printf("output.txt created\n");

    return 0;
}