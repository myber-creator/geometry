#include "print_scan.h"
#include "props.h"
#include <stdio.h>

void print_figure(figure circle[10], int m)
{
    for (int i = 0; i < m; i++) {
        printf("%d. %s (%d %d, %d)\n",
					i + 1,
					circle[i].name,
               circle[i].param[0],
               circle[i].param[1],
               circle[i].param[2]);
        printf("\tperimeter = %.3f \n", perim(circle, i));
        printf("\tarea = %.3f \n", squad(circle, i));
        crossing_check(circle, i, m);
    }
}

void read_file(FILE* file, figure circle[10], int* m)
{
    int i;
    i = 0;
    while (!feof(file)) {
        fscanf(file,
               "%s (%d %d, %d)",
               circle[i].name,
               &circle[i].param[0],
               &circle[i].param[1],
               &circle[i].param[2]);
        i++;
    }
    *m = i - 1;
}
