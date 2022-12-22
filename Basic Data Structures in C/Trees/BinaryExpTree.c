#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};
struct node *head = NULL;

struct node *Create(char c)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = c;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->next = NULL;
    return (newnode);
}

void Inorder(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        Inorder(ptr->left);
        printf("%c ", ptr->data);
        Inorder(ptr->right);
    }
}

void Push(struct node *ptr)
{
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
}

struct node *Pop()
{
    struct node *ptr = head;
    head = head->next;
    return ptr;
}

int main()
{
    int i, j;
    char str[50];
    struct node *operand1, *operand2, *operator;

    printf("\nEnter the postfix expression:\n");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^')
        {
            operator = Create(str[i]);
            operand2 = Pop();
            operand1 = Pop();
            operator->left = operand1;
            operator->right = operand2;
            Push(operator);
        }
        else
        {
            operator = Create(str[i]);
            Push(operator);
        }
    }

    printf("\nThe Inorder Traversal of Expression Tree:\n");
    Inorder(operator);

    printf("\n");
    printf("\nDevanshu Gupta 21BCE0597");
    return 0;
}
