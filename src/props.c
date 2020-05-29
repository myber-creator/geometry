#include "print_scan.h"
#include <math.h>
#include <stdio.h>

float perim(figure circle[10], int i)
{
    float perim;
    perim = 2 * M_PI * circle[i].param[2];
    return perim;
}

float squad(figure circle[10], int i)
{
    float squad;
    squad = M_PI * pow(circle[i].param[2], 2);
    return squad;
}

int crossing(figure circle[10], int i, int m)
{
    if ((sqrt(pow(circle[i].param[0] - circle[m].param[0], 2)
              + pow(circle[i].param[1] - circle[m].param[1], 2)))
        <= (circle[i].param[2] + circle[m].param[2])) {
        return 1;
    }
    return 0;
}

void crossing_check(figure circle[10], int index, int n)
{
    int circles = 0;
    for (int i = 0; i < n; i++) {
        if (i != index) {
            if (crossing(circle, index, i) == 1) {
                if (circles == 0) {
                    printf("\tintersects:\n");
                }
                circles = 1;
                printf("\t\t%d. circle\n", i + 1);
            }
        }
    }
}
