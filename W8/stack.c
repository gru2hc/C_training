#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int push(int num);
void display_stack(void);
int pop(int* pop_value);
int stack[64];
int top = -1;
int main(void)
{
    int count=0;
    int pop_value;
    int pop_result=0;
    srand(time(0));
    while(push(rand()) != -1)
    {
        count++;
    }
    display_stack();
    printf("\nValue of pop is: \n");
    while(pop(&pop_value) != -1)
    {
        printf("%d ", pop_value);
    }
    printf("\nCounter is: %d\n\n", count);
    display_stack();
}

int push(int num)
{
    int result;
    int n = sizeof(stack)/sizeof(int);
    if(top<(n-1))
    {
        stack[top+1]=num;
        top++;
        result = 1;
    }
    else
    {
        result = -1;
    }
    return result;
}

int pop(int* pop_value)
{
    int result;
    if(top != -1)
    {
        *pop_value = stack[top];
        top--;
        result = 1;
    }
    else
    {
        result = -1;
    }
    return result;
}

void display_stack(void)
{
    int i;
    for(i=0;i<(top+1);i++)
    {
        printf("%d ", stack[i]);
    }
}