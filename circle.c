#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Point circle[100];
struct Point triangle[100];



int main()
{
	int i;
	printf("Введите точку окружности:\n");
	for(i = 0; i < 2; i++){
		scanf("%d %d", &circle[i].x, &circle[i].y);
	}
	printf("Введите точки треугольника:\n");
	for(i = 0; i < 3; i++){
		scanf("%d %d", &triangle[i].x, &triangle[i].y);
	}
	print(circle,triangle);
}
