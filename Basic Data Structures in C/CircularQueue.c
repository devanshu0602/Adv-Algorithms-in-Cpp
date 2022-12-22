#include <stdio.h>

const int n = 6;
int Queue[6];
int front = -1;
int rear = -1;

void Display()
{
    int i = 0;
    for (i = front; i < rear; i = (i + 1) % n)
    {
        printf("%d ", Queue[i]);
    }
    printf("%d\n", Queue[rear]);
    printf("Front = %d\n", front);
    printf("Rear = %d\n", rear);
}

int isFull()
{
    if (front == (rear + 1) % n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQueue(int x)
{
    if (isFull())
    {
        printf("Queue is already full.\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        Queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % n;
        Queue[rear] = x;
    }
    Display();
}

void deQueue()
{
    if (isEmpty())
    {
        printf("Queue is already empty.\n");
    }
    else if (front == rear)
    {
        printf("deQueued: %d\n", Queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("deQueued: %d\n", Queue[front]);
        front = (front + 1) % n;
    }
    Display();
}

int main()
{
    printf("dequeueing:\n");
    deQueue();
    printf("\n");
    printf("enqueueing:\n");
    enQueue(10);
    enQueue(20);
    enQueue(30);
    printf("\n");
    printf("dequeueing:\n");
    deQueue();
    deQueue();
    printf("\n");
    printf("enqueueing:\n");
    enQueue(40);
    enQueue(50);
    printf("\n");
    printf("dequeueing:\n");
    deQueue();
    deQueue();
    printf("\n");
    
    printf("\nDevanshu Gupta 21BCE0597");
    return 0;
}