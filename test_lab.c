#include <stdio.h>
#include <string.h>

int wordcount(int argc, char* argv[3]) {
    FILE *file;
    file = fopen(argv[argc - 1], "r");
    char readChar;
    char previousChar = ' ';
    int linesAmount = 1;
    int fileSizeBytes = 0;
    int wordAmount = 0;
    if (file == NULL) {
        printf("File %s not found :(\n", argv[argc - 1]);
        return -1;
    } else {
        while ((readChar = fgetc(file)) != EOF) {
            fileSizeBytes += sizeof(readChar);
            if (readChar == '\n') {
                linesAmount++;
            }
            if (previousChar == ' ' || previousChar == '\t' || previousChar == '\n') {
                if (readChar != ' ' && readChar != '\t' && readChar != '\n') {
                    wordAmount++;
                }
            }
            previousChar = readChar;
        }
    }

    if (fileSizeBytes == 0) {
        linesAmount = 0;
        wordAmount = 0;
    }

    for (int i = 1; i < argc - 1; i++) {
         if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--lines") == 0) {
            return linesAmount;
        } else if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--words") == 0) {
            return wordAmount;
        } else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--bytes") == 0) {
            return fileSizeBytes;
        }
    }
    fclose(file);
}