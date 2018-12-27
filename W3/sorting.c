#include <stdio.h>
#include <math.h>

void arrange_array(int array[], int n);
void comparate_2_nums(int *a, int *b);
void print_array(int array[], int n);

void main(void)
{
    int a[] = {4,2,8,9,7,90,8,67,46,57,0};
    int n;
    n = sizeof(a)/sizeof(int);
    print_array(&(a[0]),n);
    printf("\n");
    arrange_array(&(a[0]),n);
    printf("\nResult after sorting as below.\n");
    print_array(&(a[0]),n);
    return;
}

void arrange_array(int array[], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            comparate_2_nums(&(array[i]),&(array[j]));
            //printf("%d\n", array[i]);
            // print_array(&(array[0]),n);
        }
    }
    return;
}


void comparate_2_nums(int *a, int *b)
{
    int temp;
    if (*a > *b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    return;
}

void print_array(int array[], int n)
{
    int i;
    printf("Elements of array are: \n");
    for (i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    return;
}
