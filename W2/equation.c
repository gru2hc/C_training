#include <stdio.h>
#include <math.h>

#define ON 1
#define OFF 0

#define ENGLISH ON
#define VIETNAMESE OFF

//#define LANG_EN
//#define LANG_VI
#ifdef LANG_EN
#define HELLO_WORLD "Hello world\n"
#else
#define HELLO_WORLD "Xin chao\n"
#endif

void main(void)
{
    int a = 1;
    int b = 2;
    int c = 1;
    int delta;
    float x1,x2;
    delta = b*b - 4*a*c;
    printf(HELLO_WORLD);
    if (0<delta)
    {
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
#if (ENGLISH == ON)
        printf("The quadratic equation has two distinct roots: x1 = %.2f, x2 = %.2f\n", x1, x2);
#elif (VIETNAMESE == ON)
        printf("Phuong trinh co hai nghiem: x1 = %.2f, x2 = %.2f\n", x1, x2);
#endif
    }
    else if (0== delta)
    {
        x1 = -b/(2*a);
#if (ENGLISH == ON)
        printf("The quadratic equation has one distinct root: x = %.2f\n", x1);
#elif (VIETNAMESE == ON)
        printf("Phuong trinh co mot nghiem: x = %.2f\n", x1);
#endif
    }
    else
    {
#if (ENGLISH == ON)
        printf("The quadratic equation has no distinct root.\n");
#elif (VIETNAMESE == ON)
        printf("Phuong trinh khong co nghiem.\n");
#endif
    }
    return;
}