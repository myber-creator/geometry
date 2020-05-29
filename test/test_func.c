#include "props.h"
#include <ctest.h>
#include <stdio.h>

figure circle[10];

void create_circle(figure circle[10], int n, int p1, int p2, int p3)
{
    circle[n].param[0] = p1;
    circle[n].param[1] = p2;
    circle[n].param[2] = p3;
    circle[n].name[0] = 'c';
    circle[n].name[1] = 'i';
    circle[n].name[2] = 'r';
    circle[n].name[3] = 'c';
    circle[n].name[4] = 'l';
    circle[n].name[5] = 'e';
    circle[n].name[6] = '\0';
}

CTEST(perim, test_1)
{
    create_circle(circle, 1, 1, 1, 5);
    float expect = 10 * M_PI;
    float result = perim(circle, 1);
    ASSERT_DBL_NEAR_TOL(expect, result, 1);
}

CTEST(squad, test_1)
{
    create_circle(circle, 1, 1, 2, 4);
    double expect = 61 * M_PI;
    double result = squad(circle, 1);
    ASSERT_DBL_NEAR_TOL(expect, result, 1);
}

CTEST(crossing, crossed_figures)
{
    create_circle(circle, 1, 1, 2, 2);
    create_circle(circle, 2, 2, 2, 2);
    int expect = 1;
    int result = crossing(circle, 1, 2);
    ASSERT_EQUAL(expect, result);
}

CTEST(crossing, not_crossed_figures)
{
    create_circle(circle, 1, 1, 2, 2);
    create_circle(circle, 2, 7, 8, 2);
    int expect = 0;
    int result = crossing(circle, 1, 2);
    ASSERT_EQUAL(expect, result);
}