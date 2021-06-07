#include <stdio.h>
#include <stdlib.h>

void count(FILE *fileptr);

int main(int argc, char** argv) {

    if (argc > 2) {
        printf("Must take exactly one argument, no more\n");
        exit(EXIT_FAILURE);
    } else if (argc < 2) {
        printf("Must take exactly one argument, no less\n");
        exit(EXIT_FAILURE);
    }

    // pointer that will store file contents
    FILE *fileptr;
    fileptr = fopen(argv[1], "r");

    if (fileptr == NULL) {
        printf("\n Error: file cannot be opened because it is null. \n");
        exit(EXIT_FAILURE);
    }


    count(fileptr);

    fclose(fileptr);
    exit(EXIT_SUCCESS);
    return 0;
}

void count(FILE *fileptr) {
    char c = fgetc(fileptr);
    // if file is not empty then there must be at least 1 word and line
    int words = 1;
    int lines = 1;
    printf("The contents were: \n");
    while ((c = fgetc(fileptr)) != EOF) {
        if (c == ' ' || c == '\t') {
            words++;
        }
        if (c == '\n' || c == '\0') {
            lines++;
            words++;
        }
        printf("%c", c);
    }
    printf("\nThe number of words counted in the file: %d\n", words);
    printf("The number of lines counted in the file: %d\n", lines);
}