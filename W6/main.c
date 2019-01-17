#include <stdio.h>
#include <stdlib.h>
#include "handle_node.h"
#include "display.h"

head_t g_head = NULL;

void main(void)
{
    int valid_number;
    valid_number = input_element(&g_head);
    if (valid_number == 0)
    {
        display_element(g_head);
    }
    free_node(&g_head);
    return;
}