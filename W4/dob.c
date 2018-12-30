#include <stdio.h>
#include <stdint.h>

typedef struct dob_st
{
    uint8_t DD;
    uint8_t MM;
    uint16_t YY;
} dob_t;

dob_t array_list[5] = {
    {11,7,1990},
    {9,12,1989},
    {10,12,1989},
    {9,2,1995},
    {9,1,2000},
};
void sort_2_struct_dob(dob_t array[]);
void swap_uint16(uint16_t *a, uint16_t *b);
void swap_uint8(uint8_t *a, uint8_t *b);


void main(void)
{
    int i;
    printf("List date of birth of employees:\n");
    for (i=0;i<5;i++)
    {
        printf("%d/%d/%d\n", array_list[i].DD, array_list[i].MM, array_list[i].YY);
    }
    sort_2_struct_dob(&array_list[0]);
    printf("List date of birth of employees after rearrange:\n");
    for (i=0;i<5;i++)
    {
        printf("%d/%d/%d\n", array_list[i].DD, array_list[i].MM, array_list[i].YY);
    }
    return;
}

void sort_2_struct_dob(dob_t a[])
{
    int i,j;
    for (i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if (a[i].YY > a[j].YY)
            {
                swap_uint16(&(a[i].YY),&(a[j].YY));
                printf("Test\n");
                printf("Test2 %d\n", a[i].YY);
                swap_uint8(&(a[i].MM),&(a[j].MM));
                swap_uint8(&(a[i].DD),&(a[j].DD));
            }
            else if ((a[i].YY == a[j].YY ) && (a[i].MM > a[j].MM))
            {
                swap_uint8(&(a[i].MM),&(a[j].MM));
                swap_uint8(&(a[i].DD),&(a[j].DD));
            }
            else if ((a[i].YY == a[j].YY ) && (a[i].MM == a[j].MM) && (a[i].DD > a[j].DD) )
            {
                swap_uint8(&(a[i].DD),&(a[j].DD));
            }
        }
    }
    return;
}

void swap_uint16(uint16_t *a, uint16_t *b)
{
    uint16_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void swap_uint8(uint8_t *a, uint8_t *b)
{
    uint8_t temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}


