#include <stdio.h>
#include <math.h>

#ifdef LANG_ENG 
#define HELLO_WORLD "Hello world\n"
#define equation "The quadratic equation "
#define two_roots "has two distinct roots: "
#define one_root "has one real root: "
#define no_root "has no real roots.\n"
#elif LANG_VI
#define HELLO_WORLD "Xin chao\n"
#define equation "Phuong trinh "
#define two_roots "co hai nghiem: "
#define one_root "co mot nghiem: "
#define no_root "khong co nghiem.\n"
#endif

int calculation (int a, int b, int c, float *x1, float *x2);

void main(void)
{
    int a = 1;
    int b = 2;
    int c = 1;

    float x1, x2;
    printf(HELLO_WORLD);
    int result;

    result = calculation(a,b,c, &x1,&x2);
    switch (result)
    {
        case 2:
            printf(equation two_roots "x1 = %.2f, x2 = %.2f\n", x1, x2);
            break;
        case 1:
            printf(equation one_root "x = %.2f\n", x1);
            break;
        case 0:
            printf(equation no_root);
            break;
        default: printf("Error!!!");
    }
    return;
}

int calculation (int a, int b, int c, float *x1, float *x2)
{
    int result;
    int delta;
    delta = b*b - 4*a*c;
    if (0<delta)
    {
        *x1 = (-b + sqrt(delta))/(2*a);
        *x2 = (-b - sqrt(delta))/(2*a);
        result = 2;
    }
    else if (0== delta)
    {
        *x1 = -b/(2*a);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}