#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define PERIOD 126230400

typedef struct node
{
    int data;
    struct node *next;
} node_t;

typedef node_t* head_t;

void add_node(head_t* head, node_t* new_node);
void display(head_t* head);
void delete_node(head_t* head);
int count_node(head_t* head);
void sort_node(head_t* head);

int main(void)
{
    int i;
    int counter, temp, month;
    bool leap_year = false;
    time_t seconds; 
    head_t head = NULL;
    srand(time(0));
    time(&seconds);
    seconds = 1546362000;
    counter = seconds/PERIOD;
    counter = counter*4 + 1970;
    printf("Current year is: %d\n", counter);
    temp = seconds%PERIOD;
    if (temp>94694400)
    {
        temp = temp - 94694400;
        counter = counter + 3;
    }
    else if ((63072000<temp) && (temp<94694400))
    {
        temp = temp - 63072000;
        leap_year = true;
        counter = counter + 2;
    }
    else if ((31536000<temp) && (temp<63072000))
    {
        temp = temp - 31536000;
        counter = counter + 1;
    }
    temp= temp/86400;
    if(temp<=31)
    {
        month = 1;
    }
    if(leap_year == false)
    {
        if((temp>31)&&(temp<=59))
        {
            month = 2;
        }
        if((temp>59)&&(temp<=90))
        {
            month = 3;
        }
        if((temp>90)&&(temp<=120))
        {
            month = 4;
        }
        if((temp>120)&&(temp<=151))
        {
            month = 5;
        }
        if((temp>151)&&(temp<=181))
        {
            month = 6;
        }
        if((temp>181)&&(temp<=212))
        {
            month = 7;
        }
        if((temp>212)&&(temp<=243))
        {
            month = 8;
        }
        if((temp>243)&&(temp<=273))
        {
            month = 9;
        }
        if((temp>273)&&(temp<=304))
        {
            month = 10;
        }
        if((temp>304)&&(temp<=334))
        {
            month = 11;
        }
        if((temp>334)&&(temp<=365))
        {
            month = 12;
        }
    }
        if(leap_year == false)
    {
        if((temp>31)&&(temp<=59))
        {
            month = 2;
        }
        if((temp>59)&&(temp<=90))
        {
            month = 3;
        }
        if((temp>90)&&(temp<=120))
        {
            month = 4;
        }
        if((temp>120)&&(temp<=151))
        {
            month = 5;
        }
        if((temp>151)&&(temp<=181))
        {
            month = 6;
        }
        if((temp>181)&&(temp<=212))
        {
            month = 7;
        }
        if((temp>212)&&(temp<=243))
        {
            month = 8;
        }
        if((temp>243)&&(temp<=273))
        {
            month = 9;
        }
        if((temp>273)&&(temp<=304))
        {
            month = 10;
        }
        if((temp>304)&&(temp<=334))
        {
            month = 11;
        }
        if((temp>334)&&(temp<=365))
        {
            month = 12;
        }
    }
    printf("Current year is: %d\n", counter);
    printf("Current month is: %d\n", month);
    for(i=0;i<5;i++)
    {
        node_t* node;
        node = (node_t*)malloc(sizeof(node_t));
        node->data = rand()%100;
        node->next = NULL;
        add_node(&head, node);
    }
    display(&head);
    sort_node(&head);
    printf("\nAfter sorting!\n");
    display(&head);
    // delete_node(&head);
}

void add_node(head_t* head, node_t* new_node)
{
    node_t* temp = *head;
    if (*head == NULL)
    {
        *head = new_node;
        (*head)->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        temp = new_node;
        temp->next = NULL;
    }
}

void delete_node(head_t* head)
{
    node_t* temp;
    if (*head == NULL)
    {
        /*Do nothing*/
    }
    else
    {
        while((*head)->next != NULL)
        {
            temp = *head;
            free(temp);
        }
    }
}

int count_node(head_t* head)
{
    int count=0;
    node_t* temp = *head;
    if (*head == NULL)
    {
        count = 0;
    }
    else
    {
        count++;
        while (temp->next != NULL)
        {
            temp = temp->next;
            count++;
        }
    }
    return count;
}

void sort_node(head_t* head)
{
    int a[32];
    int i,j,n, temp_array;
    node_t* temp = *head;
    n = count_node(head);

    for(i=0;i<n;i++)
    {
        a[i] = temp->data;
        temp=temp->next;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]<a[j])
            {
                temp_array = a[i];
                a[i]=a[j];
                a[j]=temp_array;
            }
        }
    }

    temp = *head;
    for(i=0;i<n;i++)
    {
        temp->data= a[i];
        temp=temp->next;
    }
    return;
}

void display(head_t* head)
{
    node_t* temp = *head;
    if(*head == NULL)
    {
        /*Do nothing*/
    }
    else
    {
        while(temp->next != NULL)
        {
            printf("%d\n", temp->data);
            temp=temp->next;
        }
        printf("%d\n", temp->data);
    }
}