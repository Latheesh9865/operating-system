#include <stdio.h>
#include <string.h>
#define MAX_LINE_LEN 1024
int main(int argc, char *argv[]) {
    char line[MAX_LINE_LEN];
    FILE *fp;
    if (argc != 3) {
        printf("Usage: grep pattern file\n");
        return 1;
    }
    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", argv[2]);
        return 1;
    }
    while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
        if (strstr(line, argv[1]) != NULL) {
            printf("%s", line);
        }
    }
    fclose(fp);
    return 0;
}