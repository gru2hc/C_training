#include <stdio.h>
#include <stdlib.h>

typedef struct node_st
{
    int data;
    struct node_st* next;
} node_t;

typedef node_t* head_t;

head_t g_head = NULL;

void add_node(head_t *head, node_t* new_node)
{
    // static int test;
    node_t* temp;
    if (NULL == *head)
    {
        *head = new_node;
        printf("%d\n", (*head)->data);
        (*head)->next = NULL;
    }
    else
    {
        temp = *head;
        while(NULL != temp->next)
        {
            temp = temp->next;
        }
        temp->next=new_node;
        new_node->next=NULL;
    }
    return;
}

void free_node(head_t *head)
{
    node_t* temp;
    if (NULL == *head)
    {
        /*do nothing*/
    }
    else
    {
        while(NULL!=(*head)->next)
        {
            temp = *head;
            *head = (*head)->next;
            free(temp);
        }
        free(*head);
        *head = NULL;
    }
}

int count_list(head_t *head)
{
    int n=0;
    node_t* temp;
    if (NULL == *head)
    {
        n=0;
    }
    else
    {
        while(NULL!=(*head)->next)
        {
            temp = *head;
            *head = (*head)->next;
            free(temp);
            n++;
        }
        free(*head);
        *head = NULL;
        n++;
    }
    return n;
}

void main(void)
{
    head_t new_node;
    new_node = (head_t)malloc(sizeof(node_t));
    new_node->data = 3;
    new_node->next = NULL;
    add_node(&g_head,new_node);
    new_node = (head_t)malloc(sizeof(node_t));
    new_node->data = 5;
    new_node->next = NULL;
    add_node(&g_head,new_node);
    printf("TEST:%d\n",g_head->data);
    printf("Node 2 is:%d\n", (g_head->next)->data);
    printf("Number of nodes in list: %d\n", count_list(&g_head));
    free_node(&g_head);
}