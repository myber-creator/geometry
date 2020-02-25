#include <stdio.h>

struct figure {
    char name[10];
    int param[3];
};

void read_file(FILE* file, int n, struct figure circle[n])
{
    int i;
    for (i = 0; i < n; i++) {
        fscanf(file,
               "%s (%d %d, %d)",
               circle[i].name,
               &circle[i].param[0],
               &circle[i].param[1],
               &circle[i].param[2]);
        printf("%s %d (%d %d, %d)\n",
               circle[i].name,
               i + 1,
               circle[i].param[0],
               circle[i].param[1],
               circle[i].param[2]);
    }
}
int main()
{
    FILE* file;
    int n;
    printf("Enter n circle:\n");
    scanf("%d", &n);
    struct figure circle[n];
    file = fopen("figures.txt", "r");
    read_file(file, n, circle);
    return 0;
}
