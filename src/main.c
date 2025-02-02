#include <stdio.h>

void print_usage() {
    printf("fienc.exe <filename>\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
    }

    FILE *file = fopen(argv[1], "r");

    printf("%s", file);

    return 0;
}