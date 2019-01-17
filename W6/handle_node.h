#ifndef SRC_HANDLE_NODE_H_
#define SRC_HANDLE_NODE_H_

#include <stdint.h>

typedef struct date_st
{
uint8_t DD;
uint8_t MM;
uint16_t YY;
} date_t;

typedef struct node
{
char name[32];
date_t dob;
struct node* next;
} node_t;

typedef node_t* head_t;

void add_node(head_t *head, node_t* new_node);
int free_node(head_t *head);

#endif /* SRC_HANDLE_NODE_H_ */