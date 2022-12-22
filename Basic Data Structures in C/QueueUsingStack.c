#include <stdio.h>

const int N = 6;
int Stack1[10], Stack2[10];
int top1 = -1, top2 = -1;
int count = 0;

void Display()
{
    int i;
    for (i = 0; i <= top1; i++)
    {
        printf("%d\n", Stack1[i]);
    }
}

void Push1(int x)
{
    if (top1 == N - 1)
    {
        printf("Already full.");
    }
    else
    {
        Stack1[++top1] = x;
    }
}

int Pop1()
{
    return Stack1[top1--];
}

void Push2(int x)
{
    if (top2 == N - 1)
    {
        printf("Already full.\n");
    }
    else
    {
        Stack2[++top2] = x;
    }
}

int Pop2()
{
    return Stack2[top2--];
}

void enQueue(int x)
{
    Push1(x);
    count++;
    Display();
    printf("\n");
}

void deQueue()
{
    int i, element;
    if (top1 == -1 && top2 == -1)
    {
        printf("Already empty.\n");
    }
    else
    {
        for (i = 0; i < count; i++)
        {
            element = Pop1();
            Push2(element);
        }
        printf("%d\n", Pop2());
        count--;
        for (i = 0; i < count; i++)
        {
            element = Pop2();
            Push1(element);
        }
    }
}

int main()
{
    printf("dequeueing:\n");
    deQueue();
    Display();
    printf("\n");
    printf("enqueueing 10:\n");
    enQueue(10);
    printf("\n");
    printf("enqueueing 20:\n");
    enQueue(20);
    printf("\n");
    printf("enqueueing 30:\n");
    enQueue(30);
    printf("\n");
    printf("dequeueing:\n");
    deQueue();
    Display();
    printf("\n");
    printf("dequeueing:\n");
    deQueue();
    Display();
    printf("\n");
    printf("enqueueing 40:\n");
    enQueue(40);
    printf("\n");
    printf("enqueueing 50:\n");
    enQueue(50);
    printf("\n");
    printf("dequeueing:\n");
    deQueue();
    Display();
    printf("\n");
    printf("dequeueing:\n");
    deQueue();
    Display();
    printf("\n");

    printf("\nDevanshu Gupta 21BCE0597");
    return 0;
}