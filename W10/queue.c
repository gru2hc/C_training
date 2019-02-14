#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int enqueue(int num, int array[], int n);
int dequeue(int array[], int n, int* value_dequeue);
void display_array(int array[]);

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
    srand(time(0));
    while(check_enqueue==1)
    {
        check_enqueue = enqueue(rand()%100,array,n);
    }

    display_array(array);
    check_dequeue = dequeue(array,n,&value_dequeue);
    printf("\nCheck value of dequeue: %d\n", value_dequeue);
    display_array(&array[0]);
    // check_enqueue = enqueue(77,array,n);
    // display_array(&array[0]);
    return 0;
}

int enqueue(int num, int array[], int n)
{

    return result;
}

int dequeue(int array[], int n, int* value_dequeue)
{

    return result;
}

void display_array(int array[])
{
    int i;
    printf("\n");

}