#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000
#define MAX_NUMBERS 100

void extractNumbers(const char* string, int* numbers, int* count) {
    *count = 0;
    char* token = strtok((char*)string, " ");

    while (token != NULL) {
        if (isdigit(*token)) {
            numbers[*count] = atoi(token);
            (*count)++;
        }
        token = strtok(NULL, " ");
    }
}

void sortNumbers(int* numbers, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int main() {
    char string[MAX_STRING_LENGTH];
    int numbers[MAX_NUMBERS];
    int count;

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Not opening.\n");
        return 1;
    }
    fgets(string, MAX_STRING_LENGTH, file);
    fclose(file);

    extractNumbers(string, numbers, &count);

    sortNumbers(numbers, count);

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Failed to create file.\n");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d ", numbers[i]);
    }
    fclose(file);

    printf("output.txt. created\n");

    return 0;
}