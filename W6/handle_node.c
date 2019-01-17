#include <stddef.h>
#include <stdlib.h>
#include "handle_node.h"

node_t* con_node;

void add_node(head_t *head, node_t* new_node)
{
    if(*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        con_node=*head;
        while (1)
        {
            if(con_node->next!=NULL)
            {
                con_node = con_node->next;
            }
        else
        {
            break;
        }
        }
        con_node->next = new_node;
    }
}

int free_node(head_t *head)
{
    node_t* temp;
    while((*head) != NULL)
    {
        temp = (*head);
        (*head) = (*head)->next;
        free(temp);
    }
    return 0;
}