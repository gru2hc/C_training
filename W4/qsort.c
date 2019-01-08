#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "qsort.h"

fp function_pointer = sub_function_sort_2_struct_joining;

int cmpfunc (const void * a, const void * b) {
    list_t* p_a=(list_t*)(a);
    list_t* p_b=(list_t*)(b);
    if(((p_a->dob.YY)==(p_b->dob.YY))&&
        ((p_a->dob.MM)==(p_b->dob.MM))&&
        ((p_a->dob.DD)==(p_b->dob.DD)))
    {
        return 0;
    }
    else if( ( (p_a->dob.YY) > (p_b->dob.YY) ) ||
                (((p_a->dob.YY)==(p_b->dob.YY))&&((p_a->dob.MM)>(p_b->dob.MM))) ||
                (((p_a->dob.YY)==(p_b->dob.YY))&&((p_a->dob.MM)==(p_b->dob.MM))&&((p_a->dob.DD)>(p_b->dob.DD))) )
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int cmp_name (const void * a, const void * b) {
    int ret;
    list_t* p_a=(list_t*)(a);
    list_t* p_b=(list_t*)(b);
    ret = strcmp(p_a->name, p_b->name);
    if(0==ret)
    {
        return 0;
    }
    else if(0<ret)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void sort_2_struct(list_t a[], int n, fp function_pointer)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            function_pointer(&a[0], i,j);
        }
    }
    return;
}

void sub_function_sort_2_struct_date(list_t a[], int i, int j)
{
    if (a[i].dob.YY > a[j].dob.YY)
    {
        swap_struct(&(a[i]),&(a[j]));
    }
    return;
}

void sub_function_sort_2_struct_name(list_t a[], int i, int j)
{
    int counter;
    if (a[i].name[0] > a[j].name[0])
    {
        swap_struct(&(a[i]),&(a[j]));
    }
    else
    {
        for(counter=1; a[i].name[counter] == 0 || a[j].name[counter] == 0; counter++)
        {
            if ((a[i].name[counter] > a[j].name[counter]))
            swap_struct(&(a[i]),&(a[j]));
        }
    }
    return;
}

void sub_function_sort_2_struct_joining(list_t a[], int i, int j)
{
    if (a[i].joining.YY > a[j].joining.YY)
    {
        swap_struct(&(a[i]),&(a[j]));
    }
    return;
}

void swap_struct(list_t *a, list_t *b)
{
    list_t temp;
    memcpy(&temp, a, sizeof(list_t));
    memcpy(a, b, sizeof(list_t));
    memcpy(b, &temp, sizeof(list_t));
    return;
}
