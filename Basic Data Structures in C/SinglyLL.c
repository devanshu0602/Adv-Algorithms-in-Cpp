#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

int length()
{
    int count = 0;
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void display()
{
    struct node *newnode;
    newnode = head;
    while (newnode != NULL)
    {
        printf("%d ", newnode->data);
        newnode = newnode->next;
    }
}

void ins_beg(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        newnode->data = x;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->data = x;
        newnode->next = head;
        head = newnode;
    }
}

void ins_end(int x)
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}

void ins_at(int x)
{
    struct node *newnode, *temp;
    int place, i;
    newnode = (struct node *)malloc(sizeof(struct node));
    temp = head;

    printf("Enter position: ");
    scanf("%d", &place);

    if (place > length())
    {
        printf("enter valid position.\n");
        ins_at(x);
    }
    else
    {
        while (i < place - 1)
        {
            temp = temp->next;
        }
        newnode->data = x;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void del_beg()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("Already empty.\n");
    }
    else
    {
        temp = head;
        head = temp->next;
        free(temp);
    }
}

void del_end()
{
    struct node *temp, *temp2;
    temp = head;

    if (temp == NULL)
    {
        printf("Already empty.\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
    }
}

void del_at()
{
    struct node *temp, *temp2;
    int place, i = 1;
    temp = head;

    printf("Enter position: ");
    scanf("%d", &place);

    if (place > length())
    {
        printf("enter valid position.\n");
        del_at();
    }
    else
    {
        while (i < place - 1)
        {
            temp = temp->next;
            i++;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
}

void reverse() {
    struct node *prevnode, *curnode, *nextnode;
    prevnode = NULL;
    curnode = head;
    nextnode = head;
    while (nextnode != NULL) {
        nextnode = nextnode->next;
        curnode->next = prevnode;
        prevnode = curnode;
        curnode = nextnode;
    }
    head = prevnode;
}

int main()
{
    ins_beg(1);
    ins_end(2);
    ins_end(3);
    ins_at(4);
    del_at();
    reverse();
    display();

    return 0;
}