#include <stdio.h>

void swap(char* a, char* b);
void reserve_expression(char input[], int length_wtnull);
void display_arr(char input[], int length_wtnull);
void prefix(char input[], int length_wtnull);

int main(void)
{
    // char input[] = "A+B*C";
    char input[] = "A*B+C/D";

    int length_wtnull = sizeof(input) - 1;
    display_arr(&input[0],length_wtnull);
    printf("\n");
    reserve_expression(&input[0],length_wtnull);
    display_arr(&input[0],length_wtnull);
    printf("\n");
    prefix(&input[0],length_wtnull);
    display_arr(&input[0],length_wtnull);
    printf("\n");
    reserve_expression(&input[0],length_wtnull);
    display_arr(&input[0],length_wtnull);
    return 0;
}

void swap(char* a, char* b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void reserve_expression(char input[], int length_wtnull)
{
    int i=0;
    for(i=0;i<(length_wtnull/2);i++)
    {
        swap(&(input[i]),&(input[length_wtnull-1-i]));
    }
    return;
}

void prefix(char input[], int length_wtnull)
{
    int i=0;
    char array[];
    
    for(i=0;i<length_wtnull;i++)
    {
        switch(input[i]) {
            case '+':
                swap(&(input[i]),&(input[i+1]));
                i++;
                break;
            case '-':
                swap(&(input[i]),&(input[i+1]));
                i++;
                break;
            case '/':
                swap(&(input[i]),&(input[i+1]));
                i++;
                break;
            case '*':
                swap(&(input[i]),&(input[i+1]));
                i++;
                break;
            default:
                /*do nothing*/
                break;
        }
    }
    return;
}

int get_priority(char operand)
{
    int result;
    if (operand = '+' || operand = '-')
    {
        result = 1;
    }
    else if (operand = '*' || operand = '/')
    {
        result = 2;
    }
    
}

void display_arr(char input[], int length_wtnull)
{
    int i = 0;
    for(i=0;i<length_wtnull;i++)
    {
        printf("%c", input[i]);
    }

}
