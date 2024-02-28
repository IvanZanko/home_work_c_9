#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 101


int isUnique(char* word, char c) {
    int count = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == c) {
             count++;
             if (count > 1) {
                return 0; //
             }
        }
     }
    return count == 1; //
}


void processFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening\n");
        return;
     }

    char word1[MAX_LENGTH], word2[MAX_LENGTH];
    fscanf(file, "%s %s", word1, word2);
    fclose(file);
    char uniqueChars[MAX_LENGTH];
    int uniqueCharsCount = 0;
    for (int i = 0; i < strlen(word1); i++) {
        if (isUnique(word2, word1[i])) {
            uniqueChars[uniqueCharsCount++] = word1[i];
        }
    }

    for (int i = 0; i < uniqueCharsCount - 1; i++) {
        for (int j = i + 1; j < uniqueCharsCount; j++) {
            if (uniqueChars[i] > uniqueChars[j]) {
                char temp = uniqueChars[i];
                uniqueChars[i] = uniqueChars[j];
                uniqueChars[j] = temp;
            }
        }
    }

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Not create file\n");
        return;
    }

    for (int i = 0; i < uniqueCharsCount; i++) {
        fprintf(outputFile, "%c ", uniqueChars[i]);
    }

    fclose(outputFile);
    printf("File output.txt created.\n");
}

int main(void) {
    processFile("input.txt");

    return 0;
}

