#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct point_st
{
    int x;
    int y;
} point_t;

typedef struct triangle
{
    point_t A;
    point_t B;
    point_t C;
} triangle_t;

float calculation_area(triangle_t ABC);

void main(void)
{
    triangle_t ABC = {{0,0}, {3,0}, {0,1}};
    float result;
    result = calculation_area (ABC);
    printf("The area of the triangle ABC is: %.2f\n", result);
    return;
}

float calculation_area(triangle_t ABC)
{
    float area;
    area = fabs((ABC.A.x*(ABC.B.y-ABC.C.y)+ABC.B.x*(ABC.C.y-ABC.A.y)+ABC.C.x*(ABC.A.y-ABC.B.y))/2.0);
    // area = ABC.A.x*(ABC.B.y-ABC.C.y)+ABC.B.x*(ABC.C.y-ABC.A.y)+ABC.C.x*(ABC.A.y-ABC.B.y);
    // area = fabs(area/2);
    return area;
}