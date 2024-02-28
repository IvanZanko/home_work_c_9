#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1000

void removeDuplicatesAndSpaces(char* string) {
    int hash_table[256] = {0};
    int index = 0;

    for (int i = 0; i < strlen(string); i++) {
        char ch = string[i];

        if (isalpha(ch)) {
            ch = toupper(ch);
            if (hash_table[ch] == 0) {
                hash_table[ch] = 1;
                string[index] = ch;
                index++;
            }
        }
    }

    string[index] = '\0';
}

int main() {
    char string[MAX_STRING_LENGTH];

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Not opening file.\n");
        return 1;
    }
    fgets(string, MAX_STRING_LENGTH, file);
    fclose(file);

    removeDuplicatesAndSpaces(string);

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Failed to create file.\n");
        return 1;
    }
    fprintf(file, "%s", string);
    fclose(file);

    printf("output.txt created\n");

    return 0;
}