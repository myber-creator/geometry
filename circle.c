#include <stdio.h>
#include <math.h>

struct figure{
    struct{
        int x;
        int y;
    }point[100];
}circle[100];

struct figure triangle[100];

void specific_circle(struct figure circle[100], float* r, int i, float* ar, float* pr){
    double pi = 3.14159265358979323846;
    *pr = 2 * pi * r[i];
    *ar = pi * pow(r[i],2);
} 

void specific_triangle(struct figure triangle[100], int i, int* ar_tr, float* pr_tr){
    float ab = sqrt(pow(triangle[i].point[1].x - triangle[i].point[0].x, 2) + pow(triangle[i].point[1].y - triangle[i].point[0].y, 2));
    float bc = sqrt(pow(triangle[i].point[2].x - triangle[i].point[1].x, 2) + pow(triangle[i].point[2].y - triangle[i].point[1].y, 2));
    float ac = sqrt(pow(triangle[i].point[2].x - triangle[i].point[0].x, 2) + pow(triangle[i].point[2].y - triangle[i].point[0].y, 2));
    *pr_tr = ab + bc + ac;
    float p = *pr_tr / 2;
    *ar_tr = sqrt(p * (p - ab) * (p - bc) * (p - ac));
} 

void print_circle(struct figure circle[100], int i, int n, float* r)
{
		printf("circle %d (%d %d, %.1f)", i+1, circle[i].point->x, circle[i].point->y, r[i]);
		printf("\n");
		float pr, ar;
		specific_circle(circle, r, i, &ar, &pr);
		printf("    Perimeter = %.4f\n", pr);
		printf("    Area = %.4f\n", ar);
		
		
}

void print_triangle(struct figure triangle[100], int i, int m)
{
		int j;
		float pr_tr;
		int ar_tr;
		printf("triangle %d ((", i+1);
		    for(j = 0; j < 2; j++){
		        printf("%d %d ,", triangle[i].point[j].x, triangle[i].point[j].y);
		    }
		    printf("%d %d))\n", triangle[i].point[2].x, triangle[i].point[2].y);
		    specific_triangle(triangle, i, &ar_tr, &pr_tr);
		    printf("    Perimeter = %.3f\n", pr_tr);
		    printf("    Area = %d\n", ar_tr);
}

int main()
{
	int i,n,j,m;
	printf("Введите количество окружностей: \n");
	scanf("%d", &n);
	float r[n];
	if(n > 0){
	    printf("Введите точки окружности и их радиусы :\n");
	    for(i = 0; i < n; i++){
	    	scanf("%d %d", &circle[i].point->x, &circle[i].point->y);
	    	scanf("%f", &r[i]);
	    }
	}
	printf("Введите количество треугольников: \n");
	scanf("%d", &m);
	if(m > 0){
    	printf("Введите точки треугольников: \n");
	    for(i = 0; i < m; i++){
	       for(j = 0; j < 3; j++){
	    	    scanf("%d %d", &triangle[i].point[j].x, &triangle[i].point[j].y);
	       }
	    }
	}
	for(i = 0; i < n; i++){
	    print_circle(circle, i, n, r);
	}
	for(i = 0; i < m; i++){
	   print_triangle(triangle,i, m);
	}
}