#include "print_scan.h"
#include <math.h>
#include <stdio.h>

int main(int argc, char** argv)
{   
    if (argc > 1) {
       FILE* file;
       int m;
       figure circle[10];
       file = fopen(argv[1], "r");
       read_file(file, circle, &m);
       fclose(file);
       print_figure(circle, m)
    } else {
       printf("The input does not match: <./name_file input_file>\n");
    }
    return 0;
}
