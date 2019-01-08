#include <stdlib.h>
#include "qsort.h"
#include "display.h"

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
    display(&array_list[0], n);
    qsort(array_list, n, sizeof(list_t), cmpfunc);
    // qsort(array_list, n, sizeof(list_t), cmp_name);
    printf("List date of birth of employees after rearrange:\n");
    display(&array_list[0], n);
    return;
}