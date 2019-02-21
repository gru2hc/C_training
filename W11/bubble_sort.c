#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b);
void sort(int arr[], int n);
void display_arr(int arr[], int n);

int main(void)
{
    int arr[20] = {};
    int n = sizeof(arr)/sizeof(int);
    srand(time(0));
    int i;
    for(i=0;i<n;i++)
    {
        arr[i] = rand()%100;
    }
    display_arr(arr, n);
    sort(arr, n);
    display_arr(arr, n);
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n)
{
    int i;
    while(n!=0)
    {
        for(i=0;i<(n-1);i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap(&arr[i], &arr[i+1]);
            }
        }
        n--;
    }
}

void display_arr(int arr[], int n)
{
    int i=0;
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
        if(i==(n-1))
        {
            printf("\n");
        }
    }
}