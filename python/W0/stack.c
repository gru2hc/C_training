#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct stack_st
{
    int* arr;
    int max_size;
    int top;
} stack_t;

void init_stack(stack_t* stack_var, int* arr, int max_size);
void display_stack(stack_t* stack_var);
int push(stack_t* stack_var, int num);
int pop(stack_t* stack_var, int* value_pop);

int main(void)
{
    stack_t stack_1;
    stack_t stack_2;
    int arr_1[5]={0};
    int arr_2[10]={0};
    int value_pop;
    int check_push=1;
    srand(time(0));
    init_stack(&stack_1, &arr_1[0], sizeof(arr_1)/sizeof(int));
    init_stack(&stack_2, &arr_2[0], sizeof(arr_2)/sizeof(int));
    display_stack(&stack_1);
    while(1==check_push)
    {
        check_push=push(&stack_1,rand()%10);
    }
    display_stack(&stack_1);
    pop(&stack_1, &value_pop);
    printf("\nStack 1 is:");
    display_stack(&stack_1);
    check_push = 1;
    while(1==check_push)
    {
        check_push=push(&stack_2,rand()%10);
    }
    printf("\nStack 2 is:");
    display_stack(&stack_2);
}

void init_stack(stack_t* stack_var, int* arr, int max_size)
{
    stack_var->arr = arr;
    stack_var->max_size = max_size;
    stack_var->top = 0;
}

int push(stack_t* stack_var, int num)
{
    int result;
    if((stack_var->top)==(stack_var->max_size))
    {
        result = 0;
    }
    else
    {
        *((stack_var->arr)+(stack_var->top)) = num;
        (stack_var->top)++;
        result = 1;
    }
    return result;
}

int pop(stack_t* stack_var, int* value_pop)
{
    int result;
    if((stack_var->top) == 0)
    {
        result = 0;
    }
    else
    {
        *value_pop = *((stack_var->arr)+(stack_var->top) - 1);
        (stack_var->top)--;
        result = 1;
    }
}

void display_stack(stack_t* stack_var)
{
    int i=0;
    printf("\n");
    for(i=0;i<(stack_var->top);i++)
    {
        printf("%d ", *((stack_var->arr)+i));
    }
}