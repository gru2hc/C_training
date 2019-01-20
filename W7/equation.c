#include <stdio.h>
#include <math.h>

int calculate_equation(int a, int b, int c, float* x1, float* x2);
void display(int result, float* x1, float*x2);
int convert_str_to_int(char *argv);

int main(int argc, char *argv[])
{
    int result;
    float x1;
    float x2;
    // convert_str_to_int((argv[1]),&temp);
    // printf("TEST: %d\n", temp);
    if(argc==4)
    {
        // result = calculate_equation((*(argv[1])-0x30),(*(argv[2])-0x30),(*(argv[3])-0x30),&x1,&x2);
        result = calculate_equation(convert_str_to_int(argv[1]),convert_str_to_int(argv[2]),convert_str_to_int(argv[3]),&x1,&x2);
        display(result,&x1,&x2);
    }
    else 
    {
        printf("Error! Please input folling format: \nequation a b c\n");
    }
    return 0;
}

int calculate_equation(int a, int b, int c, float* x1, float* x2)
{
    int delta;
    delta = b*b -4*a*c;
    if(delta>0)
    {
        *x1 = (-b-sqrt(delta))/(2*a);
        *x2 = (-b+sqrt(delta))/(2*a);
        return 2;
    }
    else if(delta==0)
    {
        *x1 = (-b)/(2*a);
        return 1;
    }
    else
    {
        return 0;
    }
}

void display(int result, float* x1, float*x2)
{
    switch (result)
    {
        case 2:
            printf("The equation has 2 roots:\nx1 = %f, x2 = %f\n", *x1, *x2);
            break;
        case 1:
            printf("The equation has 1 root:\nx1 = x2 = %f\n", *x1);
            break;
        case 0:
            printf("The equation has no root\n");
            break;
        default:
            break;
    }
}

int convert_str_to_int(char *argv)
{
    int i;
    int output = 0;
    for(i=0;*(argv+i)!=0;i++)
    {
        output = output*10 + (*(argv+i)-'0');
    }
    return output;
}