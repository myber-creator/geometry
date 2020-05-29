#ifndef H_PRINT_SCAN
#define H_PRINT_SCAN
#include <stdio.h>

typedef struct{
    char name[10];
    int param[3];
} figure;

void print_figure(figure circle[10], int m);
void read_file(FILE* file, figure circle[10], int* m);

#endif
