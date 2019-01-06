#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define type_of_sort sort_2_struct

typedef struct date_st
{
    uint8_t DD;
    uint8_t MM;
    uint16_t YY;
} date_t;

typedef struct list_st
{
    char name[32];
    date_t dob;
    date_t joining;
} list_t;

typedef void (*fp)(list_t a[], int i, int j);

void sort_2_struct(list_t a[], int n, fp temp);
void swap_struct(list_t *a, list_t *b);
void sub_function_sort_2_struct_date(list_t a[], int i, int j);
void sub_function_sort_2_struct_name(list_t a[], int i, int j);
void sub_function_sort_2_struct_joining(list_t a[], int i, int j);
int cmpfunc (const void * a, const void * b);
int cmp_name (const void * a, const void * b);
fp function_pointer = sub_function_sort_2_struct_joining;

// char test[] = "XYZ";
void main(void)
{
    list_t array_list[] = {
        {"Nguyen Van Annn",{11,7,1990},{1,1,2000}},
        {"Zguyen Van Ba",{9,12,1989},{15,1,2018}},
        {"Nguyen Thi Van Anh",{10,12,1985},{30,1,2000}},
    };
    int n = sizeof(array_list)/sizeof(list_t);
    int i;
    printf("List of employees with dob:\n");
    for (i=0;i<n;i++)
    {
        printf("%s, %d/%d/%d\n", array_list[i].name, array_list[i].dob.DD, array_list[i].dob.MM, array_list[i].dob.YY);
    }
    // type_of_sort(&array_list[0], n, sub_function_sort_2_struct_joining);
    // qsort(array_list, 3, sizeof(int), cmpfunc);
    qsort(array_list, n, sizeof(list_t), cmp_name);
    printf("List date of birth of employees after rearrange:\n");
    for (i=0;i<n;i++)
    {
        printf("%s, %d/%d/%d\n", array_list[i].name, array_list[i].dob.DD, array_list[i].dob.MM, array_list[i].dob.YY);
    }
    return;
}

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
