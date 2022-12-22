#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *previous;
    int data;
    struct node *next;
} *head;

void Display()
{
    printf("\n");
    struct node *newnode;
    newnode = head;

    printf("Values:\n");
    while (newnode != NULL)
    {
        printf("%d\t", newnode->data);
        newnode = newnode->next;
    }
    printf("\n");
}

void ins_beginning(int x)
{
    printf("\nInserting %d at the beginning.", x);
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        newnode->previous = NULL;
        newnode->data = x;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->previous = NULL;
        newnode->data = x;
        newnode->next = head;
        head->previous = newnode;
        head = newnode;
    }
}
void ins_end(int x)
{
    printf("\nInserting %d at the end.", x);
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;

    if (head == NULL)
    {
        newnode->previous = NULL;
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->previous = temp;
        newnode->next = NULL;
    }
}
void ins_at_place(int x)
{
    printf("\nInserting %d at specified point.", x);
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    int i, location;

    temp = head;
    printf("\nEnter the insertion point: ");
    scanf("%d", &location);

    for (i = 0; i < location; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("\nNot enough elements in the list.");
            return;
        }
    }
    newnode->previous = temp;
    newnode->data = x;
    newnode->next = temp->next;
    temp->next = newnode;
    temp->next->previous = newnode;
}

void del_beginning()
{
    printf("\nDeleting element at the beginning.");
    struct node *newnode;

    if (head == NULL)
    {
        printf("\nAlready empty - Underflow!");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nDeletion has completed.");
    }
    else
    {
        newnode = head;
        head = head->next;
        head->previous = NULL;
        free(newnode);
        printf("\nDeletion has completed.");
    }
}
void del_end()
{
    printf("\nDeleting element at the end.");
    struct node *newnode;
    newnode = head;

    if (head == NULL)
    {
        printf("\nAlready empty - Underflow!");
    }
    else
    {
        while (newnode->next != NULL)
        {
            newnode = newnode->next;
        }
        newnode->previous->next = NULL;
        free(newnode);
        printf("\nDeletion has completed.");
    }
}
void del_at_place()
{
    printf("\nDeleting element from specific position.");
    struct node *newnode = head;
    int i, location, current;

    printf("\nEnter the deletion point: ");
    scanf("%d", &location);

    for (i = 1; i < location && current != NULL; i++)
    {
        newnode = newnode->next;
    }
    if (newnode != NULL) 
    {
        newnode->previous->next = newnode->next;
        newnode->next->previous = newnode->previous;
        free(newnode);
    }
}

void Search(int x)
{
    struct node *newnode;
    int i=0, checker;
    newnode = head;

    while (newnode != NULL) {
        if (newnode->data == x) {
            printf("\n%d was found at position %d (or) index %d.", x, (i+1), i);
            checker = 1;
            break;
        }
        else {
            checker = 0;
        }
        i++;
        newnode = newnode->next;
    }
    if (checker == 0) {
        printf("\n%d was not found.", x);
    }
}

int main()
{
    int item;

    ins_beginning(10);
    Display();

    ins_beginning(20);
    Display();

    ins_end(30);
    Display();

    ins_beginning(40);
    Display();

    ins_end(50);
    Display();

    ins_at_place(60);
    Display();

    del_beginning();
    Display();

    ins_end(70);
    Display();

    del_beginning();
    Display();

    ins_beginning(80);
    Display();

    ins_at_place(90);
    Display();

    del_end();
    Display();

    del_at_place();
    Display();

    printf("Enter the element to be searched: ");
    scanf("%d", &item);
    Search(item);

    printf("\n");
    printf("\nDevanshu Gupta 21BCE0597");
    return 0;
}