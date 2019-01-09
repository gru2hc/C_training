#include <stdio.h>

typedef struct node
{
    int data;
    struct node* p;
} node_t;

void display_node(void);

node_t* head = NULL;
node_t* temp;

void main(void)
{
    node_t node1= {4, NULL};
    head = &node1;
    node_t node2= {5, NULL};
    temp.p = &node2;
    display_node();
    return;
}

void display_node(void)
{
    printf("Members in node: %d, %x\n", head->data, head->p);
}