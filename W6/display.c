#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "handle_node.h"

int input_element(head_t *head)
{
    int i,n;
    printf("Please input the amount of number in the list: \n");
    scanf("%d", &n);
    printf("Please input name and date of birth of employees following format: \nName DD MM YYYY\n");
    for (i=0;i<n;i++)
    {
        node_t* node = (node_t*)malloc(sizeof(node_t));
        scanf("%s", &(node->name));
        scanf("%d", &(node->dob.DD));
        if (node->dob.DD > 31)
        {
            printf("Invalid number!\n");
            return -1;
        }
        scanf("%d", &(node->dob.MM));
        if (node->dob.MM > 12)
        {
            printf("Invalid number!\n");
            return -1;
        }
        scanf("%d", &(node->dob.YY));
        node->next=NULL;
        add_node(head,node);
    }
    return 0;
}

void display_element(head_t head)
{
    printf("\nElement of each node:\n");
    node_t* temp=head;
    while (temp !=NULL)
    {
    printf("%s %d/%d/%d\n", temp->name,temp->dob.DD, temp->dob.MM, temp->dob.YY);
    temp = temp->next;
    }
    return;
}