#include <stdio.h>

int queue[20], top = -1, front = -1, rear = -1;
int adjency_mat[20][20], visited[20], stack[20];

void add(int item)
{
    if (rear == 19)
    {
        printf("QUEUE FULL");
    }
    else
    {
        if (rear == -1)
        {
            queue[++rear] = item;
            front++;
        }
        else
        {
            queue[++rear] = item;
        }
    }
}
int delete()
{
    int k;
    if ((front > rear) || (front == -1))
    {
        return (0);
    }
    else
    {
        k = queue[front++];
        return (k);
    }
}
void BreadthFirstSearch(int source, int vertices)
{
    int p, i;
    add(source);
    visited[source] = 1;
    p = delete ();
    if (p != 0)
    {
        printf(" %d", p);
    }
    while (p != 0)
    {
        for (i = 1; i <= vertices; i++)
        {
            if ((adjency_mat[p][i] != 0) && (visited[i] == 0))
            {
                add(i);
                visited[i] = 1;
            }
        }
        p = delete ();
        if (p != 0)
        {
            printf(" %d ", p);
        }
    }
    for (i = 1; i <= vertices; i++)
    {
        if (visited[i] == 0)
        {
            BreadthFirstSearch(i, vertices);
        }
    }
}

void push(int item)
{
    if (top == 19)
    {
        printf("Stack overflow ");
    }
    else
    {
        stack[++top] = item;
    }
}
int pop()
{
    int k;
    if (top == -1)
    {
        return (0);
    }
    else
    {
        k = stack[top--];
        return (k);
    }
}
void DepthFirstSearch(int source, int vertices)
{
    int i, k;
    push(source);
    visited[source] = 1;
    k = pop();
    if (k != 0)
    {
        printf(" %d ", k);
    }
    while (k != 0)
    {
        for (i = 1; i <= vertices; i++)
        {
            if ((adjency_mat[k][i] != 0) && (visited[i] == 0))
            {
                push(i);
                visited[i] = 1;
            }
        }
        k = pop();
        if (k != 0)
        {
            printf(" %d ", k);
        }
    }
    for (i = 1; i <= vertices; i++)
    {
        if (visited[i] == 0)
        {
            DepthFirstSearch(i, vertices);
        }
    }
}

int main()
{
    int vertices, i, j, choice, source;

    printf("Number of vertices? ");
    scanf("%d", &vertices);

    printf("\nEnter 1 if edge exists, else enter 0.\n");

    for (i = 1; i <= vertices; i++)
    {
        for (j = 1; j <= vertices; j++)
        {
            printf("Between %d and %d: ", i, j);
            scanf("%d", &adjency_mat[i][j]);
        }
    }

    printf("\nAdjency matrix:\n");
    for (i = 1; i <= vertices; i++)
    {
        for (j = 1; j <= vertices; j++)
        {
            printf(" %d", adjency_mat[i][j]);
        }
        printf("\n");
    }

    for (i = 1; i <= vertices; i++)
    {
        visited[i] = 0;
    }

    printf("\nChoose an option.");
    printf("\n1. BFS \t2. DFS\n");
    scanf("%d", &choice);
    printf("\nEnter the source vertex: ");
    scanf("%d", &source);

    switch (choice)
    {
    case 1:
        BreadthFirstSearch(source, vertices);
        break;
    case 2:
        DepthFirstSearch(source, vertices);
        break;
    }

    printf("\nDevanshu Gupta 21BCE0597\n");
    return 0;
}
