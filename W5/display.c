#include <stdio.h>

void main(void)
{
    int n,i,j,h;
    printf("Please enter the number:\n");
    scanf("%d", &n);
    h = (n-1)/2;
    printf("This is output:\n");
    for(i=0;i<(n+1)/2;i++)
    {
        for(j=0;j<n;j++)
        {
            // if(i<(h+1))
            // {
                if((j<(h-i)) || (j>(h+i)))
                {
                    printf(" ");
                }
                else
                {
                    printf("*");
                }
            // }
            // else if(i>(h-1))
            // {
                // if((j<(h-(i/2))) || (j>(h+(i/2))))
                // {
                    // printf(" ");
                // }
                // else
                // {
                    // printf("*");
                // }
            // }
        }
        printf("\n");
    }
    return;
}