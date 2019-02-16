#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int enqueue(int num, int array[], int n);
int dequeue(int array[], int n, int* value_dequeue);
void display_array(int array[], int n);

int tail = 0;
int head = 0;
int count = 0;

int main(void)
{
    int array[5];
    int n = sizeof(array)/sizeof(int);
    int check_enqueue = 1;
    int check_dequeue = 1;
    int value_dequeue = 0;
    int i = 0;
    srand(time(0));
    while(check_enqueue==1)
    {
        check_enqueue = enqueue(rand()%100,array,n);
    }
    display_array(array,n);

    // while(check_dequeue==1)
    // {
        // check_dequeue = dequeue(array,n,&value_dequeue);
    // }
    for(i=0;i<3;i++)
    {
        check_dequeue = dequeue(array,n,&value_dequeue);
    }
    printf("\nCheck value of dequeue: %d\n", value_dequeue);
    display_array(array,n);
    check_enqueue = enqueue(77,array,n);
    check_enqueue = enqueue(78,array,n);
    check_enqueue = enqueue(79,array,n);

    display_array(array,n);
    check_dequeue = dequeue(array,n,&value_dequeue);
    display_array(array,n);
    check_enqueue = enqueue(20,array,n);
    display_array(array,n);
    return 0;
}

int enqueue(int num, int array[], int n)
{
    int result = 0;
    if (count == n)
    {
      result = 0;
    }
    else
    {
        array[head] = num;
        head++;
        head = head%5;
        count++;
        result = 1;
    }
    return result;
}

int dequeue(int array[], int n, int* value_dequeue)
{
    int result = 0;
    if (count == 0)
    {
        result = 0;
    }
    else
    {
        *value_dequeue = array[tail];
        tail++;
        tail = tail%5;
        count--;
        result = 1;
    }
    return result;
}

void display_array(int array[], int n)
{
    int i=0;
    int position=tail;
    if(count == 0)
    {
        printf("\nERROR! There is no element to display!\n");
    }
    else
    {
        printf("\nElements in array with priority are:\n");
        for(i=0;i<count;i++)
        {
            printf("%d ", array[position]);
            position++;
            position = position%5;
        }
    }
    return;
}
