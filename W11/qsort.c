#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void display_arr(int arr[], int n);
extern void swap(int* a, int* b);
extern int partition(int arr[], int low, int high);
extern void quick_sort(int arr[], int low, int high);

int main(void)
{
    int arr[] = {10,0,2,4,5};
    int n = sizeof(arr)/sizeof(int);
    int low;
    int high;
    // srand(time(0));
    // int i;
    // for(i=0;i<n;i++)
    // {
        // arr[i] = rand()%100;
    // }
    display_arr(arr, n);
    quick_sort(arr,0,n-1);
    display_arr(arr, n);
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


void quick_sort(int arr[], int low, int high)
{
    int pivot = partition(arr,low,high);
    printf("\nTEST pivot is %d\n", pivot);
    // if(low<high)
    // {
        // quick_sort(arr,low,pivot-1);
        // quick_sort(arr,pivot+1,high);
    // }
}

int partition(int arr[], int low, int high)
{
    int pivot = high-1;
    while(low<pivot)
    {
        if(arr[low]<=arr[pivot])
        {
            /*do nothing*/
            low++;
        }
        else
        {
            if(pivot == (low+1))
            {
                swap(&arr[pivot-1],&arr[pivot]);
                pivot = pivot -1;
                display_arr(arr,high);
                printf("\nTEST i = %d, pivod = %d\n", low, pivot);
            }
            else
            {
                swap(&arr[pivot-1],&arr[pivot]);
                display_arr(arr,high);
                swap(&arr[low],&arr[pivot]);
                display_arr(arr,high);
                pivot = pivot -1;
                printf("\nTEST i = %d, pivod = %d\n", low, pivot);
            }
        }
    }
    return pivot;
}

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
