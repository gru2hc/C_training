#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int push(float num, float arr[], int n);
int pop(float arr[], int n, float* value);
void display_arr(float arr[]);
void calculation(char input[], int input_length, float arr[], int n,float* value);
int top=-1;

int main(void)
{
    char input[] = "*-+/12/93/156";
    int n, input_length,i,count;
    float value;
    int check_result = 1;
    float arr[11];
    n = sizeof(arr)/sizeof(int);
    input_length = sizeof(input);
    calculation(&input[0], input_length, &arr[0], n, &value);
    printf("Result is: \n");
    display_arr(&arr[0]); 

    return 0;
}

int push(float num, float arr[], int n)
{
    int result = 0;
    if(top==(n-1))
    {
        result = 0;
    }
    else
    {
        arr[top+1] = num;
        result = 1;
        top++;
    }
    return result;
}

int pop(float arr[], int n, float* value)
{
    int result = 0;
    if(top==-1)
    {
        result = 0;
    }
    else
    {
        *value = arr[top];
        top--;
        result = 1;
    }
    return result;
}

void display_arr(float arr[])
{
    int i;
    if(top==-1)
    {
        /*do nothing*/
    }
    else 
    {
        for(i=0;i<(top+1);i++)
        {
            printf("%.2f ", arr[i]);
        }
    }
    return;
}

void calculation(char input[], int input_length, float arr[], int n,float* value)
{
    int count = input_length-2;
    int check_pop, check_push;
    float calculate_value;
    while(count >= 0)
    {
        switch(input[count]) {
        case '+':
            check_pop = pop(&arr[0],n,value);
            calculate_value = *value;
            check_pop = pop(&arr[0],n,value);
            calculate_value= calculate_value + *value;
            check_push = push(calculate_value,&arr[0],n);
            count--;
            break;
        case '-':
            check_pop = pop(&arr[0],n,value);
            calculate_value = *value;
            check_pop = pop(&arr[0],n,value);
            calculate_value= calculate_value - *value;
            check_push = push(calculate_value,&arr[0],n);
            count--;
            break;
        case '*':
            check_pop = pop(&arr[0],n,value);
            calculate_value = *value;
            check_pop = pop(&arr[0],n,value);
            calculate_value= calculate_value*(*value);
            check_push = push(calculate_value,&arr[0],n);
            count--;
            break;
        case '/':
            check_pop = pop(&arr[0],n,value);
            calculate_value = *value;
            check_pop = pop(&arr[0],n,value);
            calculate_value= calculate_value/(*value);
            check_push = push(calculate_value,&arr[0],n);
            count--;
            break;
        default:
            check_push = push((input[count]-'0'),&arr[0],n);
            count--;
            break;
        }
    }
    return;
}
