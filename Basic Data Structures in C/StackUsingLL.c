#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *top = 0;

void Display()
{
    struct node *temp;
    temp = top;
    if (top == 0)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
}

void Push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void Pop()
{
    struct node *temp;
    temp = top;
    if (top == 0)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Popped: %d\n", top->data);
        top = top->link;
        free(temp);
    }
}

int main()
{
    printf("Adding 2, 3, 10:\n");
    Push(2);
    Push(3);
    Push(10);
    Display();
    printf("\n");
    Pop();
    Display();

    printf("\nDevanshu Gupta 21BCE0597");
    return 0;
}