#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define type_of_sort sort_2_struct_date

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
} list_t;

void sort_2_struct_date(list_t a[], int n);
void sort_2_struct_name(list_t a[], int n);
void swap_struct(list_t *a, list_t *b);

// char test[] = "XYZ";

void main(void)
{
    list_t array_list[] = {
        {"Nguyen Van Annn",{11,7,1990}},
        {"Zguyen Van Ba",{9,12,1989}},
        {"Nguyen Thi Van Anh",{10,12,1985}},
    };

    // char name_3[] = "ABCD";
    // char* name = "ABCD";
    
    // name_3[1] = 'G';
    // // *(name+1) = 'G'; 
    
    // // printf("Test char name_3: %s\n", &(name_3[0]));
    // printf("Test char name : %s\n", name);
    // printf("%s\n", &(name_3[1]));
    // date_t array_list[] = {
        // {11,7,1990},
        // {9,12,1989},
        // {10,12,1989},
        // {9,2,1995},
        // {9,1,2000},
        // {7,7,1997},
        // {8,8,1678},
    // };
    int n = sizeof(array_list)/sizeof(list_t);
    int i;
    printf("List of employees with dob:\n");
    for (i=0;i<n;i++)
    {
        printf("%s, %d/%d/%d\n", array_list[i].name, array_list[i].dob.DD, array_list[i].dob.MM, array_list[i].dob.YY);
    }
    // sort_2_struct_date(&array_list[0], n);
    type_of_sort(&array_list[0], n);
    printf("List date of birth of employees after rearrange:\n");
    for (i=0;i<n;i++)
    {
        printf("%s, %d/%d/%d\n", array_list[i].name, array_list[i].dob.DD, array_list[i].dob.MM, array_list[i].dob.YY);
    }
    return;
}

void sort_2_struct_date(list_t a[], int n)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if (a[i].dob.YY > a[j].dob.YY)
            {
                swap_struct(&(a[i]),&(a[j]));
            }
            // else if ((a[i].dob.YY == a[j].dob.YY ) && (a[i].dob.MM > a[j].dob.MM))
            // {
                // swap_struct(&(a[i]),&(a[j]));
            // }
            // else if ((a[i].dob.YY == a[j].dob.YY ) && (a[i].dob.MM == a[j].dob.MM) && (a[i].dob.DD > a[j].dob.DD) )
            // {
                // swap_struct(&(a[i]),&(a[j]));
            // }
        }
    }
    return;
}

void sort_2_struct_name(list_t a[], int n)
{
    int i,j, counter;
    for (i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
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
            // else
            // {
                // for(counter=1; counter != '0'; counter++)
                // {
                    // swap_struct(&(a[i]),&(a[j]));
                // }
            // }
            // else if ((a[i].dob.YY == a[j].dob.YY ) && (a[i].dob.MM > a[j].dob.MM))
            // {
                // swap_struct(&(a[i]),&(a[j]));
            // }
            // else if ((a[i].dob.YY == a[j].dob.YY ) && (a[i].dob.MM == a[j].dob.MM) && (a[i].dob.DD > a[j].dob.DD) )
            // {
                // swap_struct(&(a[i]),&(a[j]));
            // }
        }
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

// void sort_2_struct_date(date_t a[], int n)
// {
    // int i,j;
    // for (i=0;i<n;i++)
    // {
        // for(j=i+1;j<n;j++)
        // {
            // if (a[i].YY > a[j].YY)
            // {
                // swap_struct(&(a[i]),&(a[j]));
            // }
            // else if ((a[i].YY == a[j].YY ) && (a[i].MM > a[j].MM))
            // {
                // swap_struct(&(a[i]),&(a[j]));
            // }
            // else if ((a[i].YY == a[j].YY ) && (a[i].MM == a[j].MM) && (a[i].DD > a[j].DD) )
            // {
                // swap_struct(&(a[i]),&(a[j]));
            // }
        // }
    // }
    // return;
// }

// void swap_struct(date_t *a, date_t *b)
// {
    // date_t temp;
    // memcpy(&temp, a, sizeof(date_t));
    // memcpy(a, b, sizeof(date_t));
    // memcpy(b, &temp, sizeof(date_t));
    // return;
// }
