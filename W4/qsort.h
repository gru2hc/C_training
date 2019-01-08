#ifndef QSORT_H
#define QSORT_H

#include <stdint.h>

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

extern void sort_2_struct(list_t a[], int n, fp temp);
extern void swap_struct(list_t *a, list_t *b);
extern void sub_function_sort_2_struct_date(list_t a[], int i, int j);
extern void sub_function_sort_2_struct_name(list_t a[], int i, int j);
extern void sub_function_sort_2_struct_joining(list_t a[], int i, int j);
extern int cmpfunc (const void * a, const void * b);
extern int cmp_name (const void * a, const void * b);

#endif