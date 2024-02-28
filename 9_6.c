#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWordsEndingWithA(char* sentence) {
    int count = 0;

    char* word = strtok(sentence, " ");
    while (word != NULL) {
        int length = strlen(word);
        if (length > 0 && word[length - 1] == 'a') {
            count++;
        }
        word = strtok(NULL, " ");
    }

    return count;
}

int main(void) {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening\n");
        return 1;
    }

    char sentence[1000];
    fgets(sentence, sizeof(sentence), inputFile);
    fclose(inputFile);

    int wordCount = countWordsEndingWithA(sentence);

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to load file\n");
        return 1;
    }

    fprintf(outputFile, "%d", wordCount);
    fclose(outputFile);

    return 0;
}