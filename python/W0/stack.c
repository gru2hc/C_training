#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct stack_st
{
    int* arr;
    int max_size;
    int top;
} stack_t;

void init_stack(stack_t* stack_var, int max_size);
void deinit_stack(stack_t* stack_var);
void display_stack(stack_t* stack_var);
int push(stack_t* stack_var, int num);
int pop(stack_t* stack_var, int* value_pop);

int main(void)
{
    stack_t stack_1;
    stack_t stack_2;
    int value_pop;
    int check_push=1;
    srand(time(0));
    init_stack(&stack_1, 5);
    init_stack(&stack_2, 10);
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
    deinit_stack(&stack_1);
    deinit_stack(&stack_2);
    /*Program hangs*/
    pop(&stack_1, &value_pop);
    printf("\nStack 1 is:");
    display_stack(&stack_1);
}

void init_stack(stack_t* stack_var, int max_size)
{
    int* p = NULL;
    p = malloc(max_size*sizeof(int));
    stack_var->arr = p;
    stack_var->max_size = max_size;
    stack_var->top = 0;
}

void deinit_stack(stack_t* stack_var)
{
    free(stack_var->arr);
    stack_var->arr = NULL;
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