#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b);
int search(int arr[], int n, int find_number, int* result_pos);

int main(void)
{
    int arr[] = {1,4,5,10,7,8,4,5};
    int find_number = 8;
    int result_pos;
    int check_search;
    int i = 0;
    int n;
    n = sizeof(arr)/sizeof(int);
    printf("n = %d\n", n);
    check_search = search(arr, n, find_number, &result_pos);
    if(check_search == 0)
    {
        printf("Number not found!\n");
    }
    else
    {
        printf("The position of number %d in array is: %d\n", find_number, result_pos);
    }
    return 0;
}

int cmpfunc(const void* a, const void* b)
{
    int result;
    if(*((int*)a) == *((int*)b))
    {
        result = 0;
    }
    else if(*((int*)a) > *((int*)b))
    {
        result = 1;
    }
    else
    {
        result = -1;
    }
    return result;
}

int search(int arr[], int n, int find_number, int* result_pos)
{
    int check_pos;
    int result = 0;
    int count = 0;
    int start_pos = 0;
    int end_pos = n-1;
    qsort(arr, n, sizeof(int), cmpfunc);
    while (end_pos != start_pos)
    {
        check_pos = (start_pos + end_pos)/2;
        if(arr[check_pos] == find_number)
        {
            *result_pos = check_pos;
            result = 1;
            break;
        }
        else if(arr[check_pos] > find_number)
        {
            end_pos = check_pos-1;
        }
        else
        {
            start_pos = check_pos+1;
        }
        count++;
    }
    if(arr[start_pos]==find_number)
    {
        *result_pos =  start_pos;
        result = 1;
        count++;
    }
    else
    {
        count++;
        result = 0;
    }
    printf("%d loop\n", count);
    return result;
}