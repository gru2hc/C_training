#include <stdio.h>

int main(void)
{
    int n,i,j,h;
    printf("Please enter the odd number:\n");
    scanf("%d", &n);
    if(n%2==0)
    {
        printf("Invalid number. Please enter odd number!\n");
        return -1;
    }
    h = (n-1)/2;
    printf("This is output:\n");
    for(i=0;i<(n+1)/2;i++)
    {
        for(j=0;j<n;j++)
        {
            if((j<(h-i)) || (j>(h+i)))
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
    for(i=(n+1)/2;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((j<(i-h)) || (j>(n-1)-(i-h)))
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}