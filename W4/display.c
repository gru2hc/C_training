#include <stdio.h>
#include "display.h"

void display(list_t array_list[], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%s, %d/%d/%d\n", array_list[i].name, array_list[i].dob.DD, array_list[i].dob.MM, array_list[i].dob.YY);
    }
    return;
}