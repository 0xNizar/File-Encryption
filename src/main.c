#include <stdio.h>
#include <stdlib.h>
#include "include/rled.h"

char *get_file_content(const char *file_name) 
{
    FILE *target = fopen(file_name, "r");
    if (target == NULL) {
        printf("File can't be opened\n");
        return NULL;
    }

    fseek(target, 0, SEEK_END);
    long filesize = ftell(target);
    rewind(target);

    char *content = (char *)malloc(filesize + 1);
    if (!content) {
        printf("Memory allocation failed\n");
        fclose(target);
        return NULL;
    }

    fread(content, 1, filesize, target);
    content[filesize] = '\0';

    fclose(target);
    return content;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *file = get_file_content(argv[1]);
    if (!file) {
        return EXIT_FAILURE;
    }

    printf("Content of the file:\n");
    run_length_encoding(file);
    
    free(file);

    return EXIT_SUCCESS;
}