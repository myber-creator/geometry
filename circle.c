#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Point circle[100];
struct Point triangle[100];

int print(struct Point circle[100], struct Point triangle[100])
{
	int i;
	printf("circle(");
	for(i = 0; i < 2; ++i){
		printf("%d %d", circle[i].x, circle[i].y);
		printf(",");
	}
	printf(")\n");
	printf("triangle(");
	for(i = 0; i < 3; ++i){
		printf("%d %d", triangle[i].x, triangle[i].y);
		printf(",");
	}
	printf(")\n");
}

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
