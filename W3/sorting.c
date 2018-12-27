#include <stdio.h>
#include <math.h>

void arrange_array(int array[], int n);
void comparate_2_nums(int *a, int *b);
void print_array(int array[], int n);
void decending(int array[], int n);
void swap(int *a, int *b);

void t_arrange_array(int array[], int n);
void t_comparate_2_nums(int *a, int *b);
void main(void)
{
    int a[] = {4,8,9,7,90,8,67,46,57,0};
    int n;
    n = sizeof(a)/sizeof(int);
    print_array(&(a[0]),n);
    printf("\n");
    t_arrange_array(&(a[0]),n);
    printf("\nResult after sorting as below.\n");
    print_array(&(a[0]),n);
    //printf("Result after rearrangement.\n");
    //decending(&(a[0]),n);
    //print_array(&(a[0]),n);
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

void t_arrange_array(int array[], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            t_comparate_2_nums(&(array[i]),&(array[j]));
            //printf("%d\n", array[i]);
            // print_array(&(array[0]),n);
        }
    }
    return;
}

void t_comparate_2_nums(int *a, int *b)
{
    int temp;
    if (*a < *b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
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

void decending(int array[], int n)
{
    int i;
    // n =n/2;
    for(i=0;i<(n/2);i++)
    {
        swap(&(array[i]),&(array[n-i-1]));
        printf("%d \n", array[i]);
    }
    return;
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}
