#include <math.h>
#include <stdio.h>
#include "print_scan.h"

int main(int argc, const char *argv[])
{   
    if(argc > 2){
        FILE* file;
        int m;
        figure circle[10];
        file = fopen(argv[1], "r");
        read_file(file, circle, &m);
        fclose(file);
        print_figure(circle, m);
        return 0;
    }else{
        printf("The input does not match: <./ name_file input_file>")
    }
}
