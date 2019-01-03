#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct dob_st
{
    uint8_t DD;
    uint8_t MM;
    uint16_t YY;
} dob_t;


void sort_2_struct_dob(dob_t a[], int n);
void swap_struct(dob_t *a, dob_t *b);


void main(void)
{
    dob_t array_list[] = {
        {11,7,1990},
        {9,12,1989},
        {10,12,1989},
        {9,2,1995},
        {9,1,2000},
        {7,7,1997},
        {8,8,1678},
    };
    int n = sizeof(array_list)/sizeof(dob_t);
    int i;
    printf("List date of birth of employees:\n");
    for (i=0;i<n;i++)
    {
        printf("%d/%d/%d\n", array_list[i].DD, array_list[i].MM, array_list[i].YY);
    }
    sort_2_struct_dob(&array_list[0], n);
    printf("List date of birth of employees after rearrange:\n");
    for (i=0;i<n;i++)
    {
        printf("%d/%d/%d\n", array_list[i].DD, array_list[i].MM, array_list[i].YY);
    }
    return;
}

void sort_2_struct_dob(dob_t a[], int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if (a[i].YY > a[j].YY)
            {
                swap_struct(&(a[i]),&(a[j]));
            }
            else if ((a[i].YY == a[j].YY ) && (a[i].MM > a[j].MM))
            {
                swap_struct(&(a[i]),&(a[j]));
            }
            else if ((a[i].YY == a[j].YY ) && (a[i].MM == a[j].MM) && (a[i].DD > a[j].DD) )
            {
                swap_struct(&(a[i]),&(a[j]));
            }
        }
    }
    return;
}

void swap_struct(dob_t *a, dob_t *b)
{
    dob_t temp;
    memcpy(&temp, a, sizeof(dob_t));
    memcpy(a, b, sizeof(dob_t));
    memcpy(b, &temp, sizeof(dob_t));
    return;
}


